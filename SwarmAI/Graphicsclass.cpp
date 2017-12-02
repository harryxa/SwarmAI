////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_Direct3D = 0;
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

<<<<<<< HEAD
<<<<<<< HEAD
	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position and rotation of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

	//up&down/left&right/rotate
	m_Camera->SetRotation(0.0f, 0.0f, 0.0f);

	//init gameobject
	m_GameObject = new GameObject;
	if (!m_GameObject)
	{
		return false;
	}
	result = m_GameObject->Init(m_Direct3D->GetDevice());
	if (!result)
	{
		return false;
	}

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

=======
>>>>>>> parent of f43c36f... triangle rendering
=======
>>>>>>> parent of f43c36f... triangle rendering
	return true;
}


void GraphicsClass::Shutdown()
{
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
	// Update the rotation variable each frame.
	Movement();
	return true;
}

CameraClass * GraphicsClass::GetCamera()
{
	return m_Camera;
}

bool GraphicsClass::Render(float rotation, float mov)
{
<<<<<<< HEAD
<<<<<<< HEAD
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
	worldMatrix = XMMatrixTranslation(0, mov, 0) * XMMatrixRotationY(rotation);
	
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_GameObject->Render(m_Direct3D->GetDeviceContext(), m_Direct3D->GetDevice());
		
	// Render the model using the color shader.
	result = m_ColorShader->Render(m_Direct3D->GetDeviceContext(), m_GameObject->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}
=======
	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);
>>>>>>> parent of f43c36f... triangle rendering
=======
	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);
>>>>>>> parent of f43c36f... triangle rendering

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}


bool GraphicsClass::Movement()
{
	bool result;
	static float rotation = 0.0f;

	rotation += (float)XM_PI * 0.01f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}	
		
	static float mov = 0.0f;

	mov += (float)1 * 0.01f;
	// Render the graphics scene.
	result = Render(rotation, mov);
	if (!result)
	{
		return false;
	}
}
