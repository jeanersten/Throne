cmake_minimum_required(VERSION 3.10)

project(Throne LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Throne
  "source/Main.cpp"
)
