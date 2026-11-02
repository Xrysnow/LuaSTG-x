package org.cocos.game;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.res.AssetFileDescriptor;
import android.database.Cursor;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.CancellationSignal;
import android.os.Handler;
import android.os.Looper;
import android.os.ParcelFileDescriptor;
import android.provider.DocumentsContract;
import android.provider.OpenableColumns;
import android.util.Log;

import org.cocos.lib.CocosEngine;
import org.cocos.lib.LuaBridge;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.SynchronousQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

/** App-owned storage and one-shot, engine-thread document/permission results. */
public final class StorageBridge {
    private static final String TAG = "StorageBridge";
    private static final String STATE_REQUEST = "lstgx.storage.request";
    private static final String STATE_CODE = "lstgx.storage.code";
    private static final Handler UI = new Handler(Looper.getMainLooper());
    // A broken provider can ignore cancellation and block a worker. Keep resource
    // use bounded and reject later work explicitly rather than queue it forever.
    private static final ThreadPoolExecutor IO = new ThreadPoolExecutor(2, 2, 30, TimeUnit.SECONDS,
            new SynchronousQueue<>());
    private static final ThreadPoolExecutor SIGNALS = new ThreadPoolExecutor(2, 2, 30, TimeUnit.SECONDS,
            new ArrayBlockingQueue<>(2));
    private static final ThreadPoolExecutor CLOSERS = new ThreadPoolExecutor(2, 2, 30, TimeUnit.SECONDS,
            new ArrayBlockingQueue<>(2));
    private static final Map<Integer, Request> REQUESTS = new LinkedHashMap<>();
    private static Context context;
    private static AppActivity activity;
    private static Request picker;
    private static int nextCode = 0x4000;
    private static boolean closed;

    private static final class Request {
        final int id;
        final int code;
        final int callback;
        final String operation;
        final CancellationSignal signal = new CancellationSignal();
        final List<Closeable> resources = new ArrayList<>();
        Thread worker;
        String source;
        String permission;
        boolean cancelled;
        boolean copying;
        boolean done;
        boolean queued;
        String status;
        String path = "";
        String uri = "";
        String message = "";

        Request(int id, int code, int callback, String operation) {
            this.id = id;
            this.code = code;
            this.callback = callback;
            this.operation = operation;
        }
    }

    private StorageBridge() {}

    static void bind(AppActivity owner, Bundle state) {
        synchronized (REQUESTS) {
            context = owner.getApplicationContext();
            activity = owner;
            closed = false;
            // A restored Activity after process death has no matching Java/Lua
            // request. Its eventual result is ignored, never assigned to a new ID.
            if (state != null && state.containsKey(STATE_REQUEST)) {
                int oldId = state.getInt(STATE_REQUEST);
                if (!REQUESTS.containsKey(oldId)) {
                    nextCode = Math.max(nextCode, state.getInt(STATE_CODE, nextCode) + 1);
                    Log.i(TAG, "discarded expired request=" + oldId);
                }
            }
            for (Request request : REQUESTS.values()) {
                request.queued = false;
                if (request.done) deliver(request);
            }
        }
    }

    static void saveState(Bundle state) {
        synchronized (REQUESTS) {
            if (picker != null) {
                state.putInt(STATE_REQUEST, picker.id);
                state.putInt(STATE_CODE, picker.code);
            }
        }
    }

    static void unbind(AppActivity owner, boolean finalClose) {
        synchronized (REQUESTS) {
            if (activity != owner) return;
            activity = null;
            for (Request request : REQUESTS.values()) request.queued = false;
            if (!finalClose) return;
            closed = true;
            for (Request request : REQUESTS.values()) {
                request.cancelled = true;
                cancelIO(request);
            }
            REQUESTS.clear();
            picker = null;
            // RenderHost now tears down the Lua VM. Do not invoke released Lua
            // objects or carry their function IDs into a later engine session.
        }
    }

