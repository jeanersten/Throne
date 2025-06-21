#include "Log.h"
#include "Shader.h"

#include <fstream>
#include <string>
#include <vector>

Shader::Shader()
  : m_program_id(0)
  , m_vertex_shader_id(0)
  , m_fragment_shader_id(0)
  , m_attribute_index(0)
{}

Shader::~Shader()
{}

void Shader::compileShader(const std::string& shader_path, GLuint shader_id)
{
  std::ifstream vertex_shader_file{ shader_path };

  if (vertex_shader_file.fail())
  {
    MSG_CRITICAL("Failed to open " + shader_path);
  }

  std::string file_content { };
  std::string string_line { };

  while (std::getline(vertex_shader_file, string_line))
  {
    file_content += string_line + '\n';
  }

  vertex_shader_file.close();

  const char* file_content_cstr = file_content.c_str();
  GLint compile_status{ GL_FALSE };

  glShaderSource(shader_id, 1, &file_content_cstr, nullptr);
  glCompileShader(shader_id);
  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compile_status);

  if (compile_status == GL_FALSE)
  {
    GLint string_length{ 0 };
    glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &string_length);

    std::vector<GLchar> error_log(string_length);

    glGetShaderInfoLog(shader_id, string_length, &string_length, &error_log[0]);
    glDeleteShader(shader_id);

    MSG_ERROR("Shader {} failed to be compiled!", shader_path);
    MSG_ERROR(error_log.data());
  }

}

void Shader::compileShaders(const std::string& vertex_shader_path, const std::string& fragment_shader_path)
{
  m_vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
  m_fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);

  if (m_vertex_shader_id == 0)
  {
    MSG_ERROR("Vertex shader failed to be created!");
  }

  if (m_fragment_shader_id == 0)
  {
    MSG_ERROR("Fragment failed to be created!");
  }

  compileShader(vertex_shader_path, m_vertex_shader_id);
  compileShader(fragment_shader_path, m_fragment_shader_id);
}

void Shader::linkShaders()
{
  m_program_id = glCreateProgram();

  GLint link_status{ GL_FALSE };

  glAttachShader(m_program_id, m_vertex_shader_id);
  glAttachShader(m_program_id, m_fragment_shader_id);
  glLinkProgram(m_program_id);
  glGetProgramiv(m_program_id, GL_LINK_STATUS, &link_status);

  if (link_status == GL_FALSE)
  {
    GLint string_length{ 0 };

    glGetProgramiv(m_program_id, GL_INFO_LOG_LENGTH, &string_length);

    std::vector<GLchar> error_log(string_length);

    glGetProgramInfoLog(m_program_id, string_length, &string_length, &error_log[0]);
    glDeleteProgram(m_program_id);

    MSG_ERROR("Shader program failed to be linked!");
    MSG_ERROR(error_log.data());
  }

  glDetachShader(m_program_id, m_vertex_shader_id);
  glDetachShader(m_program_id, m_fragment_shader_id);
  glDeleteShader(m_vertex_shader_id);
  glDeleteShader(m_fragment_shader_id);
}

void Shader::use()
{
  glUseProgram(m_program_id);

  for (int i = 0; i < m_attribute_index; i++)
  {
    glEnableVertexAttribArray(i);
  }
}

void Shader::unuse()
{
  glUseProgram(0);

  for (int i = 0; i < m_attribute_index; i++)
  {
    glDisableVertexAttribArray(i);
  }
}
