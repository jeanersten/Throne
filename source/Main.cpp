#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "Welcome to Throne Engine!\n";

  if (SDL_Init(SDL_INIT_VIDEO))
  {
    std::cout << "SDL initialized successfully!\n";
  }

  return 0;
}
