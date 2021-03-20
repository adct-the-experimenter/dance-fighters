#ifndef TILE_MANAGER_H
#define TILE_MANAGER_H

#include "level_maps.h"
#include <vector>


class StageManager
{
public:
	
	StageManager();
	
	bool LoadLevel(std::uint16_t level);
	void FreeCurrentLoadedLevel();
		
private:
	
	
	
	
};

#endif
