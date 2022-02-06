#include "PhysicsSystem.h"

#include "core/system.h"

#include "core/coordinator.h"

#include "misc/level_maps.h"
#include <iostream>
#include <cmath> //for rounding
#include <array>

extern Coordinator gCoordinator;


void PhysicsSystem::Init()
{
	
}


void PhysicsSystem::Update(float& dt)
{
	
	for (auto const& entity : mEntities)
	{
		auto& rigidBody = gCoordinator.GetComponent<RigidBody3D>(entity);
		auto& transform = gCoordinator.GetComponent<Transform3D>(entity);
		auto& physics_type_comp = gCoordinator.GetComponent<PhysicsTypeComponent>(entity);
		//auto& collisionBox = gCoordinator.GetComponent<CollisionBox>(entity);
		
		// Forces
		auto const& gravity = gCoordinator.GetComponent<Gravity3D>(entity);
		
		switch(physics_type_comp.phy_type)
		{
			case PhysicsType::FIGHTING_GAME:
			{
				//have z axis movement move up or down in circle
				//have x axis movement move left or right
				
				//move transform component by velocity of rigid body multiplied by time
				transform.position.x += rigidBody.velocity.x*dt;
				transform.position.z += rigidBody.velocity.z * dt;
				
				
				
				break;
			}
			default:{break;}
		}
		
	}
	
}


