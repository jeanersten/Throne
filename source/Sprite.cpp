#include "Sprite.h"
#include "Log.h"

#include <glad/gl.h>

Sprite::Sprite()
  : m_vbo_id(0)
  , m_x(0.0f)
  , m_y(0.0f)
  , m_width(0.5f)
  , m_height(0.5f)
{}

Sprite::~Sprite()
{
  if (m_vbo_id != 0)
  {
    glDeleteBuffers(1, &m_vbo_id);
  }
}

void Sprite::create()
{
  GLfloat positions[12]{ };

  positions[0]  = m_x - m_width;
  positions[1]  = m_y - m_height;
  positions[2]  = m_x - m_width;
  positions[3]  = m_y + m_height;
  positions[4]  = m_x + m_width;
  positions[5]  = m_y - m_height;
 
  positions[6]  = m_x + m_width;
  positions[7]  = m_y + m_height;
  positions[8]  = m_x + m_width;
  positions[9]  = m_y - m_height;
  positions[10] = m_x - m_width;
  positions[11] = m_y + m_height;

  glGenBuffers(1, &m_vbo_id);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 12, positions, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
  //glPolygonMode(GL_FRONT, GL_LINE);
  //glPolygonMode(GL_BACK, GL_LINE);
  glDrawArrays(GL_TRIANGLES, 0, 6);
  //glPolygonMode(GL_FRONT, GL_FILL);
  //glPolygonMode(GL_BACK, GL_FILL);
  glDisableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
