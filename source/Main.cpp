#include "Game.h"
#include "Log.h"

#include <SDL3/SDL_main.h>

#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "Welcome to Throne Engine!\n";

  Log::setup(LOG_LEVEL_TRACE);

  Game main_game{ }; 
  main_game.run();

  return 0;
}
