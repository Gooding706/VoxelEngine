#include <glad/glad.h>

#include<GLFW/glfw3.h>

int main()
{
    if (! glfwInit() )
    {
        return -1;
    }
      #ifdef __APPLE__
    /* We need to explicitly ask for a 3.3 context on OS X */
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif

    GLFWwindow *Window;
    Window = glfwCreateWindow(500, 500, "windowBruh", 0, 0);

    glfwMakeContextCurrent(Window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        return -1;
    }

    while(!glfwWindowShouldClose(Window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(Window);

        glfwPollEvents();
    }
    return 0;
}