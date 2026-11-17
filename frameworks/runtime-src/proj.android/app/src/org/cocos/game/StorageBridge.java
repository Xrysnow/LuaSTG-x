package org.cocos.game;

import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import org.cocos.lib.CocosEngine;
import org.cocos.lib.LuaBridge;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.File;
import java.io.IOException;
import java.util.LinkedHashMap;
import java.util.Map;

/** App-owned storage paths and engine-thread permission results. */
public final class StorageBridge {
    private static final String TAG = "StorageBridge";
    private static final String STATE_REQUEST = "lstgx.storage.request";
    private static final String STATE_CODE = "lstgx.storage.code";
    private static final Handler UI = new Handler(Looper.getMainLooper());
    private static final Map<Integer, Request> REQUESTS = new LinkedHashMap<>();
    private static Context context;
    private static AppActivity activity;
    private static Request permissionRequest;
    private static int nextCode = 0x4000;
    private static boolean closed;

    private static final class Request {
        final int id;
        final int code;
        final int callback;
        String permission;
        boolean cancelled;
        boolean done;
        boolean queued;
        String status;
        String path = "";
        String uri = "";
        String message = "";

        Request(int id, int code, int callback) {
            this.id = id;
            this.code = code;
            this.callback = callback;
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
            if (permissionRequest != null) {
                state.putInt(STATE_REQUEST, permissionRequest.id);
                state.putInt(STATE_CODE, permissionRequest.code);
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
            REQUESTS.clear();
            permissionRequest = null;
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

    /** Preserve the app-owned source rule of LuaSTG's legacy Android export API. */
    public static String canonicalAppOwnedDocumentSource(String path) {
        if (path == null || path.isEmpty()) return "";
        try {
            File source = new File(path);
            if (!source.isAbsolute()) return "";
            source = source.getCanonicalFile();
            Context app = appContext();
            if (isInside(source, app.getFilesDir()) || isInside(source, app.getExternalFilesDir(null)))
                return source.getPath();
        } catch (IOException | RuntimeException e) {
            Log.w(TAG, "Cannot resolve an app-owned export source", e);
        }
        return "";
    }

    private static boolean isInside(File source, File directory) throws IOException {
        return directory != null && source.getPath().startsWith(directory.getCanonicalPath() + File.separator);
    }

    // IDs persist across process death; an old result cannot select a new Lua
    // callback. Request codes are never reused within the current process.
    private static Request create(int callback) {
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
                Request request = new Request((int) next, nextCode++, callback);
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

    public static boolean cancelRequest(int id) {
        final Request request;
        synchronized (REQUESTS) {
            request = REQUESTS.get(id);
            if (!live(request)) return false;
            request.cancelled = true;
            // Keep the permission request slot until Android delivers its result.
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
        Request request = create(callback);
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
                } else if (permissionRequest != null || request.code > 0x7fff) {
                    finish(request, "error", "", "", "Another request is active or request codes exhausted");
                } else {
                    try {
                        permissionRequest = request;
                        activity.requestPermissions(new String[]{permission}, request.code);
                    } catch (Exception e) {
                        if (permissionRequest == request) permissionRequest = null;
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
            Request request = permissionRequest;
            if (request == null || request.code != code) return true;
            permissionRequest = null;
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
            Log.i(TAG, "request=" + request.id + " status=" + status);
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
