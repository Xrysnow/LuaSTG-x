The app/manual-assets directory is the explicit source for handwritten Android
assets. Create that directory when adding handwritten files.

Generated src/ and res/ come from the engine source tree and are synchronized to
build/generated/lstgxAssets/<variant>. Do not put generated copies here.
Conflicting handwritten/generated paths fail the build and list their paths.

The old app/assets directory is preserved locally and is no longer packaged.
Before adding a legacy handwritten asset here, compare it with its source and
keep the original. The B0 inventory found all 563 legacy files identical to the
source tree, so no handwritten files needed migration.
