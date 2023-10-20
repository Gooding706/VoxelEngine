#pragma once
#include <Mesh.h>

namespace Vox
{
    class Quad
    {
        public:
        Vertex Vertices[4];
        unsigned int indices[6] = 
        {
            0, 1, 3,
            1, 2, 3 
        };

        Quad(int width, int height, glm::vec2 Origin)
        {
            Vertices[0] = {glm::vec3(0+Origin.x, 0+Origin.y, 0), glm::vec2(0, 0)};
            Vertices[1] = {glm::vec3(0+Origin.x, height+Origin.y, 0), glm::vec2(0, 1)};
            Vertices[2] = {glm::vec3(width+Origin.x, height+Origin.y, 0), glm::vec2(1, 1)};
            Vertices[3] = {glm::vec3(width+Origin.x, 0+Origin.y, 0), glm::vec2(1, 0)};
        }
    };
    
}