#include "Character.h"
#include "Texture2D.h"
#include "constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map) {
	m_renderer = renderer;

	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath)) {
		cout << "Failed to load " << imagePath << " texture!" << endl;
	}
	else {

	}

	SetPosition(startPosition);

	m_speed = MOVEMENT_SPEED;

	m_facingDirection = FACING::FACING_RIGHT;

	m_movingLeft = false;
	m_movingRight = false;

	m_canJump = true;
	m_jumping = false;
	m_jumpForce = 0.0f;

	m_collisionRadius = int(m_texture->GetWidth() + m_texture->GetHeight()) / 2;
	m_currentLevelMap = map;
}

Character::~Character() {
	m_renderer = nullptr;
}

void Character::AddGravity(float deltaTime) {
	if (m_position.y + this->m_texture->GetHeight() >= SCREEN_HEIGHT) {
		m_canJump = true;
		m_jumping = false;
		m_jumpForce = 0.0f;
	}
	else if (!m_jumping) {
		m_position.y += 200.0f * deltaTime;
	}

}

Vector2D Character::GetPosition() {
	return m_position;
}

float Character::GetCollisionRadius() {
	return m_collisionRadius;
}

Circle2D Character::GetCollisionCircle() {
	return Circle2D(m_position.x, m_position.y, m_collisionRadius);
}

Rect2D Character::GetCollisionBox() {
	return Rect2D(
		m_position.x, m_position.y,
		m_texture->GetWidth(), m_texture->GetHeight()
	);
}

void Character::Jump() {
	if (!m_jumping) {
		m_jumpForce = INITIAL_JUMP_FORCE;
		m_jumping = true;
		m_canJump = false;
	}
}

void Character::MoveLeft(float deltaTime) {
	m_position.x -= m_speed;
	m_facingDirection = FACING::FACING_LEFT;
}

void Character::MoveRight(float deltaTime) {
	m_position.x += m_speed;
	m_facingDirection = FACING::FACING_RIGHT;
}

void Character::Render(SDL_RendererFlip flip) {
	m_texture->Render(m_position, flip);
	/*switch (m_facingDirection) {
	case FACING::FACING_LEFT:
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
		break;
	case FACING::FACING_RIGHT:
		m_texture->Render(m_position, SDL_FLIP_NONE);
		break;
	default:
		break;
	}*/
}

void Character::SetPosition(Vector2D newPosition) {
	m_position = newPosition;
}

FACING Character::GetFacingDirection() {
	return m_facingDirection;
}

void Character::SetFacingDirection(FACING newDirection) {
	m_facingDirection = newDirection;
}

void Character::Update(float deltaTime, SDL_Event e) {

	//Collision position variables.
	int centralXPosition = (int)(m_position.x + (m_texture->GetWidth() * 0.5f)) / TILE_WIDTH;
	int footPosition = (int)(m_position.y + m_texture->GetHeight()) / TILE_HEIGHT;


	//additional movement?
	if (m_jumping) {
		//Adjust the position.
		m_position.y -= m_jumpForce * deltaTime;

		//Reduce the jump force
		m_jumpForce -= JUMP_FORCE_DECREMENT * deltaTime;

		//Has the jump force reduced to zero?
		if (m_jumpForce <= 0.0f)
			m_jumping = false;
	}
	else {
		//Deal with gravity.
		if (m_currentLevelMap->GetTileAt(footPosition, centralXPosition) == 0) {
			AddGravity(deltaTime);
		}
		else {
			//Collided with ground so we can jump again.
			m_canJump = true;
		}
	}

	if (m_movingLeft) {
		MoveLeft(deltaTime);
	}
	else if (m_movingRight) {
		MoveRight(deltaTime);
	}

	/*
	//Handle any events.
	switch (e.type) {
	case SDL_KEYDOWN:
		//Check which key was pressed.
		switch (e.key.keysym.sym) {
		case SDLK_w:
		case SDLK_UP:
			cout << "JUMP!" << endl;
			break;
		case SDLK_a:
		case SDLK_LEFT:
			mMovingLeft = true;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			mMovingRight = true;
			break;
		}
		break;
	case SDL_KEYUP:
		//Check which key was released.
		switch (e.key.keysym.sym) {
		case SDLK_ESCAPE:
		case SDLK_w:
		case SDLK_UP:
			Jump();
			break;
		case SDLK_s:
			break;
		case SDLK_a:
		case SDLK_LEFT:
			mMovingLeft = false;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			mMovingRight = false;
			break;
		case SDLK_SPACE:
			break;
		}
		break;
		//Check for mouse button presses.
	case SDL_MOUSEBUTTONDOWN:
		switch (e.button.button) {
		//Left mouse button was pressed
		case 1:
			break;
		//Middle mouse button was pressed
		case 2:
			break;
		//Right mouse button was pressed
		case 3:
			break;
		}
		break;
	}
	*/


}