    private static Context appContext() {
        synchronized (REQUESTS) {
            if (context != null) return context;
        }
        Activity owner = CocosEngine.getActivity();
        if (owner == null) throw new IllegalStateException("Activity is unavailable");
        return owner.getApplicationContext();
    }

    public static String getInternalDataPath() {
        return directory(appContext().getFilesDir());
    }

    public static String getExternalDataPath() {
        try {
            File external = appContext().getExternalFilesDir(null);
            if (external != null) return directory(external);
            Log.w(TAG, "External app storage unavailable; using internal storage");
        } catch (RuntimeException e) {
            Log.w(TAG, "External app storage unusable; using internal storage", e);
        }
        return getInternalDataPath();
    }

    private static String directory(File file) {
        if ((!file.isDirectory() && !file.mkdirs()) || !file.canWrite())
            throw new IllegalStateException("App data directory is not writable: " + file);
        return file.getAbsolutePath() + File.separator;
    }

    // IDs persist across process death; an old result cannot select a new Lua
    // callback. Request codes are never reused within the current process.
    private static Request create(String operation, int callback) {
        // These entry points are called by LuaJavaBridge on the CocosEngine
        // thread. The bridge has retained callback before entering Java. Until
        // REQUESTS accepts it, Java must release that reference on failure.
        try {
            synchronized (REQUESTS) {
                if (closed) throw new IllegalStateException("Storage session is closed");
                Context app = appContext();
                android.content.SharedPreferences prefs = app.getSharedPreferences("lstgx.storage", Context.MODE_PRIVATE);
                long next = prefs.getLong("nextRequest", 1);
                if (next <= 0 || next > Integer.MAX_VALUE) throw new IllegalStateException("Request IDs exhausted");
                if (!prefs.edit().putLong("nextRequest", next + 1).commit())
                    throw new IllegalStateException("Cannot persist request identity");
                Request request = new Request((int) next, nextCode++, callback, operation);
                REQUESTS.put(request.id, request);
                return request;
            }
        } catch (RuntimeException | Error e) {
            LuaBridge.releaseLuaFunction(callback);
            throw e;
        }
    }

    private static void post(Request request, Runnable action) {
        if (!UI.post(() -> {
            try { action.run(); }
            catch (SecurityException e) { finish(request, "denied", "", "", detail(e)); }
            catch (RuntimeException e) { finish(request, "error", "", "", detail(e)); }
        })) finish(request, "error", "", "", "Android UI queue is unavailable");
    }

    public static int importDocument(String mime, int callback) {
        Request request = create("import", callback);
        post(request, () -> launch(request, mime, null));
        return request.id;
    }

    public static int exportDocument(String source, String suggestedName, String mime, int callback) {
        Request request = create("export", callback);
        request.source = source;
        post(request, () -> launch(request, mime, suggestedName));
        return request.id;
    }

    private static void launch(Request request, String mime, String name) {
        synchronized (REQUESTS) {
            if (!live(request)) return;
            if (closed || activity == null || activity.isFinishing()) {
                finish(request, "error", "", "", "Activity is unavailable");
                return;
            }
            if (picker != null) {
                finish(request, "error", "", "", "Another system request is active");
                return;
            }
            if (request.code > 0x7fff) {
                finish(request, "error", "", "", "Activity request codes exhausted; restart the app");
                return;
            }
            try {
                boolean exporting = request.operation.equals("export");
                if (exporting) request.source = exportSource(request.source).getPath();
                Intent intent = new Intent(exporting ? Intent.ACTION_CREATE_DOCUMENT : Intent.ACTION_OPEN_DOCUMENT);
                intent.addCategory(Intent.CATEGORY_OPENABLE);
                intent.setType(mime == null || mime.isEmpty() ? "*/*" : mime);
                if (exporting) intent.putExtra(Intent.EXTRA_TITLE, safeName(name));
                intent.addFlags(exporting ? Intent.FLAG_GRANT_WRITE_URI_PERMISSION : Intent.FLAG_GRANT_READ_URI_PERMISSION);
                picker = request;
                activity.startActivityForResult(intent, request.code);
            } catch (SecurityException e) {
                if (picker == request) picker = null;
                finish(request, "denied", "", "", detail(e));
            } catch (Exception e) {
                if (picker == request) picker = null;
                finish(request, "error", "", "", detail(e));
            }
        }
    }

