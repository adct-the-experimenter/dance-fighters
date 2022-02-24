#include "PhysicsSystem.h"

#include "core/system.h"

#include "core/coordinator.h"

#include "misc/level_maps.h"
#include <iostream>
#include <cmath> //for rounding
#include <array>

extern Coordinator gCoordinator;

static Vector3* p1_vel_ptr;
static Vector3* p2_vel_ptr;

static Vector3* p1_pos_ptr;
static Vector3* p2_pos_ptr;

static float* p1_polar_rad_angle_ptr;
static float* p2_polar_rad_angle_ptr;


void PhysicsSystem::Init()
{
	//assuming first 2 entities are players
	size_t iterator = 0;
	
	for (auto const& entity : mEntities)
	{
		auto& rigidBody = gCoordinator.GetComponent<RigidBody3D>(entity);
		auto& transform = gCoordinator.GetComponent<Transform3D>(entity);
		
		if(iterator == 0)
		{
			p1_pos_ptr = &transform.position;
			p1_vel_ptr = &rigidBody.velocity;
			p1_polar_rad_angle_ptr = &transform.polar_rad_angle;
		}
		else if(iterator == 1)
		{
			p2_pos_ptr = &transform.position;
			p2_vel_ptr = &rigidBody.velocity;
			p2_polar_rad_angle_ptr = &transform.polar_rad_angle;
		}
		
		iterator++;
	}
}

//rate at which polar radial angle of polar coordinates of player is changed
static float rad_angle_change_rate = PI;

//rate at which radius of polar coordinates of player is changed
static float radius_change_rate = 20.0f;

static float circ_radius_barrier = 10.0f;

void PhysicsSystem::Update(float& dt)
{
	
	
	Vector3 old_p1_pos = *p1_pos_ptr;
	Vector3 old_p2_pos = *p2_pos_ptr;
	
	//assuming player 1 and player 2 have properly initialized polar radians angle
	
	//std::cout << "old p1 pos: " << old_p1_pos.x << " , " << old_p1_pos.z << std::endl;
	
	//find circle radius
	float xdist = old_p1_pos.x - old_p2_pos.x;
	float zdist = old_p1_pos.z - old_p2_pos.z;
	float circ_radius = sqrtf( pow(xdist,2) + pow(zdist,2) );
	
	//change angle if sidestep
	
	*p1_polar_rad_angle_ptr += p1_vel_ptr->z*rad_angle_change_rate*dt;
	
	if(*p1_polar_rad_angle_ptr >= 2*PI || *p1_polar_rad_angle_ptr <= -2*PI){*p1_polar_rad_angle_ptr = 0.0f;}
	
	//std::cout << "p1 polar rad angle: " << *p1_polar_rad_angle_ptr << std::endl;
	
	//change circle radius if move close or farther
	
	float sidestep_dir_factor = -1*cos(*p1_polar_rad_angle_ptr)*p1_vel_ptr->x; //factor to increase or decrease direction based on angular position of player in polar circle
	
	circ_radius += sidestep_dir_factor*radius_change_rate*dt;
	
	if(circ_radius <= 0){circ_radius = 0;}
	else if(circ_radius >= circ_radius_barrier){circ_radius = circ_radius_barrier;}
	//std::cout << "circle radius: " << circ_radius << std::endl;
	//std::cout << "p1_vel_ptr->x: " << p1_vel_ptr->x << std::endl;
	
	//move player to new coordinates centered around the other player
	
	p1_pos_ptr->x = circ_radius*cos(*p1_polar_rad_angle_ptr) + p2_pos_ptr->x;
	p1_pos_ptr->z = circ_radius*sin(*p1_polar_rad_angle_ptr) + p2_pos_ptr->z;
	
	//std::cout << "new p1 pos: " << p1_pos_ptr->x << " , " << p1_pos_ptr->z  << "\n\n";
	
	//p1_pos_ptr->x += p1_vel_ptr->x * dt;
	//p1_pos_ptr->z += p1_vel_ptr->z * dt;
	
	p2_pos_ptr->x += p2_vel_ptr->x * dt;
	p2_pos_ptr->z += p2_vel_ptr->z * dt;
	
}


