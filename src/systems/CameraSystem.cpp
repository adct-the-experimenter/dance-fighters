#include "CameraSystem.h"

#include "core/system.h"

#include "core/coordinator.h"

#include <iostream>

extern Coordinator gCoordinator;


void CameraSystem::Init(CustomCamera* camera,
				std::uint16_t screenWidth, std::uint16_t screenHeight)
{
	m_camera_ptr = camera;
		
	m_camera_ptr->camera_rect.width = screenWidth;
	m_camera_ptr->camera_rect.height = screenHeight;
	
	
}

void CameraSystem::Update()
{
	std::uint8_t current_player = 0;
	
	for (auto const& entity : mEntities)
	{
		
		auto& transform = gCoordinator.GetComponent<Transform2D>(entity);
		auto& player = gCoordinator.GetComponent<Player>(entity);
		
		
		//center camera position with player
		//15 is half of the width of the player character
		//45 is half of the player's width
		
		m_camera_ptr->camera_rect.x = (transform.position.x + 15) - (m_camera_ptr->camera_rect.width / 2);
		m_camera_ptr->camera_rect.y = (transform.position.y + 45) - (m_camera_ptr->camera_rect.height / 2);
		
		
		//bounds check
		if(m_camera_ptr->camera_rect.x < 0)
		{
			m_camera_ptr->camera_rect.x = 0;
		}
		
		if(m_camera_ptr->camera_rect.y < 0)
		{
			m_camera_ptr->camera_rect.y = 0;
		}
		
		/*
		std::cout << "Player " << int(player.num_player) << " , Camera(x,y): " << m_cameras_ptr->at(player.num_player - 1).camera_rect.x << "," 
		<< m_cameras_ptr->at(player.num_player - 1).camera_rect.y << " Player transform(x,y): " << 
		transform.position.x << "," << transform.position.y << std::endl;
		*/
		
	}
	
}

