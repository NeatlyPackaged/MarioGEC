#pragma once
#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "Commons.h"

class Character;

class Collisions {
private:
	//Creating the variables & Functions for the cpp file to use. These are privated meaning the members in here can only be called in the members functions.
	static Collisions* m_instance;

	Collisions();

public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	static Collisions* Instance();

	~Collisions();

	bool Circle(Character* character1, Character* character2);
	bool Circle(Circle2D circle1, Circle2D circle2);
	bool Box(Rect2D rect1, Rect2D rect2);
	bool Pixel(Vector2D point1, Vector2D point2);

};


#endif // !COLLISIONS_H