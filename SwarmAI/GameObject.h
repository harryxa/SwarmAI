#pragma once
#include "D3dclass.h"
#include "Modelclass.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	bool Init(ID3D11Device* device);
	void ShutDown();
	bool Render(ID3D11DeviceContext* deviceContext, ID3D11Device* device);

	

	float y;

private:
	ModelClass* m_triangle;


};