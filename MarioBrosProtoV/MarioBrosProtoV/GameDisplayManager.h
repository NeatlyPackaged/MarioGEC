#ifndef GAMEDISPLAYMANAGER_H
#define GAMEDISPLAYMANAGER_H


#include <SDL.h>


#include "Commons.h"

class GameScreen;

class GameDisplayManager {
private:
	//Creating the variables & Functions for the cpp file to use. These are privated meaning the members in here can only be called in the members functions.
	SDL_Renderer* m_renderer;
	GameScreen* m_currentScreen;

public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	GameDisplayManager(SDL_Renderer* renderer, SCREENS startScreen);
	~GameDisplayManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS newScreen);
	SCREENS GetCurrentScreen();
};

#endif // !GAMESCREENMANAGER_H