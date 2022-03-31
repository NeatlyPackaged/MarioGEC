#include "GameLevel1Display.h"

#include <iostream>
#include "Texture2D.h"
#include "constants.h"
#include "Collisions.h"

GameLevel1Display::GameLevel1Display(SDL_Renderer* renderer, SCREENS screen) :
	GameScreen(renderer, screen) 
{
	m_screen = screen;
	m_levelMap = nullptr;
	SetUpLevel();
}

GameLevel1Display::~GameLevel1Display() 
{
	delete m_backgroundTexture;
	m_backgroundTexture = nullptr;

	delete marioCharacter;
	marioCharacter = nullptr;

	//delete luigiCharacter;
	//luigiCharacter = nullptr;
}

void GameLevel1Display::Render() 
{
	m_backgroundTexture->Render(Vector2D(), SDL_FLIP_NONE);

	marioCharacter->Render();
	//luigiCharacter->Render();
}

void GameLevel1Display::SetLevelMap() {
	int map[MAP_HEIGHT][MAP_WIDTH] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	//Clear up and old map.
	if (m_levelMap != nullptr) 
	{
		delete m_levelMap;
	}

	//Set the new map.
	m_levelMap = new LevelMap(map);
}

bool GameLevel1Display::SetUpLevel() 
{
	bool success = true;

	//Load the background texture.
	m_backgroundTexture = new Texture2D(m_renderer);
	if (!m_backgroundTexture->LoadFromFile("images/BackGroundMB.png")) 
	{
		std::cout << "Failed to load background texture!" << std::endl;
		success = false;
	}

	//Set up Level map.
	SetLevelMap();

	//Set up player character.
	marioCharacter = new CharacterMario(m_renderer, "images/Mario.png", Vector2D(64, 330), m_levelMap);
	//luigiCharacter = new CharacterLuigi(m_renderer, "images/Luigi.png", Vector2D(352, 330), m_levelMap);

	return success;
}


void GameLevel1Display::Update(float deltaTime, SDL_Event e) 
{
	//Update the player(s).
	marioCharacter->Update(deltaTime, e);
	//luigiCharacter->Update(deltaTime, e);

	//Circle Collision

	//if (Collisions::Instance()->Circle(
	//	marioCharacter->GetCollisionCircle(),
	//	luigiCharacter->GetCollisionCircle())
	//	) {
	//	cout << "Circle Bro Smash!" << endl;
	//}

	//if (Collisions::Instance()->Box(
	//	marioCharacter->GetCollisionBox(), luigiCharacter->GetCollisionBox())
	//	) {
	//	cout << "Box Bro Smash!" << endl;
	//}
}