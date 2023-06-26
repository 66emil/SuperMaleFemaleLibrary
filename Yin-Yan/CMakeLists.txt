cmake_minimum_required(VERSION 3.25)
project(Yin_Yan)

set(CMAKE_CXX_STANDARD 20)
set(SFML_DIR "/usr/local/Cellar/sfml/lib/cmake/SFML")

include_directories(/usr/local/Cellar/sfml/include)
include_directories(${SFML_INCLUDE_DIR})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Yin_Yan main.cpp Circle/Circle.cpp Grid/Grid.cpp Level/Level.cpp)

target_link_libraries(Yin_Yan sfml-graphics sfml-window sfml-system)
