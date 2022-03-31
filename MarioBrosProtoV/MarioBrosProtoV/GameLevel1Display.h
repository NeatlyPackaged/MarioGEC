#ifndef GAMELEVEL1DISPLAY_H
#define GAMELEVEL1DISPLAY_H

#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "LevelMap.h"

class Texture2D;
class Character;

class GameLevel1Display :
	public GameScreen 
{
private:
	//Creating the variables & Functions for the cpp file to use. These are privated meaning the members in here can only be called in the members functions.
	Texture2D* m_backgroundTexture;
	SCREENS m_screen;

	CharacterMario* marioCharacter;
	CharacterLuigi* luigiCharacter;

	LevelMap* m_levelMap;

	bool SetUpLevel();
	void SetLevelMap();

public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	GameLevel1Display(SDL_Renderer* renderer, SCREENS screen);
	~GameLevel1Display();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	SCREENS GetScreenID() { return m_screen; }
};

#endif // !GAMESCREENLEVEL1_H