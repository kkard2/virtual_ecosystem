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

# Description

A virtual ecosystem is a simple bio-cybernetic simulator of an ecosystem with three species of virtual organisms:
algae *, fungi # and bacteria @. The ecosystem environment is a rectangular board of cells, called niches.
Each niche can be empty, occupied by a living or dead organism. Each niche has its direct neighborhood.
Living organisms only interact with their neighborhood. The ecosystem develops in simulation steps.

Each organism ages and dies when it exceeds its maximum age (in simulation steps). Each species has its own age range.
If an organism is not dead, it tries to eat. Fungi absorb dead organisms in their neighborhood.
Bacteria hunt algae or other bacteria in their neighborhood. Algae get food by photosynthesis.

If an organism is not hungry, it tries to reproduce. It places its offspring in a free cell in its neighborhood.
Reproduction costs food for the parent. The offspring is young and hungry.

If a fungus or bacterium does not eat or reproduce, it changes cell if there is a free one in its neighborhood.
