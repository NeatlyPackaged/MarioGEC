#ifndef CHARACTERLUIGI_H
#define CHARACTERLUIGI_H

#include "Character.h"
class CharacterLuigi :
	public Character {
public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	CharacterLuigi(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~CharacterLuigi();

	void Render();
	void Update(float deltaTime, SDL_Event e);
};

#endif // !CHARACTERLUIGI_H