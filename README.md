# Virtual ecosystem

App for simulating a simple environment.

# Prerequisites

CMake version 3.12 (or higher) and a C++ build system (MSVC, GCC, MinGW, Ninja, etc.)
which supports C++20. CMake should be configured to use this build system.

# Building

Create a directory `build`, navigate to it, and execute `cmake ..`.
This should create the project files for the default build system
specified in CMake settings.

Then you can run `cmake --build .` to build the project.

# How to write a map file

A map file is a text file that represents the initial state of a simulation.
It consists of rows and columns of characters, where each character corresponds to an organism or an empty space.

To write a valid map file, you need to follow these rules:

Lines should contain rows of characters separated by spaces.
Each character represents an organism on the map.
There are only three species: `@` for bacteria, `#` for fungus and `*` for alga.
Use `_` to represent an empty space.

Here is an example of a valid map file:
```
@ _ _ # _ _ *
* _ * _ * _ _
_ # _ @ _ # _
# * # _ * * _
@ _ @ # @ # _
# @ _ # * _ _
@ # _ @ * _ #
```
This map file represents a 7x7 grid with bacteria, fungus and alga distributed randomly.
