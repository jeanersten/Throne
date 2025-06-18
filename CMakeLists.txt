cmake_minimum_required(VERSION 3.10)

project(Throne LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(vendor/GLAD EXCLUDE_FROM_ALL)
add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)
add_subdirectory(vendor/spdlog EXCLUDE_FROM_ALL)

add_executable(Throne
  "source/Game.cpp"
  "source/Log.cpp"
  "source/Main.cpp"
  "source/Sprite.cpp"

  "source/Log.h"
  "source/Game.h"
  "source/Sprite.h"
)

target_link_libraries(Throne PRIVATE glad SDL3::SDL3 spdlog::spdlog)

add_custom_command(
  TARGET Throne POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:Throne>
  VERBATIM
)
