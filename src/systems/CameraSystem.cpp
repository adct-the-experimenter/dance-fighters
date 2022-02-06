#include "CameraSystem.h"

#include "core/system.h"

#include "core/coordinator.h"

#include <iostream>

extern Coordinator gCoordinator;


void CameraSystem::Init(CustomCamera* camera,
				std::uint16_t screenWidth, std::uint16_t screenHeight)
{
	main_camera_ptr = camera;
	
	*main_camera_ptr->GetPointerToCamera() = (Camera3D){(Vector3){-5, 8, -5}, (Vector3){0, 2, 0}, (Vector3){0, 2, 0}, 45, CAMERA_PERSPECTIVE};
	
}

void CameraSystem::Update()
{
	std::uint8_t current_player = 0;
	
	for (auto const& entity : mEntities)
	{
		
		auto& transform = gCoordinator.GetComponent<Transform3D>(entity);
		auto& player = gCoordinator.GetComponent<Player>(entity);
		
		
		//center camera to follow both players
		
		//put camera at halfway point of distance vector made from  2 players positions
		//zoom based on distance between 2 players.
		
		
	}
	
	// Update camera
	UpdateCamera(main_camera_ptr->GetPointerToCamera());      
	
}

