#include "GameLevel1Display.h"

#include <iostream>
#include "Texture2D.h"
#include "constants.h"

bool GameLevel1Display::SetUpLevel() {
	bool success = true;

	//Load the background texture.
	m_backgroundTexture = new Texture2D(m_renderer);
	if (!m_backgroundTexture->LoadFromFile("images/test.bmp")) {
		std::cout << "Failed to load background texture!" << std::endl;
		success = false;
	}

	//Set up player character.
	marioCharacter = new CharacterMario(m_renderer, "images/Mario.png", Vector2D(64, 330));
	luigiCharacter = new CharacterLuigi(m_renderer, "images/Luigi.png", Vector2D(352, 330));

	return success;
}

GameLevel1Display::GameLevel1Display(SDL_Renderer* renderer, SCREENS screen) :
	GameScreen(renderer, screen) {
	m_screen = screen;
	SetUpLevel();
}

GameLevel1Display::~GameLevel1Display() {
	delete m_backgroundTexture;
	m_backgroundTexture = nullptr;

	delete marioCharacter;
	marioCharacter = nullptr;

	delete luigiCharacter;
	luigiCharacter = nullptr;
}

void GameLevel1Display::Render() {
	m_backgroundTexture->Render(Vector2D(), SDL_FLIP_NONE);

	marioCharacter->Render();
	luigiCharacter->Render();
}

void GameLevel1Display::Update(float deltaTime, SDL_Event e) {
	//Update the player(s).
	marioCharacter->Update(deltaTime, e);
	luigiCharacter->Update(deltaTime, e);
}