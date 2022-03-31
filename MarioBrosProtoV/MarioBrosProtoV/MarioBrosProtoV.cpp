// MarioBrosProtoV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "GameDisplayManager.h"
#include "Texture2D.h"
#include "constants.h"
#include "Commons.h"

using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;

GameDisplayManager* g_DisplayManager = nullptr;

Uint32 g_OldTime;


//prototypes
bool InitSDL();
void CloseSDL();
void Render();
bool Update();
//SDL_Texture* LoadTextureFromFile(string path);

int main(int argc, char* args[])
{
    //used to check if we want to quit
    bool quit = false;

    //check if sdl was setup correctly
    if (InitSDL())
    {
        g_DisplayManager = new GameDisplayManager(g_renderer, SCREENS::SCREEN_LEVEL1);

        g_OldTime = SDL_GetTicks();


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


/*bool LoadTextureFromFile(std::string path)
{

    SDL_Texture* p_texture = nullptr;
    


    //Load the image
    SDL_Surface* m_surface = IMG_Load(path.c_str());
    if (p_surface != nullptr)
    {
        //set color key to transparent image
        SDL_SetColorKey(m_surface, SDL_TRUE, SDL_MapRGB(m_surface->format, 0, 0XFF, 0XFF))
            //create the texture from the pixels on the surface
            p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);
        if (p_texture == nullptr)
        {
            cout << "Unable to create texture from surface. Error: " << SDL_GetError();
        }
        else
        {
            m_width = m_surface->w;
            m_height = m_surface->h;
        }

        //remove the loaded surface now that we have a texture
        SDL_FreeSurface(m_surface);
    }
    else {
        cout << "Unable to create texture from surface. Error: " << IMG_GetError();
    }
    //return the texture
    return m_texture != nullptr;
}*/


//Function prototypes
bool InitSDL()
{
    //flag to remember if something has failed
    bool success = true;

    //Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL did not initialise. Error: " << SDL_GetError();
        success = true;
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
            success = false;
        }
        else {
            g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

            if (g_renderer == nullptr) {
                cout << "Renderer was not created. Error: " << SDL_GetError();
                success = false;
            }
            else
            {
                //Initialise PNG loading.
                int imageFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imageFlags) && imageFlags)) {
                    cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
                    success = false;
                }
                else {
                    /*//Load the background texture
                    g_texture = new Texture2D(g_renderer);

                    if (!g_texture->LoadFromFile("Images/test.bmp"))
                    {
                        cout << "Could not load image file (images/test.bmp). Error: " << endl;
						success = false;
                    } */
                }
            }
            
        }
        
    }

    return success;

}

    void CloseSDL()
    {
        delete g_DisplayManager;
        g_DisplayManager = nullptr;
         
        //release the renderer
        SDL_DestroyRenderer(g_renderer);
        g_renderer = nullptr;
        
        //release the window
        SDL_DestroyWindow(g_window);
        g_window = nullptr;

        //quit SDL subsystems
        IMG_Quit();
        SDL_Quit();
    }

    
    bool Update()
    {
        //Flag to check if quiting game.
        bool success = false;

        //Get the new time.
        Uint32 newTime = SDL_GetTicks();

        //Event Handler.
        SDL_Event e;

        //Get the events.
        SDL_PollEvent(&e);

        //Handle any events.
        switch (e.type) {
            //Click the 'X' to quit.
        case SDL_QUIT:
            success = true;
            break;

            //Check for key releases.
        case SDL_KEYUP:
            //Check which key was released.
            switch (e.key.keysym.sym) {

                //Press 'ESCAPE' to quit.
            case SDLK_ESCAPE:
                success = true;
                break;
            case SDLK_a:
            case SDLK_d:
            case SDLK_w:
            case SDLK_s:
                /*
                create a player class
                must handle:
                - self animation
                - store its position
                */
                break;
            case SDLK_SPACE:
                if (g_DisplayManager->GetCurrentScreen() == SCREENS::SCREEN_LEVEL1) 
                {
                    g_DisplayManager->ChangeScreen(SCREENS::SCREEN_INTRO);
                }
                else 
                {
                    g_DisplayManager->ChangeScreen(SCREENS::SCREEN_LEVEL1);
                }

                break;
            }
            break;

            //Check for mouse button presses.
        case SDL_MOUSEBUTTONDOWN:
            switch (e.button.button) 
            {
                //Left mouse button was pressed
            case 1:
                /*
                if (_gameState != gsPlaying) {
                    _gameState = gsPlaying;
                }
                */
                break;

                //Middle mouse button was pressed
            case 2:
                success = true;
                break;

                //Right mouse button was pressed
            case 3:
                success = true;
                break;
            }
            break;
        }

        g_DisplayManager->Update((float)(newTime - g_OldTime) / 1000.0f, e);

        //Set the current time to be the old time.
        g_OldTime = newTime;

        return success;
    }


    void Render()
    {
        // Clear the screen
        SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(g_renderer);

        g_DisplayManager->Render();

        //update the screen
        SDL_RenderPresent(g_renderer);
    }