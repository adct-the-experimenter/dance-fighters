#include "InputReactorSystem.h"

#include "core/system.h"
#include "core/coordinator.h"


extern Coordinator gCoordinator;

float speed_factor = 10.0f;

void InputReactorSystem::Update(ControllerInput& input)
{
	for (auto const& entity : mEntities)
	{
		auto& inputReactor = gCoordinator.GetComponent<InputReact>(entity);
		auto& rigidBody = gCoordinator.GetComponent<RigidBody3D>(entity);
		
		switch(inputReactor.actor_type)
		{
			case InputReactorType::NONE:{break;}
			case InputReactorType::PLAYER:
			{
				//do player specific event handling
				//get other player specific component from entity.
				
				for(size_t i = 0; i < input.gamepads_vec.size(); i++)
				{
					//if player number matches game pad
					if(inputReactor.player_num == i + 1)
					{
						//figure out input
						
						inputReactor.current_index++;
						
						if(inputReactor.current_index == 4){inputReactor.current_index = 0;}
						
						//if move left
						if(input.gamepads_vec[i].left_x_dir_axis == -1)
						{
							inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::LEFT;
							
							if( input.gamepads_vec[i].left_y_dir_axis == -1)
							{
								inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::UP_LEFT;
							}
							else if( input.gamepads_vec[i].left_y_dir_axis == 1)
							{
								inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::DOWN_LEFT;
							}
						}
						//if move right
						else if( input.gamepads_vec[i].left_x_dir_axis == 1 )
						{
							inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::RIGHT;
							
							if( input.gamepads_vec[i].left_y_dir_axis == -1)
							{
								inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::UP_RIGHT;
							}
							else if( input.gamepads_vec[i].left_y_dir_axis == 1)
							{
								inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::DOWN_RIGHT;
							}
						}
						//if no move
						else
						{
							if( input.gamepads_vec[i].left_y_dir_axis == -1)
							{
								inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::UP;
							}
							else if( input.gamepads_vec[i].left_y_dir_axis == 1)
							{
								inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::DOWN;
							}
						}
						
						if(input.gamepads_vec[i].left_x_dir_axis == 0 
							&& input.gamepads_vec[i].left_y_dir_axis == 0)
						{
							inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::NONE;
						}
						
						//react to input 
						
						//To do:
						//check for sequential input
						//check for timed input i.e. steps happened within 2 seconds of each other.
						//check if 2 buttons held together
						//Up arrow
						//	-Move closer to opponent
						//	-double press in an attack.
						//Left and right arrow
						//	-separate, side step
						//	-together, no movement
						//Back arrow
						//	-Move away from opponent
						//	-together with left or right, guard
						
						switch(inputReactor.seq_steps_array[inputReactor.current_index])
						{
							//single arrows
							case InputArrows::LEFT:{rigidBody.velocity.x = speed_factor; break;}
							case InputArrows::RIGHT:{rigidBody.velocity.x = -speed_factor; break;}
							case InputArrows::UP:
							{
								//To do: check for previous up arrow for attack and time
								
								//else move if not attacking
								rigidBody.velocity.z = speed_factor;
								
								break;
							}
							case InputArrows::DOWN:{rigidBody.velocity.z = -speed_factor; break;}
							
							
							//combo arrows
							case InputArrows::UP_LEFT:{break;}
							case InputArrows::UP_RIGHT:{break;}
							case InputArrows::UP_DOWN:{break;}
							
							case InputArrows::DOWN_LEFT:{break;}
							case InputArrows::DOWN_RIGHT:{break;}
							
							case InputArrows::LEFT_RIGHT:{ rigidBody.velocity.x = 0.0f; rigidBody.velocity.z = 0.0f; break;}
							
							//none
							case InputArrows::NONE:{rigidBody.velocity.x = 0.0f; rigidBody.velocity.z = 0.0f; break;}
						}
						
						
					}
					
				}
				
				
				break;
			}
			default:{break;}
		}
		
	}
}
