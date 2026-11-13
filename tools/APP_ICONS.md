# Application icons

`res/icon.png` is the shared source icon and the Linux window icon. Regenerate
Windows ICO, macOS ICNS, Android launcher PNGs and iOS AppIcon PNGs with:

```sh
python3 tools/generate_app_icons.py
```

The script requires Pillow. To replace the source and regenerate all icons:

```sh
python3 tools/generate_app_icons.py --source /path/to/icon.png
```

Images are resized with Lanczos filtering. Windows, macOS, Android and Linux
preserve transparency; iOS icons use an opaque white background. The iOS
marketing icon and macOS 1024-pixel representation are upscaled when the source
is smaller than 1024 pixels.
