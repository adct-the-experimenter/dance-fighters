
#ifndef INPUT_REACTOR_SYSTEM_H
#define INPUT_REACTOR_SYSTEM_H

#include "core/system.h"

#include "core/ControllerInput.h"

class InputReactorSystem : public System
{
public:

	void Update(ControllerInput& input);
	
	//function to keep track of time for arrows registered
	void TrackTime(double& dt);
};

#endif
