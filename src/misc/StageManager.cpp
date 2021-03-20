#include "StageManager.h"

#include "pugixml.hpp"
#include <iostream>

#include "globalvariables.h"
#include "raylib.h"


Stage main_stage;

StageManager::StageManager()
{
	
}

bool StageManager::LoadLevel(std::uint16_t level)
{
	//load map
	std::string mapFilePath = "";
	std::string textureFilePath = "";
	
	//set file paths
	switch(level)
	{
		case 0:
		{  
			mapFilePath = DATADIR_STR + "/stage_assets/cubicmap.png";
			textureFilePath = DATADIR_STR + "/stage_assets/cubicmap_atlas.png";
			break;
		}
	}
	
	//load level based on file paths
	if(mapFilePath != "" && textureFilePath != "")
	{
		//
		Image imMap = LoadImage(mapFilePath.c_str());      // Load cubicmap image (RAM)

		Mesh mesh = GenMeshCubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
		main_stage.model = LoadModelFromMesh(mesh);

		// NOTE: By default each cube is mapped to one part of texture atlas
		
		Texture2D texture = LoadTexture(textureFilePath.c_str());    // Load map texture
		//MATERIAL_MAP_DIFFUSE = maps[0]
		main_stage.model.materials[0].maps[0].texture = texture;             // Set map diffuse texture

		// Get map image data to be used for collision detection
		main_stage.mapPixels = LoadImageColors(imMap);
		UnloadImage(imMap);             // Unload image from RAM
		

	}
	else
	{
		std::cout << "Uninitialized map file path or texture file paths.";
		return false;
	}
	
	return true;
}

void StageManager::FreeCurrentLoadedLevel()
{
	UnloadImageColors(main_stage.mapPixels);   // Unload color array
	UnloadModel(main_stage.model);             // Unload map model
}
