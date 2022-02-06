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
						
						if(input.gamepads_vec[i].left_x_dir_axis == -1)
						{
							rigidBody.velocity.x = speed_factor;
						}
						else if( input.gamepads_vec[i].left_x_dir_axis == 1 )
						{
							rigidBody.velocity.x = -speed_factor;
						}
						else
						{
							rigidBody.velocity.x = 0.0f;
						}
						
						if( input.gamepads_vec[i].left_y_dir_axis == -1)
						{
							rigidBody.velocity.z = speed_factor;
						}
						else if( input.gamepads_vec[i].left_y_dir_axis  == 1)
						{
							rigidBody.velocity.z = -speed_factor;
						}
						else
						{
							rigidBody.velocity.z = 0.0f;
						}
						
					}
					
				}
				
				
				break;
			}
			default:{break;}
		}
		
	}
}
