////////////////////////////////////////////////////////////////////////////////

// Filename: main.cpp

//Create the system class and then initialise it.
//If it initialises with no problems then we call the system class Run function.
//The Run function will run its own loop and do all the application code until it completes.
//After the Run function finishes we then shut down the system object and do the clean up of the system object.
//The entire application has been encapsulated inside the system class.

////////////////////////////////////////////////////////////////////////////////
#include "Systemclass.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	SystemClass* System;
	bool result;


	// Create the system object.
	System = new SystemClass;
	if (!System)
	{
		return 0;
	}

	// Initialize and run the system object.
	result = System->Initialize();
	if (result)
	{
		System->Run();
	}

	// Shutdown and release the system object.
	System->Shutdown();
	delete System;
	System = 0;

	return 0;
}