#include "MediaLoader.h"

#include "globalvariables.h"

Texture2D title_menu_texture;
Texture2D char_select_texture;

Model base_fighter_model;
Texture2D base_fighter_texture;

MediaLoader::MediaLoader()
{
	
}

bool MediaLoader::loadMedia()
{
	std::string filepath = DATADIR_STR + "/title_menu.png";
	title_menu_texture = LoadTexture(filepath.c_str());
	
	filepath = DATADIR_STR + "/char_select.png";
	char_select_texture = LoadTexture(filepath.c_str());
	
	base_fighter_model = LoadModel("../data/fighter_assets/dance-fighter-base.iqm");
	base_fighter_texture = LoadTexture("../data/fighter_assets/testfighter_texture.png");
	SetMaterialTexture(&base_fighter_model.materials[0], MAP_DIFFUSE, base_fighter_texture);
	
	return true;
}

void MediaLoader::freeMedia()
{
	UnloadTexture(title_menu_texture);
	UnloadTexture(char_select_texture);
}
