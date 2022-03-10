#ifndef CHARACTERMARIO_H
#define CHARACTERMARIO_H

#include "Character.h"

class CharacterMario :
	public Character {
public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~CharacterMario();

	void Render();
	void Update(float deltaTime, SDL_Event e);
};

#endif // !CHARACTERMARIO_H

