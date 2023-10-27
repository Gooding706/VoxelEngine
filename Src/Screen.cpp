#include <Screen.h>
#include <Quad.h>
#include <Shader.h>
#include <Mesh.h>

namespace Vox
{
    void Screen::Render()
    {
        ScreenInstance->I_Render();
    }

    void Screen::init()
    {
        Quad Q1(2, 2, {0, 0});
        ScreenMesh = new Mesh(Q1);

        glGenTextures(1, &Texture);
        Vox::ShaderBundle Shaders = Vox::CreateShaders("Shaders/Vert.glsl", "Shaders/Frag.glsl");
        unsigned int Program = Vox::CreateProgram(Shaders);
        ShaderProgram = Program;
    }

    const Screen* Screen::GetInstance()
    {
        if(ScreenInstance == nullptr){
            ScreenInstance = new Screen();
            ScreenInstance->init();
        }
        return ScreenInstance;
    }

    glm::vec2 Screen::GetDimensions()
    {
        return ScreenInstance->I_GetDimensions();
    }

    void Screen::SetDimensions(glm::vec2 Dimensions)
    {
        ScreenInstance->I_SetDimensions(Dimensions);
    }

    void Screen::SetPixel(glm::vec2 Position, Color PixelColor)
    {
        ScreenInstance->I_SetPixel(Position, PixelColor);
    }

    Color Screen::GetPixel(glm::vec2 Position)
    {
        return ScreenInstance->I_GetPixel(Position);
    }

    void Screen::ClearColor(Color PixelColor)
    {   
        ScreenInstance->I_ClearColor(PixelColor);
    }

    glm::vec2 Screen::I_GetDimensions()
    {
        return Dimensions;
    }

    void Screen::I_SetDimensions(glm::vec2 Dimensions)
    {
        this->Dimensions = Dimensions;
        ResizeArray();
    }

    void Screen::I_SetPixel(glm::vec2 Position, Color PixelColor)
    {
        PixelArray[(int)(Position.y * Dimensions.y + Position.x)] = PixelColor;
    }

    Color Screen::I_GetPixel(glm::vec2 Position)
    {
        return PixelArray[(int)(Position.y * Dimensions.y + Position.x)];
    }

    void Screen::I_ClearColor(Color PixelColor)
    {
        for (size_t i = 0; i < (Dimensions.x * Dimensions.y); i++)
        {
            PixelArray[i] = PixelColor;
        }
        
    }

    void Screen::ResizeArray()
    {
        delete[] PixelArray;
        PixelArray = new Color[Dimensions.x * Dimensions.y];
    }

    void Screen::I_Render()
    {
        ScreenMesh->Draw(ShaderProgram, Texture);
    }

    Screen *Screen::ScreenInstance = nullptr;
    Mesh *Screen::ScreenMesh = nullptr;
}