#pragma once
#include "D3dclass.h"
#include "Modelclass.h"

#include <directxmath.h>
using namespace DirectX;

class GameObject
{
public:
	GameObject();
	~GameObject();

	bool Init(ID3D11Device* device);
	void ShutDown();
	bool Render(ID3D11DeviceContext* deviceContext, ID3D11Device* device);

	void Tick();

	void SetPos(float x, float y, float z);
	XMFLOAT3 getPos();

	float y;

private:
	//ModelClass* m_triangle;
	XMFLOAT3 m_pos;


};