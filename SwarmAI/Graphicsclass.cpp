////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "Graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_Direct3D = 0;
	m_Camera = 0;
	m_Model = 0;
	m_ColorShader = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;


	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position and rotation of the camera.
	m_Camera->SetPosition(8.0f, 8.0f, -25.0f);

	//up&down/left&right/rotate
	m_Camera->SetRotation(0.0f, 0.0f, 0.0f);

	GameObject* obj = 0;
	int posX = 0;
	int posY = 0;

	int row = 10;
	int col = 10;

	//init gameobjects and offsets positions
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			obj = new GameObject();
			obj->SetPos(posX, posY, 0.0f);
			m_gameObjects.push_back(obj);
			posY += 2;
		}
		posY = 0;
		posX += 2;
	}

	m_Model = new ModelClass;
	m_Model->InitializeBuffers(m_Direct3D->GetDevice(), row, col);

	// Create the color shader object.
	m_ColorShader = new ColorShaderClass;
	if (!m_ColorShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_ColorShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}

	return true;
}

void GraphicsClass::Shutdown()
{

	// Release the color shader object.
	if (m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = 0;
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		delete m_gameObjects[i];
		m_gameObjects[i] = 0;
	}

	// Release the model object.
	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}
	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	return;
}

bool GraphicsClass::Frame()
{
	bool result;
		
	Tick();

	result = Render();
	if (!result)
	{
		return false;
	}	
}

void GraphicsClass::Tick()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Tick();

		
	}
	m_Model->updatePositions(m_Direct3D->GetDeviceContext(), m_gameObjects);
}

CameraClass * GraphicsClass::GetCamera()
{
	return m_Camera;
}

bool GraphicsClass::Render()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result;
	
	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	//worldMatrix = XMMatrixRotationY(rotation);
	//worldMatrix = XMMatrixTranslation(0, mov, 0) * XMMatrixRotationY(rotation);
	
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	//m_GameObject->Render(m_Direct3D->GetDeviceContext(), m_Direct3D->GetDevice());
	m_Model->Render(m_Direct3D->GetDeviceContext());
	// Render the model using the color shader.
	result = m_ColorShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetVertexCount(), m_Model->GetInstanceCount(), worldMatrix, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}


