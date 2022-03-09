#ifndef GAMESCREEN_H
#define GAMESCREEN_H


#include <SDL.h>
#include "Commons.h"

class GameScreen
{
protected:
	SDL_Renderer* m_renderer;

public:
	SCREENS m_screen;

	GameScreen(SDL_Renderer* renderer, SCREENS screen);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	SCREENS GetScreenID();
};

#endif // !GAMESCREEN_H
