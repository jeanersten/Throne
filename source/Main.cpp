#include "Game.h"

#include <SDL3/SDL_main.h>

#include <spdlog/spdlog.h>

#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "Welcome to Throne Engine!\n";

  spdlog::error("TEST");

  Game main_game{ }; 
  main_game.run();

  return 0;
}
