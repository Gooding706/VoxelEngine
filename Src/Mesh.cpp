#include <Mesh.h>
#include <Shape.h>
#include <glad/glad.h>

namespace Vox
{
    Mesh::Mesh(Shape& Data)
    {
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vox::Vertex)*4, Data.GetVerts(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*6, Data.GetIndices(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vox::Vertex), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vox::Vertex), (void*)(sizeof(glm::vec3)));
        glEnableVertexAttribArray(1);
    }

    unsigned int Mesh::GetVbo()
    {
        return vbo;
    }
    unsigned int Mesh::GetEbo()
    {
        return ebo;
    }
    unsigned int Mesh::GetVao()
    {
        return vao;
    }

    void Mesh::Draw(unsigned int shader, unsigned int texture)
    {
        glUseProgram(shader);
        glBindVertexArray(vao);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
} // namespace Vox

