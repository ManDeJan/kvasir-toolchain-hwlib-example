# Kvasir toolchain example with hwlib
Demonstrates how to easily set up a build environment for the arduino due.

## How to get started

Clone this repo to your device.
Set the location of the toolchain and hwlib in CMakeLists.txt.
Then to build a cmake project make a build folder in the same directory as your CMakeLists.txt file, for example:

```bash
# make a build folder
mkdir build
cd build
# generate cmake files
cmake ..
```
Then if you want to build your project from the build folder type
`make`
or if you want to flash it to the due type `make flash`.

## Adding new sources to your project

if you have a new source file in your project you want to make sure you add it in yur CMakeLists.txt in the `set(sources)` list.

<sub><sup>**Note:** You only have to do this for actual source files (files ending in `.cpp`) not for header files (`.hpp`)</sup></sub>
