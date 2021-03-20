#ifndef LEVEL_MAP_H
#define LEVEL_MAP_H

#include "raylib.h"
#include <vector>
#include <cstdint>
#include <iostream>

struct Stage
{
	//holds entire 3d mesh of stage
	Model model;
	//holds color info of image, black = floor, white = wall
	Color *mapPixels = nullptr; 
};

//only load and free 1 stage since only 1 stage is played at a time
extern Stage main_stage;

#endif
