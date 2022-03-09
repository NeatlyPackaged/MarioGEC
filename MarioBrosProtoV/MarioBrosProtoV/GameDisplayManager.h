#ifndef GAMEDISPLAYMANAGER_H
#define GAMEDISPLAYMANAGER_H

/* SDL lib */
#include <SDL.h>

/* usr lib */
#include "Commons.h"

class GameScreen;

class GameDisplayManager {
private:
	SDL_Renderer* m_renderer;
	GameScreen* m_currentScreen;

public:
	GameDisplayManager(SDL_Renderer* renderer, SCREENS startScreen);
	~GameDisplayManager();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS newScreen);
	SCREENS GetCurrentScreen();
};

#endif // !GAMESCREENMANAGER_H