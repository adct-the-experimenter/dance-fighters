#include "char_selector.h"

#include "core/system.h"
#include "core/coordinator.h"

#include "misc/media.h" //for texture

extern Coordinator gCoordinator;

CharacterSelector::CharacterSelector()
{
	std::array <Color,8> t_colors = {WHITE,BLUE,BEIGE,GRAY,BROWN,RED,GOLD,LIGHTGRAY};
	colors = t_colors;
	
	move_next_state = false;
	
	m_num_fighters = 2;
}

CharacterSelector::~CharacterSelector()
{
	
}

void CharacterSelector::Init(std::vector <Entity> *entities_vec_ptr, std::uint8_t num_players)
{
	//initialize vector holding pointers to player entitites
	//assuming first entities in entire entity vector are player entities.
	
	player_entities_vec.resize(num_players);
	
	for(size_t i = 0; i < player_entities_vec.size(); i++)
	{
		player_entities_vec[i] = &entities_vec_ptr->at(i);
	}
	
	fighter_boxes.resize(m_num_fighters);
	
	char_confirmations.resize(num_players);
	
	//initialize name slot text box locations for each character
	for(size_t it = 0; it < fighter_boxes.size(); it++)
	{
		fighter_boxes[it].name_slot.textBox = {100*(it+1),20,50,20};
	}
}

void CharacterSelector::handle_input(ControllerInput& controller_input, KeyboardInput& key_input)
{
	CharacterSelector::handle_controller_input(controller_input);
	CharacterSelector::handle_keyboard_input(key_input);
}

const int16_t joystick_border = 32600;

void CharacterSelector::handle_controller_input(ControllerInput& input)
{
	//number of character boxes and number of players should be the same
	
	//for each controller
	for(size_t i = 0; i < input.gamepads_vec.size();i++)
	{
		//if joystick moved up, go up a slot
		if(input.gamepads_vec[i].y_dir_axis < -joystick_border)
		{
			
		}
		//else if joystick moved down, go down a slot
		else if(input.gamepads_vec[i].y_dir_axis > joystick_border)
		{
			
		}
			
		//if joystick moved left, go left on color choice
		if(input.gamepads_vec[i].x_dir_axis < -joystick_border)
		{
			
		}
		//if joystick moved right, go right on color choice
		else if(input.gamepads_vec[i].x_dir_axis > joystick_border)
		{
			
		}
		
		//if a button pressed, turn confirm bool on
		if(input.gamepads_vec[i].button == SDL_CONTROLLER_BUTTON_A)
		{
			fighter_boxes[i].confirm_selection = true;
		}
	}
	
}

void CharacterSelector::handle_keyboard_input(KeyboardInput& input)
{
	
}

void CharacterSelector::logic()
{
	int width = 30;
	
	for(size_t i = 0; i < fighter_boxes.size(); i++)
	{  	
		
		//if selection confirmed
		if(fighter_boxes[i].confirm_selection)
		{
			//create new render components for player entity, and set player info based on choices.
			//if not already created
			if(!char_confirmations[i])
			{
				char_confirmations[i] = true;
				
				//add multiple render component 
				
				
				//add render position
				
				//add player info component
				
														
				//add input react component
				
				//add transform
				
				//add rigid body
						
				//add gravity component for later use
				
				//add physics type
						
				//add collision box
				
				//add animation component
				
			}
			
		}
		
	}
	
	//check if all players confirmed character creations
	bool all_confirmed = true;
	for(size_t i = 0; i < char_confirmations.size(); i++)
	{
		all_confirmed = char_confirmations[i];
		if(!all_confirmed){break;}
	}
	
	if(all_confirmed)
	{
		move_next_state = true;
	}
	
}

std::array <std::string,6> str_attr_array = {"Hair","Head", "Eyes","Upper Body", "Lower Body", "Shoes"};
void CharacterSelector::render()
{
	
	//render body part slots
	for(size_t i = 0; i < fighter_boxes.size(); i++)
	{
		Vector2 position = {100*(i+1) + i*50,0};
		
		//if selection is not confirmed
		if(!fighter_boxes[i].confirm_selection)
		{
			//draw textures of each slot
			
			
			//render text box for typing slot
			
		}
		
	}
	
}

void CharacterSelector::sound()
{
	//play some character select music
}

bool CharacterSelector::MoveToNextStateBool(){return move_next_state;}