    static boolean onActivityResult(int code, int result, Intent data) {
        final Request request;
        final ContentResolver resolver = appContext().getContentResolver();
        synchronized (REQUESTS) {
            if (code < 0x4000 || code > 0x7fff) return false;
            request = picker;
            if (request == null || request.code != code || request.operation.equals("permission")) {
                Log.i(TAG, "ignored expired/duplicate document result code=" + code);
                return true;
            }
            picker = null;
            if (!live(request)) return true;
            if (result == Activity.RESULT_CANCELED) {
                finish(request, "cancelled", "", "", "User cancelled the document picker");
                return true;
            }
            if (result != Activity.RESULT_OK || data == null || data.getData() == null) {
                finish(request, "error", "", "", "Document picker returned no document");
                return true;
            }
            Uri uri = data.getData();
            if (!ContentResolver.SCHEME_CONTENT.equals(uri.getScheme())) {
                finish(request, "error", "", "", "Document picker must return a content URI");
                return true;
            }
            request.copying = true;
            try {
                IO.execute(() -> copyDocument(request, resolver, uri));
            } catch (RejectedExecutionException e) {
                request.copying = false;
                finish(request, "error", "", "", "Document IO workers are busy; retry after the active operations finish");
            }
        }
        return true;
    }

    private static void copyDocument(Request request, ContentResolver resolver, Uri uri) {
        File imported = null;
        boolean exportStarted = false;
        synchronized (REQUESTS) {
            if (!live(request)) return;
            request.worker = Thread.currentThread();
        }
        try {
            if (request.operation.equals("import")) {
                File imports = new File(getInternalDataPath(), "imports");
                directory(imports);
                String name = "document";
                Cursor metadata = resolver.query(uri, new String[]{OpenableColumns.DISPLAY_NAME}, null, null, null,
                        request.signal);
                try (Cursor cursor = metadata == null ? null : track(request, metadata)) {
                    if (cursor != null && cursor.moveToFirst()) name = safeName(cursor.getString(0));
                }
                imported = File.createTempFile("import-" + request.id + "-", "-" + safeName(name), imports);
                try (AssetFileDescriptor descriptor = track(request, resolver.openAssetFileDescriptor(uri, "r", request.signal));
                     InputStream input = track(request, descriptor.createInputStream());
                     FileOutputStream output = track(request, new FileOutputStream(imported))) {
                    transfer(request, input, output);
                    output.getFD().sync();
                }
                synchronized (REQUESTS) {
                    if (!live(request)) throw new IOException("Request cancelled");
                    finish(request, "success", imported.getCanonicalPath(), "", "");
                    imported = null;
                }
            } else {
                File source = exportSource(request.source);
                try (InputStream input = track(request, new FileInputStream(source));
                     ParcelFileDescriptor descriptor = track(request, resolver.openFileDescriptor(uri, "wt", request.signal));
                     OutputStream output = track(request, new ParcelFileDescriptor.AutoCloseOutputStream(descriptor))) {
                    exportStarted = true;
                    transfer(request, input, output);
                    output.flush();
                }
                synchronized (REQUESTS) {
                    if (!live(request)) throw new IOException("Request cancelled");
                    finish(request, "success", "", uri.toString(), "");
                    exportStarted = false;
                }
            }
        } catch (SecurityException e) {
            finish(request, "denied", "", "", detail(e));
        } catch (Exception e) {
            finish(request, "error", "", "", detail(e));
        } finally {
            synchronized (REQUESTS) {
                request.worker = null;
                request.resources.clear();
            }
            if (imported != null && !imported.delete()) Log.w(TAG, "Cannot remove incomplete import: " + imported);
            if (exportStarted) {
                // ACTION_CREATE_DOCUMENT owns a new document; never delete a
                // pre-existing source or a user-selected existing document.
                try { DocumentsContract.deleteDocument(resolver, uri); }
                catch (Exception e) { Log.w(TAG, "Incomplete export may remain at " + uri, e); }
            }
        }
    }

