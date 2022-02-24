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

static float circ_radius_max = 10.0f;
static float circ_radius_min = 1.0f;

void UpdatePlayerPositionFromInput(float& dt)
{
	Vector3 old_p1_pos = *p1_pos_ptr;
	Vector3 old_p2_pos = *p2_pos_ptr;
	
	//assuming player 1 and player 2 have properly initialized polar radians angle
	
	//std::cout << "old p1 pos: " << old_p1_pos.x << " , " << old_p1_pos.z << std::endl;
	//std::cout << "old p2 pos: " << old_p2_pos.x << " , " << old_p2_pos.z << std::endl;
	
	//find circle radius
	float xdist = old_p1_pos.x - old_p2_pos.x;
	float zdist = old_p1_pos.z - old_p2_pos.z;
	float circ_radius = sqrtf( pow(xdist,2) + pow(zdist,2) );
	
	//change angle if sidestep
	
	*p1_polar_rad_angle_ptr += p1_vel_ptr->z*rad_angle_change_rate*dt;
	if(*p1_polar_rad_angle_ptr > 2*PI){*p1_polar_rad_angle_ptr = 0.0f;}
	else if(*p1_polar_rad_angle_ptr < 0.0f){*p1_polar_rad_angle_ptr = 2*PI;}
	
	*p2_polar_rad_angle_ptr += p1_vel_ptr->z*rad_angle_change_rate*dt;
	if(*p2_polar_rad_angle_ptr > 2*PI ){*p2_polar_rad_angle_ptr = 0.0f;}
	else if(*p2_polar_rad_angle_ptr < 0.0f){*p2_polar_rad_angle_ptr = 2*PI;}
	
	//std::cout << "p1 polar rad angle: " << *p1_polar_rad_angle_ptr << std::endl;
	//std::cout << "p2 polar rad angle: " << *p2_polar_rad_angle_ptr << std::endl;
	
	//change circle radius if move close or farther
	
	float p1_sidestep_dir_factor = -1*cos(*p1_polar_rad_angle_ptr)*p1_vel_ptr->x; //factor to increase or decrease magnitude based on angular position of player in polar circle
	
	//std::cout << "p1_vel_ptr->x: " << p1_vel_ptr->x << std::endl;
	
	//std::cout << "p1 sidestep factor: " << p1_sidestep_dir_factor << std::endl;

	circ_radius += (p1_sidestep_dir_factor)*radius_change_rate*dt;
	
	if(circ_radius <= circ_radius_min){circ_radius = circ_radius_min;}
	else if(circ_radius >= circ_radius_max){circ_radius = circ_radius_max;}
	//std::cout << "circle radius: " << circ_radius << std::endl;
	
	//move player to new coordinates centered around the other player
	bool moving = false;
	if(p1_vel_ptr->x || p1_vel_ptr->z){moving = true;}
	
	if(moving)
	{
		p1_pos_ptr->x = circ_radius*cos(*p1_polar_rad_angle_ptr) + old_p2_pos.x;
		p1_pos_ptr->z = circ_radius*sin(*p1_polar_rad_angle_ptr) + old_p2_pos.z;
	}
	
	//std::cout << "new p1 pos: " << p1_pos_ptr->x << " , " << p1_pos_ptr->z  << "\n\n";
	
	xdist = p1_pos_ptr->x - old_p2_pos.x;
	zdist = p1_pos_ptr->z - old_p2_pos.z;
	circ_radius = sqrtf( pow(xdist,2) + pow(zdist,2) );
	
	
	*p2_polar_rad_angle_ptr += p2_vel_ptr->z*rad_angle_change_rate*dt;
	if(*p2_polar_rad_angle_ptr > 2*PI ){*p2_polar_rad_angle_ptr = 0.0f;}
	else if(*p2_polar_rad_angle_ptr < 0.0f){*p2_polar_rad_angle_ptr = 2*PI;}
	
	*p1_polar_rad_angle_ptr += p2_vel_ptr->z*rad_angle_change_rate*dt;
	if(*p1_polar_rad_angle_ptr > 2*PI ){*p1_polar_rad_angle_ptr = 0.0f;}
	else if(*p1_polar_rad_angle_ptr < 0.0f){*p1_polar_rad_angle_ptr = 2*PI;}
	
	//std::cout << "p2 polar rad angle: " << *p2_polar_rad_angle_ptr << std::endl;
	//std::cout << "p1 polar rad angle: " << *p1_polar_rad_angle_ptr << std::endl;
	
	float p2_sidestep_dir_factor = -1*cos(*p2_polar_rad_angle_ptr)*p2_vel_ptr->x; //factor to increase or decrease magnitude based on angular position of player in polar circle
	//std::cout << "p2_vel_ptr->x: " << p2_vel_ptr->x << std::endl;
	//std::cout << "p2 sidestep factor: " << p2_sidestep_dir_factor << std::endl;
	
	circ_radius += (p2_sidestep_dir_factor)*radius_change_rate*dt;
	
	if(circ_radius <= circ_radius_min){circ_radius = circ_radius_min;}
	else if(circ_radius >= circ_radius_max){circ_radius = circ_radius_max;}
	//std::cout << "circle radius: " << circ_radius << std::endl;
	
	moving = false;
	if(p2_vel_ptr->x || p2_vel_ptr->z){moving = true;}
	
	if(moving)
	{
		p2_pos_ptr->x = circ_radius*cos(*p2_polar_rad_angle_ptr) + old_p1_pos.x;
		p2_pos_ptr->z = circ_radius*sin(*p2_polar_rad_angle_ptr) + old_p1_pos.z;
	}
	
	//std::cout << "new p2 pos: " << p2_pos_ptr->x << " , " << p2_pos_ptr->z  << "\n\n";
	
	//p1_pos_ptr->x += p1_vel_ptr->x * dt;
	//p1_pos_ptr->z += p1_vel_ptr->z * dt;
	
	//p2_pos_ptr->x += p2_vel_ptr->x * dt;
	//p2_pos_ptr->z += p2_vel_ptr->z * dt;
}

void PhysicsSystem::Update(float& dt)
{	
	UpdatePlayerPositionFromInput(dt);
}


