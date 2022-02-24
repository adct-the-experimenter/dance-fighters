#include "CameraSystem.h"

#include "core/system.h"

#include "core/coordinator.h"

#include <iostream>

extern Coordinator gCoordinator;


void CameraSystem::Init(CustomCamera* camera,
				std::uint16_t screenWidth, std::uint16_t screenHeight)
{
	main_camera_ptr = camera;
	
	//*main_camera_ptr->GetPointerToCamera() = (Camera3D){(Vector3){-5, 8, -5}, (Vector3){0, 2, 0}, (Vector3){0, 2, 0}, 45, CAMERA_PERSPECTIVE};
	Camera* camera_ptr = main_camera_ptr->GetPointerToCamera();
	camera_ptr->position = (Vector3){ 20.0f, 20.0f, 20.0f }; // Camera position
	camera_ptr->target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera_ptr->up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera_ptr->fovy = 45.0f;                                // Camera field-of-view Y
}

void CameraSystem::Update()
{
	std::uint8_t current_player = 0;
	
	for (auto const& entity : mEntities)
	{
		
		auto& transform = gCoordinator.GetComponent<Transform3D>(entity);
		auto& player = gCoordinator.GetComponent<Player>(entity);
		
		
		//center camera to follow both players
		//if(current_player == 0)
		//{
			//main_camera_ptr->GetPointerToCamera()->target = transform.position;
		//}
		//put camera at halfway point of distance vector made from  2 players positions
		//zoom based on distance between 2 players.
		
		
	}
	
	// Update camera
	UpdateCamera(main_camera_ptr->GetPointerToCamera());      
	
}

