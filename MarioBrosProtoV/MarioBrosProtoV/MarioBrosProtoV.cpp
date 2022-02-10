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
    }
}
    void CloseSDL()
    {
        //release the window
        SDL_DestroyWindow(g_window);
        g_window = nullptr;

        //quit SDL subsystems
        IMG_Quit();
        SDL_Quit();
    }



    int main(int argc, char* args[])
    {


        //check if sdl was setup correctly
        if (InitSDL())
        {
            SDL_Delay(5000);
        }

        CloseSDL();

        return 0;
    }