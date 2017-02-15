cmake_minimum_required (VERSION 2.8.11)
project (example CXX)


# Set the location of kvasir and hwlib on your PC
# You can download or clone the latest versions of these at
# https://github.com/wovo/hwlib
# https://github.com/kvasir-io/toolchain
set(hwlib <your-path-to-hwlib>/hwlib)
set(toolchain <your-path-to-the-toolchain>/kvasir_toolchain)

include_directories(
	${kvasir}/Lib
)

include_directories(
	${hwlib}/include
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -specs=nano.specs")

# Add new source files here
set(sources
    ${hwlib}/include/hwlib.cpp
    main.cpp
)

set(warnings
    "-Wall"
    "-Wextra"
    "-Wfatal-errors"
    "-Wpedantic"
    "-Wcast-align"
    "-Wmissing-declarations"
    "-Wredundant-decls"
    "-Wuninitialized"
    "-Wconversion"
    "-Wno-unused-parameter")

set(cxxflags
    "-std=c++14"
    "-Og"
    "-g3"
    ${warnings})

string(REGEX REPLACE ";" " " cxxflags "${cxxflags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${cxxflags}")

# The compiler that is used:
include(${toolchain}/compilers/arm-none-eabi.cmake)

# The target chip that is compiled for:
include(${toolchain}/targets/arm32/cm3/atmel/sam3x/sam3x8e/sam3x8e.cmake)

# The flashscript used to flash the script:
include(${toolchain}/targets/arm32/cm3/atmel/sam3x/sam3x8e/flashscripts/arduino_due.cmake)
