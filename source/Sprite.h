#pragma once

#include <glad/gl.h>

class Sprite
{
private:
  GLuint m_vbo_id;

  GLfloat m_x;
  GLfloat m_y;
  GLfloat m_width;
  GLfloat m_height;

public:
  Sprite();
  ~Sprite();

  void create();
  void draw();
};
