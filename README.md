# Simple3DGameEngine

This repository contains the C++ implementation of 3D game engine from [ThinMatrix](https://www.youtube.com/@ThinMatrix) OpenGL [tutorial](https://www.youtube.com/watch?v=VS8wlS9hF8E&list=PLRIWtICgwaX0u7Rf9zkZhLoLuZVfUksDP).

Libraries required to run this code are [OpenGL](https://www.opengl.org/), [GLFW](https://www.glfw.org/), [GLEW](https://glew.sourceforge.net/) and [stb](https://github.com/nothings/stb).
Where stb is used for loading images. Depending on the instalation CMakeLists.txt may need other configuration (I've used find_package for most libraries and standard yay installation path for stb).

## Some info I guess

To build run

```shell
cmake .
make
```

To run code you can do

```shell
make run
```

or just run the build file with

```shell
./build/3DEngine
```

To remove all the buiild files you can run

```shell
make clean-all
```
