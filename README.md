# MyLearnOpenGL

This repo is tested on MacOS X and there maybe problems on other OS platform such as Linux.

## Prepare GLFW & GLEW
**GLFW:**
* Download the source files from official website: [GLFW](https://www.glfw.org/download.html)
* Compile and install with following steps:
```shell
# compile
cd /path/to/your/glfw-x.x.x
mkdir build
cd build; cmake ..
make

# install
make install

# the header files & libraries are installed to following path(on Max OS X)
/usr/local/include/GLFW
/usr/local/lib
```

**GLEW:** can be installed by Homebrew
```shell
brew install glew

# the header files & libraries are installed to following path(on Max OS X)
/usr/local/Cellar/glew/2.1.0_1/include
/usr/local/Cellar/glew/2.1.0_1/lib
```

## Compile
```shell
mkdir build
cd build
cmake ..
make
```

## Run
```shell
# You MUST cd to the directory where the executable file locates, e.g.
cd /path/to/this/repo/build
./Transform2D
```