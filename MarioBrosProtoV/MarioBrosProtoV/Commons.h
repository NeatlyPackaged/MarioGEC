#pragma once
struct Vector2D
{
	float x;
	float y;
	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}
	float initial_x;
	float initial_y;
	Vector2D()
	{
		x = initial_x;
		y = initial_y;
	}
};
