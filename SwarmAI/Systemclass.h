#pragma once

#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_

//speeds up build process by reducing the size of Win32 headrer files by excluding certain APIs
#define WIN32_LEAN_AND_MEAN

//call the functions to create / destroy windows and use the other useful win32 functions
#include <windows.h>

#include "inputclass.h"
#include "graphicsclass.h"
#include "GameObject.h"

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	//functions that was called in Main defined here.
	bool Initialize();
	void Shutdown();
	void Run();

	//handle the windows system messages that will get sent to the application while it is running.
	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;

	GameObject* m_GameObject;
};

//used to re-direct the windows system messaging into our MessageHandler function inside the system class.
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static SystemClass* ApplicationHandle = 0;


#endif