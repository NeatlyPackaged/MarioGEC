#pragma once
#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_mixer.h>
//#include <string>
#include <iostream>
#include "Commons.h"

class Texture2D
{
public:
    //Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
    Texture2D(SDL_Renderer* renderer);
    ~Texture2D();

    bool LoadFromFile(std::string path);
    void Free();
    void Render(Vector2D new_position, SDL_RendererFlip flip, double angle = 0.0f);

    int GetWidth() { return m_width; }
    int GetHeight() { return m_height; }
    
private:
    //Creating the variables & Functions for the cpp file to use. These are privated meaning the members in here can only be called in the members functions.
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;

    int m_width;
    int m_height;
};

#endif //_TEXTURE2D_H