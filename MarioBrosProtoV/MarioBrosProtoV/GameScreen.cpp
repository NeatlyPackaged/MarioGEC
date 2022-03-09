#include "GameScreen.h"

GameScreen::GameScreen(SDL_Renderer* renderer, SCREENS screen) {
	m_renderer = renderer;

	m_screen = screen;
}

GameScreen::~GameScreen() {
	m_renderer = nullptr;
}

void GameScreen::Render()
{
}

void GameScreen::Update(float deltaTime, SDL_Event e)
{
}

SCREENS GameScreen::GetScreenID() {
	return m_screen;
}