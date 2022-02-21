#include "InputReactorSystem.h"

#include "core/system.h"
#include "core/coordinator.h"


extern Coordinator gCoordinator;

float speed_factor = 10.0f;

/*

SDL Controller button enums

SDL_CONTROLLER_BUTTON_INVALID
SDL_CONTROLLER_BUTTON_A
SDL_CONTROLLER_BUTTON_B
SDL_CONTROLLER_BUTTON_X
SDL_CONTROLLER_BUTTON_Y
SDL_CONTROLLER_BUTTON_BACK
SDL_CONTROLLER_BUTTON_GUIDE
SDL_CONTROLLER_BUTTON_START
SDL_CONTROLLER_BUTTON_LEFTSTICK
SDL_CONTROLLER_BUTTON_RIGHTSTICK
SDL_CONTROLLER_BUTTON_LEFTSHOULDER
SDL_CONTROLLER_BUTTON_RIGHTSHOULDER
SDL_CONTROLLER_BUTTON_DPAD_UP
SDL_CONTROLLER_BUTTON_DPAD_DOWN
SDL_CONTROLLER_BUTTON_DPAD_LEFT
SDL_CONTROLLER_BUTTON_DPAD_RIGHT
SDL_CONTROLLER_BUTTON_MAX 

*/


static void ProcessButtonHold(InputReact& inputReactor,ControllerInput::GamepadInfo& gamepad_input)
{
	bool leftHeld = false;
	bool rightHeld = false;
	bool downHeld = false; 
	bool upHeld = false;
	
	//if left button held or down
	if(gamepad_input.button_held_array[SDL_CONTROLLER_BUTTON_DPAD_LEFT] ||
		gamepad_input.button_down == SDL_CONTROLLER_BUTTON_DPAD_LEFT )
	{
		leftHeld = true;
	}
	
	//if right button held or down
	if( gamepad_input.button_held_array[SDL_CONTROLLER_BUTTON_DPAD_RIGHT] ||
		gamepad_input.button_down == SDL_CONTROLLER_BUTTON_DPAD_RIGHT )
	{
		rightHeld = true;
	}
	
	//if down button held or down
	if( gamepad_input.button_held_array[SDL_CONTROLLER_BUTTON_DPAD_DOWN] ||
		gamepad_input.button_down == SDL_CONTROLLER_BUTTON_DPAD_DOWN )
	{
		downHeld = true;
	}
	
	//if up button held or down
	if( gamepad_input.button_held_array[SDL_CONTROLLER_BUTTON_DPAD_UP] ||
		gamepad_input.button_down == SDL_CONTROLLER_BUTTON_DPAD_UP )
	{
		upHeld = true;
	}
	
	//if only left
	if(leftHeld && !rightHeld && !upHeld && !downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::LEFT;
	}
	
	//if only right 
	else if(!leftHeld && rightHeld && !upHeld && !downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::RIGHT;
	}
	
	//if only up
	else if(!leftHeld && !rightHeld && upHeld && !downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::UP;
	}
	
	//if only down
	else if(!leftHeld && !rightHeld && !upHeld && downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::DOWN;
	}
	
	//if only left and up 
	else if(leftHeld && !rightHeld && upHeld && !downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::UP_LEFT;
	}
	
	//if only left and right
	else if(leftHeld && rightHeld && !upHeld && !downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::LEFT_RIGHT;
	}
	
	//if only left and down
	else if(leftHeld && !rightHeld && !upHeld && downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::DOWN_LEFT;
	}
	
	//if only right and up
	else if(!leftHeld && rightHeld && upHeld && !downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::UP_RIGHT;
	}
	
	//if only right and down
	else if(!leftHeld && rightHeld && !upHeld && downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::DOWN_RIGHT;
	}
	
	//if only down and up
	else if(!leftHeld && !rightHeld && upHeld && downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::UP_DOWN;
	}
	
	//if no buttons held
	if(!leftHeld && !rightHeld && !upHeld && !downHeld)
	{
		inputReactor.current_arrows_held = InputArrows::NONE;
	}
}

