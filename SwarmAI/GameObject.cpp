#include "GameObject.h"

GameObject::GameObject()
{
	m_triangle = 0;
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
	result = m_triangle->Initialize(device, "../SwarmAI/triangle.txt");
	
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


bool GameObject::Render(ID3D11DeviceContext* deviceContext)
{
	m_triangle->Render(deviceContext);
	return true;
}

int GameObject::GetIndexCount()
{
	return m_triangle->GetIndexCount();
}


