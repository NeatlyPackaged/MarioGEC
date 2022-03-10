#ifndef GAMEINTRODISPLAY_H
#define GAMEINTRODISPLAY_H


#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"

class Texture2D;

class GameIntroDisplay :
	public GameScreen {
private:
	Texture2D* m_backgroundTexture;
	SCREENS m_screen;

	bool SetUpLevel();

public:
	GameIntroDisplay(SDL_Renderer* renderer, SCREENS screen);
	~GameIntroDisplay();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	SCREENS GetScreenID() { return m_screen; }

};


#endif // !GAMEINTRODISPLAY_H