    private static void transfer(Request request, InputStream input, OutputStream output) throws IOException {
        byte[] buffer = new byte[64 * 1024];
        for (;;) {
            synchronized (REQUESTS) {
                if (!live(request)) throw new IOException("Request cancelled");
            }
            int count = input.read(buffer);
            synchronized (REQUESTS) {
                if (!live(request)) throw new IOException("Request cancelled");
            }
            if (count < 0) return;
            if (count > 0) output.write(buffer, 0, count);
        }
    }

    private static <T extends Closeable> T track(Request request, T resource) throws IOException {
        if (resource == null) throw new IOException("Provider returned no descriptor or stream");
        synchronized (REQUESTS) {
            if (live(request)) {
                request.resources.add(resource);
                return resource;
            }
        }
        // Called only by an IO worker. Never close provider handles on UI/Lua.
        resource.close();
        throw new IOException("Request cancelled");
    }

    private static void cancelIO(Request request) {
        if (request.worker != null) request.worker.interrupt();
        final List<Closeable> resources = new ArrayList<>(request.resources);
        // Binder cancellation and descriptor close are independent: even if a
        // broken provider blocks its cancel transaction, closing its pipe can
        // still wake our reader. Both pools have finite workers and queues.
        try {
            SIGNALS.execute(() -> {
                try { request.signal.cancel(); }
                catch (RuntimeException e) { Log.w(TAG, "Provider cancellation failed request=" + request.id, e); }
            });
        } catch (RejectedExecutionException e) {
            Log.w(TAG, "Provider cancellation workers busy request=" + request.id);
        }
        if (!resources.isEmpty()) {
            try {
                CLOSERS.execute(() -> {
                    // Close streams/descriptors before a provider-backed cursor,
                    // whose remote close method could itself be unresponsive.
                    for (int index = resources.size() - 1; index >= 0; index--) {
                        Closeable resource = resources.get(index);
                        try { resource.close(); }
                        catch (IOException | RuntimeException e) { Log.w(TAG, "Closing cancelled IO request=" + request.id, e); }
                    }
                });
            } catch (RejectedExecutionException e) {
                Log.w(TAG, "Provider close workers busy; IO worker retains cleanup request=" + request.id);
            }
        }
    }

    private static File exportSource(String value) throws IOException {
        if (value == null || value.isEmpty()) throw new IOException("Export source is empty");
        File source = new File(value).getCanonicalFile();
        File internal = appContext().getFilesDir().getCanonicalFile();
        boolean allowed = inside(source, internal);
        if (!allowed) {
            File external = appContext().getExternalFilesDir(null);
            allowed = external != null && inside(source, external.getCanonicalFile());
        }
        if (!allowed || !source.isFile() || !source.canRead())
            throw new IOException("Export source must be a readable file in app-specific storage");
        return source;
    }

    private static boolean inside(File file, File root) {
        return file.getPath().startsWith(root.getPath() + File.separator);
    }

    private static String safeName(String name) {
        if (name == null || name.isEmpty()) return "document";
        String safe = name.replaceAll("[\\\\/\\p{Cntrl}]", "_");
        return safe.substring(0, Math.min(safe.length(), 100));
    }

