#include "GameDisplayManager.h"

/* usr lib */
#include "GameScreen.h"
#include "GameIntroDisplay.h"
#include "GameLevel1Display.h"

GameDisplayManager::GameDisplayManager(SDL_Renderer* renderer, SCREENS startScreen) {
	m_renderer = renderer;

	m_currentScreen = nullptr;

	ChangeScreen(startScreen);
}

GameDisplayManager::~GameDisplayManager() {
	m_renderer = nullptr;

	delete m_currentScreen;
	m_currentScreen = nullptr;
}

void GameDisplayManager::Render() {
	m_currentScreen->Render();
}

void GameDisplayManager::Update(float deltaTime, SDL_Event e) {
	m_currentScreen->Update(deltaTime, e);
}

void GameDisplayManager::ChangeScreen(SCREENS newScreen) {
	//Clear up old screen.
	if (m_currentScreen != nullptr) {
		delete m_currentScreen;
	}

	GameLevel1Display* tmpLevel1Screen = nullptr;
	GameIntroDisplay* tmpIntroScreen = nullptr;

	switch (newScreen) {
	case SCREENS::SCREEN_INTRO:
		tmpIntroScreen = new GameIntroDisplay(m_renderer, newScreen);
		m_currentScreen = (GameScreen*)tmpIntroScreen;
		tmpIntroScreen = nullptr;
		break;
	case SCREENS::SCREEN_MENU:
		break;
	case SCREENS::SCREEN_LEVEL1:
		tmpLevel1Screen = new GameLevel1Display(m_renderer, newScreen);
		m_currentScreen = (GameScreen*)tmpLevel1Screen;
		tmpLevel1Screen = nullptr;
		break;
	case SCREENS::SCREEN_LEVEL2:
		break;
	case SCREENS::SCREEN_GAMEOVER:
		break;
	case SCREENS::SCREEN_HIGHSCORES:
		break;
	default:
		break;
	}
}

SCREENS GameDisplayManager::GetCurrentScreen() {
	return m_currentScreen->GetScreenID();
}