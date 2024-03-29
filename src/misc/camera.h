#ifndef CAMERA_H
#define CAMERA_H

#include <cstdint>
#include "raylib.h"

class CustomCamera
{
	
public:

	void Init()
	{
		// Define the camera to look into our 3d world
		camera = { 0 };
		camera.position = (Vector3){ 20.0f, 20.0f, 20.0f }; // Camera position
		camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
		camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
		camera.fovy = 45.0f;                                // Camera field-of-view Y
		camera.type = CAMERA_PERSPECTIVE;                   // Camera mode type
	}
	
	Camera3D* GetPointerToCamera()
	{
		return &camera;
	}
	
	Camera3D& GetReferenceToCamera()
	{
		return camera;
	}
	
private:

	Camera3D camera;
	
};


#endif
