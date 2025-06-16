cmake_minimum_required(VERSION 3.10)

project(Throne LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)

add_executable(Throne
  "source/Game.cpp"
  "source/Main.cpp"

  "source/Game.h"
)

target_link_libraries(Throne PRIVATE SDL3::SDL3)

add_custom_command(
  TARGET Throne POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:Throne>
  VERBATIM
)
