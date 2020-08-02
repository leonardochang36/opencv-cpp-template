# OpenCV Template

A simple C++ project to serve as a starting point for an OpenCV project.
I use CMake to simplify the compilation process.

# Prerequisites

 - CMake
 - OpenCV


# How to compile

CMake reads the CMakeLists.txt we have in the project and
creates a Makefile that can be used to build the project.

We first create a directory to store build files:
```console
$ mkdir build
```

Run CMake from the build directory:

```console
$ cd build
$ cmake ..
```

Build the project:

```console
$ make
```

Run:
```console
$ ./my_project
```

You must be able to see your camera feed and a negative feed.

HAPPY CODING!!
