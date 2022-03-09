#include "Texture2D.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

Texture2D::Texture2D(SDL_Renderer* renderer)
{
    m_renderer = renderer;
    m_texture = nullptr;

    m_width = 0;
    m_height = 0;
}

Texture2D::~Texture2D()
{
    //free up memory
    Free();
    m_renderer = nullptr;
}

bool Texture2D::LoadFromFile(std::string path)
{

    //remove memory used for a previous texture
    Free();


    //Load the image
    SDL_Surface* m_surface = IMG_Load(path.c_str());

    if (m_surface == nullptr)
    {
        cout << "Unable to load image as surface. Error: " << SDL_GetError() << endl;
    }
    else {
        //set color key to transparent image
        SDL_SetColorKey(m_surface, SDL_TRUE, SDL_MapRGB(m_surface->format, 0, 0xFF, 0xFF));

        //create the texture from the pixels on the surface
        m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
        if (m_texture == nullptr)
        {
            cout << "Unable to create texture from surface. Error: " << SDL_GetError() << endl;
        }
        else
        {
            //setting the dimensions
            m_width = m_surface->w;
            m_height = m_surface->h;
        }

        //remove the loaded surface now that we have a texture
        SDL_FreeSurface(m_surface);
       
    }
    //return the texture
    return m_texture != nullptr;
}

void Texture2D::Free()
{
    //check if texture exists before removing it
    if (m_texture != nullptr)
    {
        SDL_DestroyTexture(m_texture);
        
    }
    
    m_width = 0;
    m_height = 0;
    m_texture = nullptr;
}

void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
    //Set where to render texture
    SDL_Rect renderLocation = { new_position.x,new_position.y, m_width, m_height };

    //render to screen
    SDL_RenderCopyEx(m_renderer, m_texture, nullptr, &renderLocation, 0, nullptr, SDL_FLIP_NONE);
}