static void ProcessButtonRelease(InputReact& inputReactor,ControllerInput::GamepadInfo& gamepad_input)
{
	
	//if left button released recently
	if(gamepad_input.button_up_released == SDL_CONTROLLER_BUTTON_DPAD_LEFT)
	{
		inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::LEFT;
	}
	
	//if right button released recently
	else if( gamepad_input.button_up_released == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)
	{
		inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::RIGHT;
	}
	
	//if down button held or down
	else if( gamepad_input.button_up_released == SDL_CONTROLLER_BUTTON_DPAD_DOWN )
	{
		inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::DOWN;
	}
	
	//if up button held or down
	else if( gamepad_input.button_up_released == SDL_CONTROLLER_BUTTON_DPAD_UP )
	{
		inputReactor.seq_steps_array[inputReactor.current_index] = InputArrows::UP;
	}
		
}

static void ProcessInputToArrows(InputReact& inputReactor,ControllerInput::GamepadInfo& gamepad_input)
{
	inputReactor.current_index++;
						
	if(inputReactor.current_index == 4){inputReactor.current_index = 0;}
	
	ProcessButtonHold(inputReactor,gamepad_input);
	ProcessButtonRelease(inputReactor,gamepad_input);
	
}

static void ReactToArrows(InputReact& inputReactor,RigidBody3D& rigidBody)
{
	//To do:
	//check for sequential input
	//check for timed input i.e. steps happened within 2 seconds of each other.
	//check if 2 buttons held together
	
	//attack activation
	
	bool attackModeEnabled = false;
	
	if(inputReactor.seq_steps_array[inputReactor.current_index] == InputArrows::UP)
	{
		//check if previous step input was up arrow
		if(inputReactor.current_index == 0)
		{
			if(inputReactor.seq_steps_array[3] == InputArrows::UP)
			{
				std::cout << "Start attack sequence!\n";
				attackModeEnabled = true;
				
				//reset sequential steps array
				inputReactor.seq_steps_array[0] = InputArrows::NONE;
				inputReactor.seq_steps_array[1] = InputArrows::NONE;
				inputReactor.seq_steps_array[2] = InputArrows::NONE;
				inputReactor.seq_steps_array[3] = InputArrows::NONE;
			}
		}
		else
		{
			if(inputReactor.seq_steps_array[inputReactor.current_index - 1] == InputArrows::UP)
			{
				std::cout << "Start attack sequence!\n";
				attackModeEnabled = true;
				
				//reset sequential steps array
				inputReactor.seq_steps_array[0] = InputArrows::NONE;
				inputReactor.seq_steps_array[1] = InputArrows::NONE;
				inputReactor.seq_steps_array[2] = InputArrows::NONE;
				inputReactor.seq_steps_array[3] = InputArrows::NONE;
			}
		}
		
	}
	
	//guard activation
	
	bool guardModeEnabled = false;
	
	if(inputReactor.seq_steps_array[inputReactor.current_index] == InputArrows::DOWN)
	{
		//check if previous step input was up arrow
		if(inputReactor.current_index == 0)
		{
			if(inputReactor.seq_steps_array[3] == InputArrows::DOWN)
			{
				std::cout << "Start guard mode!\n";
				guardModeEnabled = true;
				
				//reset sequential steps array
				inputReactor.seq_steps_array[0] = InputArrows::NONE;
				inputReactor.seq_steps_array[1] = InputArrows::NONE;
				inputReactor.seq_steps_array[2] = InputArrows::NONE;
				inputReactor.seq_steps_array[3] = InputArrows::NONE;
			}
		}
		else
		{
			if(inputReactor.seq_steps_array[inputReactor.current_index - 1] == InputArrows::DOWN)
			{
				std::cout << "Start guard mode!\n";
				guardModeEnabled = true;
				
				//reset sequential steps array
				inputReactor.seq_steps_array[0] = InputArrows::NONE;
				inputReactor.seq_steps_array[1] = InputArrows::NONE;
				inputReactor.seq_steps_array[2] = InputArrows::NONE;
				inputReactor.seq_steps_array[3] = InputArrows::NONE;
			}
		}
		
	}
	
	//grab activation
	
	bool grabModeEnabled = false;
	
	if(inputReactor.seq_steps_array[inputReactor.current_index] == InputArrows::UP)
	{
		//check if previous step input was down arrow
		
		if(inputReactor.current_index == 0)
		{
			if(inputReactor.seq_steps_array[3] == InputArrows::DOWN)
			{
				std::cout << "Start grab mode!\n";
				grabModeEnabled = true;
				
				//reset sequential steps array
				inputReactor.seq_steps_array[0] = InputArrows::NONE;
				inputReactor.seq_steps_array[1] = InputArrows::NONE;
				inputReactor.seq_steps_array[2] = InputArrows::NONE;
				inputReactor.seq_steps_array[3] = InputArrows::NONE;
			}
		}
		else
		{
			if(inputReactor.seq_steps_array[inputReactor.current_index - 1] == InputArrows::DOWN)
			{
				std::cout << "Start grab mode!\n";
				grabModeEnabled = true;
				
				//reset sequential steps array
				inputReactor.seq_steps_array[0] = InputArrows::NONE;
				inputReactor.seq_steps_array[1] = InputArrows::NONE;
				inputReactor.seq_steps_array[2] = InputArrows::NONE;
				inputReactor.seq_steps_array[3] = InputArrows::NONE;
			}
		}
		
	}
	
	//check buttons held down for movement
	switch(inputReactor.current_arrows_held)
	{
		//single arrows
		case InputArrows::LEFT:{rigidBody.velocity.x = speed_factor; break;}
		case InputArrows::RIGHT:{rigidBody.velocity.x = -speed_factor; break;}
		case InputArrows::UP:
		{
			//Up arrow
			//	-Move closer to opponent
			//	-double press in an attack.
			
			if(!attackModeEnabled && !grabModeEnabled){rigidBody.velocity.z = speed_factor;}
			
			break;
		}
		case InputArrows::DOWN:
		{
			//Back arrow
			//	-Move away from opponent
			//	-together with left or right, guard
			if(!guardModeEnabled && !grabModeEnabled){rigidBody.velocity.z = -speed_factor; }
			break;
		}
		
		
		//combo arrows
		case InputArrows::UP_LEFT:{break;}
		case InputArrows::UP_RIGHT:{break;}
		case InputArrows::UP_DOWN:{break;}
		
		case InputArrows::DOWN_LEFT:{break;}
		case InputArrows::DOWN_RIGHT:{break;}
		
		case InputArrows::LEFT_RIGHT:
		{
			//Left and right arrow
			//	-separate, side step
			//	-together, no movement 
			rigidBody.velocity.x = 0.0f; 
			rigidBody.velocity.z = 0.0f; 
			break;
		}
		
		//none
		case InputArrows::NONE:{rigidBody.velocity.x = 0.0f; rigidBody.velocity.z = 0.0f; break;}
	}
}

void InputReactorSystem::TrackTime(double& dt)
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
				//update time
				inputReactor.time_attack_seq += dt;
				
				//if 2 seconds has passed
				if( inputReactor.time_attack_seq >= 2.5f)
				{
					//reset sequential steps array
					inputReactor.seq_steps_array[0] = InputArrows::NONE;
					inputReactor.seq_steps_array[1] = InputArrows::NONE;
					inputReactor.seq_steps_array[2] = InputArrows::NONE;
					inputReactor.seq_steps_array[3] = InputArrows::NONE;
					
					inputReactor.time_attack_seq = 0.0f;
				}
				
				
				break;
			}
			default:{break;}
		}
		
	}
	
	
}

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
						ProcessInputToArrows(inputReactor,input.gamepads_vec[i]);
						
						//react to input 
						ReactToArrows(inputReactor,rigidBody);
						
					}
					
				}
				
				
				break;
			}
			default:{break;}
		}
		
	}
}
