#include "GameObject.h"

GameObject::GameObject()
{
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

bool GameObject::Render(ID3D11DeviceContext* deviceContext, ID3D11Device* device)
{
	return true;
}

void GameObject::Tick()
{
	//m_pos.x += 0.05;
	//m_pos.y += 0.05;

	SetVel(Destination());	

	MovePos(m_vel);
	
}

XMFLOAT3 GameObject::Move()
{
	XMFLOAT3 centre = XMFLOAT3(0, 0, 0);
	XMFLOAT3 move = XMFLOAT3(0,0,0);

	move.x = (centre.x - m_pos.x);	
	move.y = (centre.y - m_pos.y);
	
	return move;	
}

XMFLOAT3 GameObject::Destination()
{
	XMFLOAT3 dest = XMFLOAT3(0, 0, 0);;

	dest.x = (m_vel.x + Move().x) * 0.0005;
	m_vel.x = dest.x;

	dest.y = (m_vel.y + Move().y) * 0.0005;
	m_vel.y = dest.y;

	return dest;
}

void GameObject::SetPos(float x, float y, float z)
{
	m_pos = XMFLOAT3(x, y, z);
}

void GameObject::MovePos(XMFLOAT3 _pos)
{
	m_pos.x += _pos.x;
	m_pos.y += _pos.y;
	m_pos.z += _pos.z;
}

XMFLOAT3 GameObject::getPos()
{
	return m_pos;
}

void GameObject::SetVel(XMFLOAT3 _vel)
{
	m_vel.x += _vel.x;
	m_vel.y += _vel.y;
	m_vel.z += _vel.z;
}

XMFLOAT3 GameObject::GetVel()
{
	return m_vel;
}




