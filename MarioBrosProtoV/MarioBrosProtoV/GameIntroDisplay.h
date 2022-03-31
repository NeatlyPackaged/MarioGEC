#ifndef GAMEINTRODISPLAY_H
#define GAMEINTRODISPLAY_H


#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"

class Texture2D;

class GameIntroDisplay :
	public GameScreen 
{
private:
	//Creating the variables & Functions for the cpp file to use. These are privated meaning the members in here can only be called in the members functions.
	Texture2D* m_backgroundTexture;
	SCREENS m_screen;

	bool SetUpLevel();

public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	GameIntroDisplay(SDL_Renderer* renderer, SCREENS screen);
	~GameIntroDisplay();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	SCREENS GetScreenID() { return m_screen; }

};


#endif // !GAMEINTRODISPLAY_H