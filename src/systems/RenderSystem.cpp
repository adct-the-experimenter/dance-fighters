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

bool IsObjectInCameraView(float& posX, float& posY, Rectangle& camera_rect)
{
	//half the width and height because the camera is centered on a player.
	
	if(posX < camera_rect.x)
	{
		return false;
	}
	else if(posX > camera_rect.x + (camera_rect.width / 2))
	{
		return false;
	}
	
	if(posY < camera_rect.y)
	{
		return false;
	}
	else if(posY > camera_rect.y + (camera_rect.height / 2))
	{
		return false;
	}
	
	return true;
}

Vector3 mapPosition = { -16.0f, 0.0f, -8.0f };  // Set model position

void RenderSystem::Update()
{
			
	if(this->m_camera_ptr)
	{			
		//render texture background color
		ClearBackground(RAYWHITE);
		
		BeginMode3D(this->m_camera_ptr->GetReferenceToCamera());
        
        //draw the stage
        if(main_stage.mapPixels)
        {
			DrawModel(main_stage.model, mapPosition, 1.0f, WHITE); // Draw maze map
		}
        
		//for every entity
		for (auto const& entity : mEntities)
		{
			auto& render_comp = gCoordinator.GetComponent<RenderComponent>(entity);
			auto& transform = gCoordinator.GetComponent<Transform2D>(entity);
			
			//bool renderObjectBool = IsObjectInCameraView(transform.position.x,transform.position.y,m_camera_ptr->camera_rect);
			bool renderObjectBool = true;
			
			//if renderable object is within camera bounds.
			if(renderObjectBool)
			{
				//change render position of renderable object relative to camera
				auto& render_position = gCoordinator.GetComponent<RenderPosition>(entity);
					
				//render_position.overall_position.x = transform.position.x - m_camera_ptr->camera_rect.x;
				render_position.overall_position.x = transform.position.x;
				//render_position.overall_position.y = transform.position.y - m_camera_ptr->camera_rect.y;
				render_position.overall_position.y = transform.position.y;
				
				//render object
				//if not multi part render
				if(!render_comp.multi_part)
				{
					if(render_comp.single_render_part.texture_ptr)
					{
						//adjust render component positions according to overall position
						Vector2 pos = {render_position.overall_position.x + render_comp.single_render_part.position.x,
									  render_position.overall_position.y + render_comp.single_render_part.position.y};
						
						
						DrawTextureRec(*render_comp.single_render_part.texture_ptr, 
										render_comp.single_render_part.frame_rect, 
										pos, 
										render_comp.single_render_part.tint);
					}
				}
				else
				{
					if(render_comp.multi_render_parts_vec[0].texture_ptr)
					{
						//draw collision box for debugging
						//Rectangle collision_rect = {render_position.overall_position.x,render_position.overall_position.y,30,60};
							
						//DrawRectangleRec(collision_rect, RED);
						
						for(int c = render_comp.multi_render_parts_vec.size() - 1; c >= 0; c--)
						{
							//render from last to first to make hair render over head
							
							//adjust render component positions according to overall position
							//for centering to collision box
							Vector2 pos = {render_position.overall_position.x + (render_comp.multi_render_parts_vec[c].position.x / 2),
										  render_position.overall_position.y + (render_comp.multi_render_parts_vec[c].position.y / 2) };
													
							DrawTextureRec(*render_comp.multi_render_parts_vec[c].texture_ptr, 
											render_comp.multi_render_parts_vec[c].frame_rect, 
											pos, 
											render_comp.multi_render_parts_vec[c].tint);
							
							
						}
						
						
					}
				}
			}
		}
		
		EndMode3D();
					
	}
		
	
}

