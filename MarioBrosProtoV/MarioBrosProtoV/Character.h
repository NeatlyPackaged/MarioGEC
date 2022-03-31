#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>
#include <iostream>

#include "Commons.h"
#include "LevelMap.h"

using namespace std;

class Texture2D;

class Character 
{
protected:
	//Creating the variables & Functions for the cpp file to use. These are protected meaning they can be used in a specific class but never in any other.
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;

	bool m_jumping;
	bool m_canJump;
	float m_jumpForce;
	float m_collisionRadius;
	bool m_movingLeft;
	bool m_movingRight;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);

private:
	//Creating the variables & Functions for the cpp file to use. These are privated meaning the members in here can only be called in the members functions.
	float m_speed;
	FACING m_facingDirection;
	LevelMap* m_currentLevelMap;

	void AddGravity(float deltaTime);

public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	

	Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Character();

	virtual void Render(SDL_RendererFlip flip);
	virtual void Update(float deltaTime, SDL_Event e);

	Vector2D GetPosition();
	float GetCollisionRadius();
	Circle2D GetCollisionCircle();
	Rect2D GetCollisionBox();

	void Jump();
	void SetPosition(Vector2D newPosition);
	void SetFacingDirection(FACING newDirection);
	FACING GetFacingDirection();
};

#endif // CHARACTER_H
