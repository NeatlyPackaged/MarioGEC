#pragma once
#ifndef LEVELMAP_H
#define LEVELMAP_H

#include "constants.h"

class LevelMap {
public:
	//Creating the variables & Functions for the cpp file to use. These are public meaning they can be called from outside classes if called.
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);
	~LevelMap();

	void ChangeTileAt(unsigned int row, unsigned int column, unsigned int newValue);
	int GetTileAt(unsigned int h, unsigned int w);

private:
	//Creating the variables & Functions for the cpp file to use. These are privated meaning the members in here can only be called in the members functions.
	int** m_map;
};

#endif // !LEVELMAP_H