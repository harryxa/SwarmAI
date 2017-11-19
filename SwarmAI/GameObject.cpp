#include "GameObject.h"

GameObject::GameObject()
{
	m_ModelTriangle = 0;
}

GameObject::~GameObject()
{
}

bool GameObject::Init()
{
	m_ModelTriangle = new GraphicsClass;
	if (!m_ModelTriangle)
	{
		return false;
	}
}

void GameObject::SetPosition(float x, float y, float z)
{
	m_positionX = x;
	m_positionY = y;
	m_positionZ = z;
	return;
}


void GameObject::SetRotation(float x, float y, float z)
{
	m_rotationX = x;
	m_rotationY = y;
	m_rotationZ = z;
	return;
}

XMFLOAT3 GameObject::GetPosition()
{
	return XMFLOAT3(m_positionX, m_positionY, m_positionZ);
}


XMFLOAT3 GameObject::GetRotation()
{
	return XMFLOAT3(m_rotationX, m_rotationY, m_rotationZ);
}



