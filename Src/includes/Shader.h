#pragma once
#include <glad/glad.h>

namespace Vox
{
    struct ShaderBundle
    {
        unsigned int VertexShader, FragmentShader;
    };

    ShaderBundle CreateShaders(const char *VertexPath, const char *FragmentPath);
    unsigned int CreateProgram(ShaderBundle Shaders);
} // namespace Vox
