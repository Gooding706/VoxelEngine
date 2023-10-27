#include <glad/glad.h>
#include<GLFW/glfw3.h>

#include <Mesh.h>
#include <Quad.h>
#include <Shader.h>
#include <memory>
#include<Screen.h>
#include <Color.h>


void SetPixel(Vox::Color *Screen, Vox::Color PixelColor, glm::vec2 Position, int dim)
{
    Screen[(int)(Position.y * dim + Position.x)] = PixelColor;
}

void UpdateTexture(Vox::Color *Screen, int dim, unsigned int texture)
{
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, dim, dim, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, Screen);
    glGenerateMipmap(GL_TEXTURE_2D);
}

int main()
{
    int dim = 500;
    srand(time(nullptr));
    Vox::Color *Screen = new Vox::Color[dim*dim];
    


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

    unsigned int texture;
    glGenTextures(1, &texture);

    Vox::Quad Q1(2, 2, glm::vec2(0, 0));

    unsigned int vbo, ebo, vao;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vox::Vertex)*4, Q1.GetVerts(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*6, Q1.GetIndices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vox::Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vox::Vertex), (void*)(sizeof(glm::vec3)));
    glEnableVertexAttribArray(1);

    Vox::ShaderBundle Shaders = Vox::CreateShaders("Shaders/Vert.glsl", "Shaders/Frag.glsl");
    unsigned int Program = Vox::CreateProgram(Shaders);




    while(!glfwWindowShouldClose(Window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(Program);
        glBindVertexArray(vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        uint8_t val = (rand()%255);
        SetPixel(Screen, {val, val, val, 255}, {rand()%dim, rand()%dim}, dim);
        UpdateTexture(Screen, dim, texture);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(Window);
        glfwPollEvents();
    }
    return 0;
}