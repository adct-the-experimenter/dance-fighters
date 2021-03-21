#include "MediaLoader.h"

#include "globalvariables.h"

Texture2D title_menu_texture;
Texture2D char_select_texture;

MediaLoader::MediaLoader()
{
	
}

bool MediaLoader::loadMedia()
{
	std::string filepath = DATADIR_STR + "/title_menu.png";
	title_menu_texture = LoadTexture(filepath.c_str());
	
	filepath = DATADIR_STR + "/char_select.png";
	char_select_texture = LoadTexture(filepath.c_str());
	
	return true;
}

void MediaLoader::freeMedia()
{
	UnloadTexture(title_menu_texture);
	UnloadTexture(char_select_texture);
}
