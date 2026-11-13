#!/usr/bin/env python3
"""Regenerate application icons from res/icon.png (requires Pillow)."""
import argparse
import json
from pathlib import Path
import shutil

from PIL import Image


def main():
    root = Path(__file__).resolve().parents[1]
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, default=root / 'res/icon.png',
                        help='Square PNG; also copied to res/icon.png for the Linux window icon')
    args = parser.parse_args()
    source = args.source.resolve()
    with Image.open(source) as original:
        if original.width != original.height:
            parser.error('The source icon must be square')
        image = original.convert('RGBA')
    master = root / 'res/icon.png'
    if source != master:
        shutil.copyfile(source, master)
    runtime = root / 'frameworks/runtime-src'
    generated = [master]

    def png(path, size, opaque=False):
        value = image.resize((size, size), Image.Resampling.LANCZOS)
        if opaque:
            background = Image.new('RGBA', value.size, 'white')
            value = Image.alpha_composite(background, value).convert('RGB')
        path.parent.mkdir(parents=True, exist_ok=True)
        value.save(path, format='PNG')
        generated.append(path)

    windows = runtime / 'proj.win32/res/game.ico'
    image.save(windows, format='ICO', sizes=[(n, n) for n in (16, 24, 32, 48, 64, 128, 256)])
    generated.append(windows)
    mac = runtime / 'proj.ios_mac/mac/Icon.icns'
    image.resize((1024, 1024), Image.Resampling.LANCZOS).save(mac, format='ICNS')
    generated.append(mac)
    for density, size in [('mdpi', 48), ('hdpi', 72), ('xhdpi', 96), ('xxhdpi', 144), ('xxxhdpi', 192)]:
        png(runtime / ('proj.android/app/res/mipmap-' + density + '/ic_launcher.png'), size)
    catalog = runtime / 'proj.ios_mac/ios/Images.xcassets/AppIcon.appiconset'
    contents = json.loads((catalog / 'Contents.json').read_text(encoding='utf-8'))
    sizes = {}
    for item in contents['images']:
        if item['idiom'] == 'ios-marketing':
            item['filename'] = 'Icon-1024.png'
        size = round(float(item['size'].split('x')[0]) * float(item['scale'][:-1]))
        name = item['filename']
        if name in sizes and sizes[name] != size:
            raise ValueError('Conflicting icon dimensions: ' + name)
        sizes[name] = size
    for name, size in sizes.items():
        png(catalog / name, size, opaque=True)
    # Preserve the catalog's established indentation and CRLF line endings.
    text = (catalog / 'Contents.json').read_text(encoding='utf-8')
    if '"filename" : "Icon-1024.png"' not in text:
        text = text.replace('"idiom" : "ios-marketing",',
                            '"idiom" : "ios-marketing",\n      "filename" : "Icon-1024.png",')
        with (catalog / 'Contents.json').open('w', encoding='utf-8', newline='\r\n') as stream:
            stream.write(text)
    print(json.dumps({'source': str(master), 'generated': [str(p.relative_to(root)) for p in generated]}, indent=2))


if __name__ == '__main__':
    main()
