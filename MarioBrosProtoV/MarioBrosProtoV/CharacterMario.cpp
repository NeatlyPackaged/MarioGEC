#include "CharacterMario.h"

CharacterMario::CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D startPosition)
	: Character(renderer, imagePath, startPosition) {
}

CharacterMario::~CharacterMario()
{
}

void CharacterMario::Update(float deltaTime, SDL_Event e) {
	Character::Update(deltaTime, e);

	//Handle any events.
	switch (e.type) {
	case SDL_KEYDOWN:
		//Check which key was pressed.
		switch (e.key.keysym.sym) {
		case SDLK_a:
			m_movingLeft = true;
			m_movingRight = false;
			break;

		case SDLK_d:
			m_movingRight = true;
			m_movingLeft = false;
			break;

		case SDLK_w:
			Jump();
			break;
		}
		break;

	case SDL_KEYUP:
		//Check which key was released.
		switch (e.key.keysym.sym) {

		case SDLK_a:
			m_movingLeft = false;
			break;

		case SDLK_d:
			m_movingRight = false;
			break;
		}
		break;
	}
}