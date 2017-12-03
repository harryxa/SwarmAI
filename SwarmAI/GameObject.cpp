#include "GameObject.h"

GameObject::GameObject()
{
	m_triangle = 0;
	y = 0;
}

GameObject::~GameObject()
{
}

bool GameObject::Init(ID3D11Device* device)
{
	bool result;

	m_triangle = new ModelClass;
	if (!m_triangle)
	{
		return false;
	}
	result = m_triangle->Initialize(device, "../SwarmAI/cube.txt");
	
	if (!result)
	{
		return false;
	}
	return true;
}

void GameObject::ShutDown()
{
	if (m_triangle)
	{
		m_triangle->Shutdown();
		delete m_triangle;
		m_triangle = 0;
	}
}


bool GameObject::Render(ID3D11DeviceContext* deviceContext, ID3D11Device* device)
{
	
	y = y + 0.01f;

	m_triangle->InitializeBuffers(device, y);
	m_triangle->Render(deviceContext);
	return true;
}

ModelClass* GameObject::getModel()
{
	return m_triangle;
}

int GameObject::GetIndexCount()
{
	return m_triangle->GetIndexCount();
}