    public static boolean cancelRequest(int id) {
        final Request request;
        synchronized (REQUESTS) {
            request = REQUESTS.get(id);
            if (!live(request)) return false;
            request.cancelled = true;
            cancelIO(request);
            // Keep a cancelled picker as a tombstone until its result returns;
            // do not let a later selection satisfy a different request.
            finish(request, "cancelled", "", "", "Request cancelled by caller");
            return true;
        }
    }

    public static boolean hasPermission(String permission) {
        if (permission == null || permission.isEmpty()) return false;
        return appContext().checkPermission(permission, android.os.Process.myPid(), android.os.Process.myUid())
                == PackageManager.PERMISSION_GRANTED;
    }

    public static int requestPermission(String permission, int callback) {
        Request request = create("permission", callback);
        request.permission = permission;
        post(request, () -> {
            synchronized (REQUESTS) {
                if (!live(request)) return;
                if (hasPermission(permission)) {
                    finish(request, "success", "", "", "Permission is granted");
                } else if (activity == null || activity.isFinishing() || closed) {
                    finish(request, "error", "", "", "Activity is unavailable");
                } else if (permission == null || permission.isEmpty()
                        || permission.equals("android.permission.MANAGE_EXTERNAL_STORAGE")) {
                    finish(request, "error", "", "", "Invalid or special permission; no runtime request was submitted");
                } else if (Build.VERSION.SDK_INT < 23) {
                    finish(request, "denied", "", "", "Permission is not granted");
                } else if (picker != null || request.code > 0x7fff) {
                    finish(request, "error", "", "", "Another request is active or request codes exhausted");
                } else {
                    try {
                        picker = request;
                        activity.requestPermissions(new String[]{permission}, request.code);
                    } catch (Exception e) {
                        if (picker == request) picker = null;
                        finish(request, "error", "", "", detail(e));
                    }
                }
            }
        });
        return request.id;
    }

    static boolean onRequestPermissionsResult(int code, String[] permissions, int[] grants) {
        synchronized (REQUESTS) {
            if (code < 0x4000 || code > 0x7fff) return false;
            Request request = picker;
            if (request == null || request.code != code || !request.operation.equals("permission")) return true;
            picker = null;
            if (!live(request)) return true;
            boolean granted = grants.length > 0 && grants[0] == PackageManager.PERMISSION_GRANTED
                    && hasPermission(request.permission);
            finish(request, granted ? "success" : "denied", "", "", granted ? "Permission is granted" : "Permission was denied");
            return true;
        }
    }

    private static boolean live(Request request) {
        return request != null && REQUESTS.get(request.id) == request && !request.done && !request.cancelled && !closed;
    }

    private static void finish(Request request, String status, String path, String uri, String message) {
        synchronized (REQUESTS) {
            if (request.done || REQUESTS.get(request.id) != request || closed) return;
            request.done = true;
            request.status = status;
            request.path = path;
            request.uri = uri;
            request.message = message;
            Log.i(TAG, "request=" + request.id + " operation=" + request.operation + " status=" + status);
            deliver(request);
        }
    }

    private static void deliver(Request request) {
        if (request.queued || activity == null || closed) return;
        final AppActivity owner = activity;
        request.queued = true;
        CocosEngine.runOnGLThread(() -> {
            final String result;
            synchronized (REQUESTS) {
                if (REQUESTS.get(request.id) != request || closed) return;
                if (activity != owner) { request.queued = false; return; }
                REQUESTS.remove(request.id);
                result = json(request);
            }
            try { LuaBridge.callLuaFunctionWithString(request.callback, result); }
            finally { LuaBridge.releaseLuaFunction(request.callback); }
        });
    }

    private static String json(Request request) {
        try {
            return new JSONObject().put("requestId", request.id).put("status", request.status)
                    .put("path", request.path).put("uri", request.uri).put("message", request.message).toString();
        } catch (JSONException e) { throw new IllegalStateException(e); }
    }

    private static String detail(Exception e) {
        return e.getClass().getSimpleName() + ": " + (e.getMessage() == null ? "Operation failed" : e.getMessage());
    }
}
