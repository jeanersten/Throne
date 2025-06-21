#pragma once

#include <glad/gl.h>

#include <string>

class Shader
{
private:
  GLuint m_program_id;
  GLuint m_vertex_shader_id;
  GLuint m_fragment_shader_id;
  GLint m_attribute_index;

  void compileShader(const std::string& shader_path, GLuint shader_id);

public:
  Shader();
  ~Shader();

  void compileShaders(const std::string& vertex_shader_path, const std::string& fragment_shader_path);
  void linkShaders();

  void use();
  void unuse();
};
