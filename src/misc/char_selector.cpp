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
		if(input.gamepads_vec[i].left_y_dir_axis < -joystick_border)
		{
			
		}
		//else if joystick moved down, go down a slot
		else if(input.gamepads_vec[i].left_y_dir_axis > joystick_border)
		{
			
		}
			
		//if joystick moved left, go left on color choice
		if(input.gamepads_vec[i].left_x_dir_axis < -joystick_border)
		{
			
		}
		//if joystick moved right, go right on color choice
		else if(input.gamepads_vec[i].left_x_dir_axis > joystick_border)
		{
			
		}
		
		//if a button pressed, turn confirm bool on
		if(input.gamepads_vec[i].button_up_released == SDL_CONTROLLER_BUTTON_A)
		{
			fighter_boxes[i].confirm_selection = true;
		}
	}
	
}

void CharacterSelector::handle_keyboard_input(KeyboardInput& input)
{
	
}

static const Vector3 player1_start = {1.0f,2.0f,0.0f};
static const float player1_rad_angle = 0.0f;

static Vector3 player2_start = {-1.0f,2.0f,0.0f};
static const float player2_rad_angle = PI;

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
				
				//add render component 
				
				gCoordinator.AddComponent(
								*player_entities_vec[i],
								RenderModelComponent {
									.model = base_fighter_model,
									.texture = base_fighter_texture
								}
							);
				
				
				//add player info component
				gCoordinator.AddComponent(
								*player_entities_vec[i],
								Player {
									.player_num = i + 1
								}
							);
														
				//add input react component
				InputReact react;
				react.actor_type = InputReactorType::PLAYER;
				react.reactToInput = true;
				react.player_num = i + 1;
								 
				gCoordinator.AddComponent(
								*player_entities_vec[i],
								react
								);
							
				//add transform
				Vector3 initP;
				float rad_angle = 0.0f;
				
				if(i == 0){ initP = player1_start; rad_angle = player1_rad_angle;}
				else if(i == 1){ initP = player2_start; rad_angle = player2_rad_angle;}
				
				gCoordinator.AddComponent(
							*player_entities_vec.at(i),
							Transform3D{
								.position = initP,
								.polar_rad_angle = rad_angle
							}
						);
				
				//add rigid body
				Vector3 initV = {0.0f,0.0f,0.0f};
				gCoordinator.AddComponent(
							*player_entities_vec.at(i),
							RigidBody3D{
								.velocity = initV
							}
						);
						
				//add gravity component for later use
				Vector3 grav = {0.0f,0.0f,0.0f};
				gCoordinator.AddComponent(
							*player_entities_vec.at(i),
							Gravity3D{
								.force = grav 
							}
						);
						
				//add physics type
				PhysicsType pType = PhysicsType::FIGHTING_GAME;
				gCoordinator.AddComponent(
							*player_entities_vec.at(i),
							PhysicsTypeComponent{
								.phy_type = pType 
							}
						);
						

				
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

void CharacterSelector::render()
{
	
	//render body part slots
	for(size_t i = 0; i < fighter_boxes.size(); i++)
	{
		
		//if selection is not confirmed
		if(!fighter_boxes[i].confirm_selection)
		{
			//draw texture of character select boxes
			DrawTexture(char_select_texture, 200, 100, WHITE);
			
		}
		
	}
	
}

void CharacterSelector::sound()
{
	//play some character select music
}

bool CharacterSelector::MoveToNextStateBool(){return move_next_state;}
