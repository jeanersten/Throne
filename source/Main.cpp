#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

unsigned int screen_width{ 640 };
unsigned int screen_height{ 480 };

void cleanup();

void frameBufferSizeCallbackFunc(GLFWwindow* window, int width, int height);

void handleInput(GLFWwindow* window);

int main(int argc, char* argv[])
{
  if (!glfwInit())
  {
    std::cerr << "Failed to initialize GLFW!\n";

    cleanup();

    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window{ glfwCreateWindow(screen_width, screen_height, "Throne Engine!", nullptr, nullptr) };

  if (window == nullptr)
  {
    std::cerr << "Failed to create GLFW window!\n";

    cleanup();

    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cerr << "Failed to load GLAD!\n";

    cleanup();

    return -1;
  }

  glfwSetFramebufferSizeCallback(window, frameBufferSizeCallbackFunc);

  while (!glfwWindowShouldClose(window))
  {
    glfwWaitEvents();

    handleInput(window);

    glfwSwapBuffers(window);
    glfwSwapInterval(1);
  }

  cleanup();

  return 0;
}

void cleanup()
{
  glfwTerminate();
}

void frameBufferSizeCallbackFunc(GLFWwindow* window, int width, int height)
{
  screen_width = width;
  screen_height = height;

  glViewport(0, 0, width, height);
}

void handleInput(GLFWwindow* window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}
