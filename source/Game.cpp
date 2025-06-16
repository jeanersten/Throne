#include "Game.h"

#include <glad/gl.h>

#include <SDL3/SDL.h>

#include <iostream>

Game::Game()
 : m_window(nullptr)
 , m_screen_width(640)
 , m_screen_height(480)
 , m_state(GameState::PLAY)
{
  init();
}

Game::~Game()
{
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void Game::init()
{
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    std::cerr << "Failed to initialize SDL!\n";
  }

  m_window = SDL_CreateWindow("Throne Engine", m_screen_width, m_screen_height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if (!m_window)
  {
    std::cerr << "Failed to create SDL window!\n";
  }

  SDL_GLContext opengl_context = SDL_GL_CreateContext(m_window);

  if (!opengl_context)
  {
    std::cerr << "Failed to create SDL OpenGL context!\n";
  }

  if (!gladLoadGL(SDL_GL_GetProcAddress))
  {
    std::cerr << "Failed to retrieved OpenGL functions via GLAD!\n";
  }
}

void Game::update()
{
  while (m_state != GameState::EXIT)
  {
    handleEvents();
  }
}

void Game::handleEvents()
{
  SDL_Event event{ };

  while (SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_EVENT_QUIT:
        m_state = GameState::EXIT;
      break;
    }
  }
}

void Game::run()
{
  update();
}
