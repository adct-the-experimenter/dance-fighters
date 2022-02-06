#include "RenderSystem.h"

#include "core/system.h"

#include "core/coordinator.h"

#include <iostream>

#include <cmath>

extern Coordinator gCoordinator;

#include "misc/level_maps.h"


void RenderSystem::Init(CustomCamera* camera)
{
	m_camera_ptr = camera;
        
}


void RenderSystem::Update()
{
			
	if(this->m_camera_ptr)
	{			
		
		//for every entity
		for (auto const& entity : mEntities)
		{
			auto& render_comp = gCoordinator.GetComponent<RenderModelComponent>(entity);
			auto& transform = gCoordinator.GetComponent<Transform3D>(entity);
			
			//DrawModelEx( render_comp.model, transform.position, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
			DrawModel(render_comp.model, transform.position, 1, WHITE);
		}
		
		
					
	}
		
	
}

