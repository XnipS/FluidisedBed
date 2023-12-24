# Fluidised Bed

![Banner](https://repository-images.githubusercontent.com/663372365/f817217c-a226-4045-9a23-b35badf2d423)
Built by _XnipS_.

# Goals

Original goal to simulate a 2D fluidised bed with configurable chamber settings, alterable enthalpy and confiugurable fluid and bed. Currently simulates particles with elastic collisions (can be dampened to simulate losses) as well as simple gravity.

# Screenshot
![FB_V6](https://github.com/XnipS/FluidisedBed/assets/23164022/3e27d613-bf31-475b-935c-590acd41f403)

# Compiling

## Windows

- Clone with submodules `git clone --recurse-submodules https://github.com/XnipS/FluidisedBed.git`
- Download [SDL2](https://github.com/libsdl-org/SDL/releases/latest) `SDL2-devel-2.28.1-VC.zip` version and extract contents to FluidisedBed/vclib/SDL2
- May need to copy and paste relevant .dll from FluidisedBed/vclib/SDL2/lib to your build output folder.

## Linux

- Requires SDL2 from relevant package manager
