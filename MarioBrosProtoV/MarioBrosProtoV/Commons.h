#ifndef COMMONS_H
#define COMMONS_H

//The struct class will allow multiple variables to be listed under one name, this one being vector2d.
struct Vector2D 
{
	float x, y;

	Vector2D() 
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D(float newX, float newY) 
	{
		x = newX;
		y = newY;
	}
};

//The struct class will allow multiple variables to be listed under one name, this one being rect2d.
struct Rect2D 
{
	float x, y, w, h;

	Rect2D() 
	{
		x = 0; y = 0;
		w = 0; h = 0;
	}

	Rect2D(float newX, float newY, float newW, float newH) 
	{
		x = newX; y = newY;
		w = newW; h = newH;
	}
	
};

//The struct class will allow multiple variables to be listed under one name, this one being circle2d.
struct Circle2D 
{
	float x, y, radius;

	Circle2D() 
	{
		x = 0; y = 0;
		radius = 0;
	}

	Circle2D(float newX, float newY, float newRadius) 
	{
		x = newX; y = newY;
		radius = newRadius;
	}
};

//The enum class is used to represent a group of constants, variables that cannot be changed. This one is in relation to the screens.
enum class SCREENS 
{
	SCREEN_INTRO = 0,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES
};

//The enum class is used to represent a group of constants, variables that cannot be changed. This one is in relation to the Players facing.
enum class FACING 
{
	FACING_LEFT,
	FACING_RIGHT
};



#endif // COMMONS_H


