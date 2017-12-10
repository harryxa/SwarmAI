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
	void MovePos(XMFLOAT3 _pos);
	XMFLOAT3 getPos();

	void SetVel(XMFLOAT3 _vel);
	XMFLOAT3 GetVel();

	XMFLOAT3 Move();

	XMFLOAT3 Destination();
	
private:
	//ModelClass* m_triangle;
	XMFLOAT3 m_pos;

	XMFLOAT3 m_vel = XMFLOAT3(0, 0, 0);
	XMFLOAT3 m_acc = XMFLOAT3(0, 0, 0);


};