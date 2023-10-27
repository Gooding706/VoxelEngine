#pragma once
#include<Quad.h>
#include <Color.h>
#include <Mesh.h>
#include <glm.hpp>
#include<glad/glad.h>


namespace Vox
{
    class Screen{
        public:
            static const Screen* GetInstance();
            static glm::vec2 GetDimensions();
            static void SetDimensions(glm::vec2 Dimensions);
            static void SetPixel(glm::vec2 Position, Color PixelColor);
            static Color GetPixel(glm::vec2 Position);
            static void ClearColor(Color PixelColor);
            static void Render();

        private:
            Screen(){};
            Screen(Screen &t) = delete;

            glm::vec2 I_GetDimensions();
            void I_SetDimensions(glm::vec2 Dimensions);
            void I_SetPixel(glm::vec2 Position, Color PixelColor);
            Color I_GetPixel(glm::vec2 Position);
            void I_ClearColor(Color PixelColor);
            void I_Render();
            

            void ResizeArray(); //Will Clear all pixels

            static Screen *ScreenInstance;
            static Mesh *ScreenMesh;
            void init();

            unsigned int Texture = 0;
            unsigned int ShaderProgram = 0;
            glm::vec2 Dimensions = {100, 100};
            Color *PixelArray;
    };
} // namespace Vox
