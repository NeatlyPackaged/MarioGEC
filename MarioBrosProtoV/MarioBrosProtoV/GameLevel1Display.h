#ifndef GAMELEVEL1DISPLAY_H
#define GAMELEVEL1DISPLAY_H

/* SDL lib */
#include <SDL.h>

/* usr lib */
#include "Commons.h"
#include "GameScreen.h"
#include "Character.h"
#include "CharacterMario.h"
#include "CharacterLuigi.h"
#include "LevelMap.h"

class Texture2D;
class Character;

class GameLevel1Display :
	public GameScreen {
private:
	Texture2D* m_backgroundTexture;
	SCREENS m_screen;

	CharacterMario* marioCharacter;
	CharacterLuigi* luigiCharacter;

	LevelMap* mLevelMap;

	bool SetUpLevel();
	void SetLevelMap();

public:
	GameLevel1Display(SDL_Renderer* renderer, SCREENS screen);
	~GameLevel1Display();

	void Render();
	void Update(float deltaTime, SDL_Event e);

	SCREENS GetScreenID() { return m_screen; }
};

#endif // !GAMESCREENLEVEL1_H