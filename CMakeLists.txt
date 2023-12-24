# Infomation
cmake_minimum_required(VERSION 3.5)
project(FluidisedBed LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Glob files
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)
# Get imgui path
set(IMGUI_PATH depend/imgui)
# Get implot path
set(IMPLOT_PATH depend/implot)
# Get vectorMath path
set(VM_PATH depend/VectorMath/include)
# Get SDL2 from package manager
find_package(SDL2 REQUIRED)
# Glob imgui
file(GLOB IMGUI_GLOB
    ${IMGUI_PATH}/*.cpp
    ${IMGUI_PATH}/*.h
    # Specific bindings
    ${IMGUI_PATH}/backends/imgui_impl_sdl2.cpp
	${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
)
# Glob implot
file(GLOB IMPLOT_PATH
    ${IMPLOT_PATH}/*.cpp
    ${IMPLOT_PATH}/*.h
)
# Imgui include
INCLUDE_DIRECTORIES(
    ${IMGUI_PATH}
	${SDL2_INCLUDE_DIRS}
)
# BUILD imgui
add_library(imgui STATIC ${IMGUI_GLOB})
target_link_libraries(imgui SDL2)
target_include_directories(imgui PUBLIC SDL2 SDL2main)
# BUILD implot
add_library(implot STATIC ${IMPLOT_PATH})
# BUILD FluidisedBed Lib
add_library(FluidisedBed SHARED
${SOURCE_FILES}
${HEADER_FILES}
)
target_include_directories(FluidisedBed PRIVATE imgui ${SDL2_INCLUDE_DIRS} ${VM_PATH})
# BUILD Main Simulator Executable
add_executable(Simulator src/main.cpp)
target_include_directories(Simulator PRIVATE ${SDL2_INCLUDE_DIRS} ${VM_PATH})
target_link_libraries(Simulator PUBLIC SDL2 FluidisedBed imgui OpenGL implot)
