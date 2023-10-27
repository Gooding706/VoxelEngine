#include <Shader.h>
#include <fstream>
#include <sstream>
#include <iostream>

std::string ReadFile(const char *Path)
{
    std::ifstream f;
    f.open(Path, std::ios::in);
    if (!f.is_open())
    {
        std::cout << "file couldn't be read at" << Path << '\n';
    }

    // read whole file into stringstream buffer
    std::stringstream buffer;
    buffer << f.rdbuf();
    buffer << "\0";
    f.close();
    // need to copy, as pointer is deleted when call is finished
    std::string shaderCode = buffer.str();

    return shaderCode;
}

void LogCompile(unsigned int Shader)
{
    int success;
    char infoLog[512];

    glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(Shader, 512, NULL, infoLog);
        std::cout << infoLog << '\n';
    }
}

void LogLink(unsigned int Program)
{
    int success;
    char infoLog[512];

    glGetProgramiv(Program, GL_LINK_STATUS, &success);

    if(!success)
    {
        glGetProgramInfoLog(Program, 512, NULL, infoLog);
        std::cout << infoLog << '\n';
    }
}

namespace Vox
{
    ShaderBundle CreateShaders(const char *VertexPath, const char *FragmentPath)
    {   
        std::string vertString = ReadFile(VertexPath);
        std::string fragString = ReadFile(FragmentPath);

        const char *VertPT = vertString.c_str();
        const char *FragPT = fragString.c_str();

        unsigned int vert, frag;

        vert = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vert, 1, &VertPT, NULL);
        glCompileShader(vert); 
        LogCompile(vert);

        frag = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(frag, 1, &FragPT, NULL);
        glCompileShader(frag);
        LogCompile(frag);

        return {vert, frag}; 
    }

    unsigned int CreateProgram(ShaderBundle Shaders)
    {
        unsigned int program;
        program = glCreateProgram();
        glAttachShader(program, Shaders.VertexShader);
        glAttachShader(program, Shaders.FragmentShader);
        glLinkProgram(program);
        LogLink(program);

        glDeleteShader(Shaders.FragmentShader);
        glDeleteShader(Shaders.VertexShader);

        return program;
    }
} // namespace Vox
