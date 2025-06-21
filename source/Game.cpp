#include "Game.h"
#include "Log.h"

#include <glad/gl.h>

#include <SDL3/SDL.h>

#include <iostream>

Game::Game()
  : m_window(nullptr)
  , m_screen_width(640)
  , m_screen_height(480)
  , m_state(GameState::PLAY)
  , m_sprite()
  , m_shader()
{
  init();
}

Game::~Game()
{}

void Game::init()
{
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    MSG_ERROR("Failed to initialize SDL!");
  }

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  m_window = SDL_CreateWindow("Throne Engine", m_screen_width, m_screen_height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if (!m_window)
  {
    MSG_ERROR("Failed to create SDL window!");
  }

  SDL_GLContext opengl_context = SDL_GL_CreateContext(m_window);

  if (!opengl_context)
  {
    MSG_ERROR("Failed to create SDL OpenGL context!");
  }

  if (!gladLoadGL(SDL_GL_GetProcAddress))
  {
    MSG_ERROR("Failed to retrieved OpenGL function via GLAD!\n");
  }

  SDL_GL_SetSwapInterval(1);

  glClearColor(0.3f, 0.5f, 0.4f, 1.0f);
  glClearDepth(1.0);

  m_shader.compileShaders("C:\\Dev\\Throne\\resource\\VertexSample.vert", "C:\\Dev\\Throne\\resource\\FragmentSample.frag");
  m_shader.linkShaders();

  m_sprite.create();
}

void Game::update()
{
  while (m_state != GameState::EXIT)
  {
    handleEvents();
    handleRendering();
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
      {
        m_state = GameState::EXIT;
      }
      break;

      case SDL_EVENT_WINDOW_RESIZED:
      {
        SDL_GetWindowSize(m_window, &m_screen_width, &m_screen_height);

        glViewport(0, 0, m_screen_width, m_screen_height);
      }
      break;
    }
  }
}

void Game::handleRendering()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  m_shader.use();
  m_sprite.draw();
  m_shader.unuse();

  SDL_GL_SwapWindow(m_window);
}

void Game::run()
{
  update();
}
