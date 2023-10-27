#pragma once
#include <Mesh.h>

namespace Vox
{
    class Shape
    {
        public:
            virtual const Vertex* GetVerts() = 0;
            virtual const unsigned int* GetIndices() = 0;
            virtual size_t NumVerts() = 0;
            virtual size_t NumIndices() = 0;
        private:
            Vertex *Vertices;
            unsigned int *Indices;
    };
} // namespace Vox
