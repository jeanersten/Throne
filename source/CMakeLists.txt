add_executable(Throne
  Main.cpp
)

target_link_libraries(Throne PRIVATE
  glfw
  glad
)

target_compile_definitions(Throne PRIVATE
  $<$<CONFIG:Debug>:CROWN_DEBUG_BUILD>
  $<$<CONFIG:Debug>:CROWN_RELEASE_BUILD>
)
