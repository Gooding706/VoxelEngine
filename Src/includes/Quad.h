#pragma once
#include <Mesh.h>
#include <Shape.h>

namespace Vox
{
    class Quad : public Shape
    {
        private:
        Vertex Vertices[4];
        unsigned int indices[6] = 
        {
            0, 1, 3,
            1, 2, 3 
        };

        public:
        Quad(float width, float height, glm::vec2 Origin)
        {
            Vertices[0] = {glm::vec3(Origin.x - (width/2.0f), Origin.y - (height/2.0f), 0), glm::vec2(0, 0)};
            Vertices[1] = {glm::vec3(Origin.x - (width/2.0f), Origin.y + (height/2.0f), 0), glm::vec2(0, 1)};
            Vertices[2] = {glm::vec3(Origin.x + (width/2.0f), Origin.y + (height/2.0f), 0), glm::vec2(1, 1)};
            Vertices[3] = {glm::vec3(Origin.x + (width/2.0f), Origin.y - (height/2.0f), 0), glm::vec2(1, 0)};
        }
        const Vertex* GetVerts()
        {
            return Vertices;
        }

        const unsigned int* GetIndices()
        {
            return indices;
        }

        inline size_t NumIndices()
        {
            return 6;
        }

        inline size_t NumVerts()
        {
            return 4;
        }

    };
    
}