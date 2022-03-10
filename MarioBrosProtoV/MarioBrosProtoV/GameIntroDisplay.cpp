#include "GameIntroDisplay.h"

#include <iostream>
#include "Texture2D.h"

bool GameIntroDisplay::SetUpLevel() {
	bool success = true;

	//Load the background texture.
	m_backgroundTexture = new Texture2D(m_renderer);
	if (!m_backgroundTexture->LoadFromFile("images/test.bmp")) {
		std::cout << "Failed to load background texture!" << std::endl;
		success = false;
	}

	return success;
}

GameIntroDisplay::GameIntroDisplay(SDL_Renderer* renderer, SCREENS screen) :
	GameScreen(renderer, screen) {
	m_screen = screen;
	SetUpLevel();
}

GameIntroDisplay::~GameIntroDisplay() {
	delete m_backgroundTexture;
	m_backgroundTexture = nullptr;

}

void GameIntroDisplay::Render() {
	m_backgroundTexture->Render(Vector2D(), SDL_FLIP_NONE);
}

void GameIntroDisplay::Update(float deltaTime, SDL_Event e) {
}