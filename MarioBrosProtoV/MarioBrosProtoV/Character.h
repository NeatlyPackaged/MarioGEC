#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>
#include <iostream>

#include "Commons.h"

using namespace std;

class Texture2D;

class Character {
protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;

	bool m_jumping;
	bool m_canJump;
	float m_jumpForce;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);

private:
	float m_speed;
	FACING m_facingDirection;

	void AddGravity(float deltaTime);

public:
	bool m_movingLeft;
	bool m_movingRight;

	Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	Vector2D GetPosition();
	void Jump();
	void SetPosition(Vector2D newPosition);
};

#endif // CHARACTER_H
