#include "Game.h"
#include "Log.h"

#include <SDL3/SDL_main.h>

#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "Welcome to Throne Engine!\n";

  Log::setup(LOG_LEVEL_TRACE);

  MSG_TRACE("TRACE: {}", 1);
  MSG_DEBUG("DEBUG: {}", 2);
  MSG_INFO("INFO: {}", 3);
  MSG_WARN("TRACE: {}", 4);
  MSG_ERROR("ERROR: {}", 5);
  MSG_CRITICAL("CRITICAL: {}", 6);

  Game main_game{ }; 
  main_game.run();

  return 0;
}
