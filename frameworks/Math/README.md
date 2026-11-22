# lstgx_Math

Math and geometry support of [LuaSTG-x](https://github.com/Xrysnow/LuaSTG-x).

## Dependency

* `Vec2` class in [cocos2d-x/math](https://github.com/cocos2d/cocos2d-x/tree/v3/cocos/math)

## Features

* 2D collision check of following geometry:
  * Circle
  * Oriented Bounding Box
  * Ellipse
  * Diamond
  * Triangle
  * Point
* Spline interpolation of following methods:
  * [Cardinal](https://en.wikipedia.org/wiki/Cubic_Hermite_spline#Cardinal_spline)
  * [Catmull-Rom](https://en.wikipedia.org/wiki/Cubic_Hermite_spline#Catmull%E2%80%93Rom_spline)
  * [Centripetal Catmull-Rom](https://en.wikipedia.org/wiki/Centripetal_Catmull%E2%80%93Rom_spline)
* Solution of quadratic, cubic and quartic equation.
* Fast fourier transformation based on [meow_fft](https://github.com/JodiTheTigger/meow_fft).
* Window functions for FFT.
* Random algorithm from [Python](https://docs.python.org/3.5/library/random.html).
