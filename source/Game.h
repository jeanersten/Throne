#pragma once

#include <SDL3/SDL.h>

enum class GameState
{
  PLAY,
  EXIT
};

class Game
{
private:
  SDL_Window* m_window;

  int m_screen_width;
  int m_screen_height;

  GameState m_state;

  void init();
  void update();

  void handleEvents();
  void handleRendering();

public:
  Game();
  ~Game();

  void run();
};
