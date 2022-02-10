// MarioBrosProtoV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "constants.h"

using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
SDL_Texture* g_texture = nullptr;

//prototypes
bool InitSDL();
SDL_Texture* LoadTextureFromFile(string path);
void CloseSDL();
void Render();
void FreeTexture();

//Function prototypes
bool InitSDL()
{
    //Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL did not initialise. Error: " << SDL_GetError();
        return false;
    }
    else
    {
        g_window = SDL_CreateWindow("Games Engine Creation",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
        //did the window get created?
        if (g_window == nullptr)
        {
            //window failed
            cout << "Window was not created. Error: " << SDL_GetError();
            return false;
        }
        g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

        if (g_renderer != nullptr)
        {
            //init PNG loading
            int imageFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imageFlags) & imageFlags))
            {
                cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
                return false;
            }

        }
        else 
        {
            cout << "Renderer could not initialise. Error: " << SDL_GetError();
            return false;
        }

        //Load the background texture
        g_texture = LoadTextureFromFile("Images/test.bmp");
        if (g_texture == nullptr)
        {
            return false;
        }
    }
}

    bool Update()
    {
        // Event Handler
        SDL_Event e;

        //get events
        SDL_PollEvent(&e);

        //handle the events
        switch (e.type)
        {
            //click the 'X' to quit
        case SDL_QUIT:
                return true;
                break;

                //Additional Keyboard Task to quit

        }



        return false;
    }

    void CloseSDL()
    {
        //release the window
        SDL_DestroyWindow(g_window);
        g_window = nullptr;

        //quit SDL subsystems
        IMG_Quit();
        SDL_Quit();
        //clear the texture
        
        
        
        FreeTexture();
        //release the renderer
        SDL_DestroyTexture(g_texture);
        g_texture = nullptr;
    }

    

    void Render()
    {
        SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(g_renderer);
        SDL_Rect renderLocation = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

        //Render to screen
        SDL_RenderCopyEx(g_renderer, g_texture, NULL, &renderLocation, 0, NULL, SDL_FLIP_NONE);

        //Update the Screen
        SDL_RenderPresent(g_renderer);
    }

    SDL_Texture* LoadTextureFromFile(string path)
    {
        //remove memory used for a previous texture
        FreeTexture();
        SDL_Texture* p_texture = nullptr;

        //Load the image
        SDL_Surface* p_surface = IMG_Load(path.c_str());
        if (p_surface != nullptr)
        {
            //create the texture from the pixels on the surface
            p_texture = SDL_CreateTextureFromSurface(g_renderer, p_surface);
            if (p_texture == nullptr)
            {
                cout << "Unable to create texture from surface. Error: " << SDL_GetError();
            }
            //remove the loaded surface now that we have a texture
            SDL_FreeSurface(p_surface);
        }
        else {
            cout << "Unable to create texture from surface. Error: " << IMG_GetError();
        }
        //return the texture
        return p_texture;
    }

    void FreeTexture()
    {
        //check if texture exists before removing it
        if(g_texture != nullptr)
        {
            SDL_DestroyTexture(g_texture);
            g_texture = nullptr;
        }
    }



    int main(int argc, char* args[])
    {
        

        //check if sdl was setup correctly
        if (InitSDL())
        {
            //flag to check if we wish to quit
            bool quit = false;

            //Game Loop
            while (!quit)
            {
                Render();
                quit = Update();
            }
        }

        CloseSDL();

        return 0;
    }