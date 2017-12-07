#include "GameObject.h"

GameObject::GameObject()
{
	y = 0;
}

GameObject::~GameObject()
{
}

bool GameObject::Init(ID3D11Device* device)
{
	bool result;
	return true;
}

void GameObject::ShutDown()
{
	
}

void GameObject::SetPos(float x, float y, float z)
{
	m_pos = XMFLOAT3(x, y, z);
}

XMFLOAT3 GameObject::getPos()
{
	return m_pos;
}

bool GameObject::Render(ID3D11DeviceContext* deviceContext, ID3D11Device* device)
{
	return true;
}

void GameObject::Tick()
{
	m_pos.x += 0.05;
	//m_pos.y += 0.05;
}




