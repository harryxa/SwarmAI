#pragma once

#include "Graphicsclass.h"


class GameObject 
{
public:
	GameObject();
	~GameObject();

	bool Init();

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	XMFLOAT3 GetPosition();
	XMFLOAT3 GetRotation();

	void Render();

private:

	
	GraphicsClass* m_ModelTriangle;

	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	XMMATRIX m_viewMatrix;
};