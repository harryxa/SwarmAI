#pragma once

#ifndef _MODELCLASS_H_
#define _MODELCLASS_H_

#include <d3d11.h>
#include <directxmath.h>
using namespace DirectX;

//fstram library, to handle reading from the model text file
#include <fstream>
using namespace std;

class ModelClass
{
private:

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};

	//struct ModelType
	//{
	//	float x, y, z;
	//	float a, b, c, d;		
	//};

public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*, char*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();
	bool InitializeBuffers(ID3D11Device*, int y);

private:
	
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	//bool LoadModel(char*);
	//void ReleaseModel();

	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;

	//ModelType* m_model;
	
};

#endif

