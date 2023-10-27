#pragma once
#include <glm.hpp>
#include <Shape.h>

namespace Vox
{
    struct Vertex
    {
        glm::vec3 Position;
        glm::vec2 UV;
    };

    class Mesh
    {   public:
        Mesh(Shape& Data);
        unsigned int GetVbo();
        unsigned int GetEbo();
        unsigned int GetVao();

        void Draw(unsigned int shader, unsigned int texture);

        private:
        unsigned int vbo, vao, ebo;
        size_t VertCount, IndexCount;
    };

}