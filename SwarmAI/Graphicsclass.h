#pragma once

#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_

<<<<<<< HEAD
#include "D3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "colorshaderclass.h"
#include "GameObject.h"
=======

//////////////
// INCLUDES //
//////////////
#include "d3dclass.h"

>>>>>>> parent of f43c36f... triangle rendering

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	CameraClass* GetCamera();
	

private:
	bool Render(float rotation, float mov);

	bool Movement();

	D3DClass* m_Direct3D;
<<<<<<< HEAD
	CameraClass* m_Camera;
	ModelClass* m_Model;
	ColorShaderClass* m_ColorShader;
	GameObject* m_GameObject;
	
=======
>>>>>>> parent of f43c36f... triangle rendering

};

#endif