#ifndef GAMESCREEN_H
#define GAMESCREEN_H


#include <SDL.h>
#include "Commons.h"

class GameScreen
{
protected:
	//Creating the variables & Functions for the cpp file to use. These are protected meaning they can be used in a specific class but never in any other.
	SDL_Renderer* m_renderer;

public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	SCREENS m_screen;

	GameScreen(SDL_Renderer* renderer, SCREENS screen);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	SCREENS GetScreenID();
};

#endif // !GAMESCREEN_H
