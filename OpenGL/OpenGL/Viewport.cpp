#include "Viewport.h"
#include <iostream>

const int M_I_OFFSET_X = 0;
const int M_I_OFFSET_Y = 0;

std::function<void(void)> m_pInputW = nullptr;
std::function<void(void)> m_pInputA = nullptr;
std::function<void(void)> m_pInputS = nullptr;
std::function<void(void)> m_pInputD = nullptr;


void HandleFramebufferSize(GLFWwindow* a_pWindow, int a_iWidth, int a_iHeight)
{
	glViewport(M_I_OFFSET_X, M_I_OFFSET_Y, a_iWidth, a_iHeight);
}


void ProcessInput(GLFWwindow* a_pWindow)
{
	if (glfwGetKey(a_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(a_pWindow, true);
	}

	if (glfwGetKey(a_pWindow, GLFW_KEY_W) == GLFW_PRESS)
	{
		if (m_pInputW != nullptr) m_pInputW();
	}

	if (glfwGetKey(a_pWindow, GLFW_KEY_A) == GLFW_PRESS)
	{
		if (m_pInputA != nullptr) m_pInputA();
	}

	if (glfwGetKey(a_pWindow, GLFW_KEY_S) == GLFW_PRESS)
	{
		if (m_pInputS != nullptr) m_pInputS();
	}

	if (glfwGetKey(a_pWindow, GLFW_KEY_D) == GLFW_PRESS)
	{
		if (m_pInputD != nullptr) m_pInputD();
	}
}

void CViewport::SetWInput(std::function<void(void)> a_pInputW)
{
	m_pInputW = a_pInputW;
}

void CViewport::SetAInput(std::function<void(void)> a_pInputA)
{
	m_pInputA = a_pInputA;
}

void CViewport::SetSInput(std::function<void(void)> a_pInputS)
{
	m_pInputS = a_pInputS;
}

void CViewport::SetDInput(std::function<void(void)> a_pInputD)
{
	m_pInputD = a_pInputD;
}

const int CViewport::Initialize(void)
{
	if (m_pWindow == nullptr)
	{
		m_error = E_ERROR_TYPE::ET_WINDOW_CREATION_FAILED;
		std::cout << "ERROR: GLFW Window Creation failed!" << std::endl;
		glfwTerminate();
		return static_cast<int>(m_error);
	}
	glfwMakeContextCurrent(m_pWindow);
	glfwSetFramebufferSizeCallback(m_pWindow, HandleFramebufferSize);


	//GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		m_error = E_ERROR_TYPE::ET_GLAD_INITIALISATION_FAILED;
		std::cout << "ERROR: GLAD Initialisation failed" << std::endl;
		return static_cast<int>(m_error);
	}
	
	glEnable(GL_DEPTH_TEST);
	return static_cast<int>(m_error);
}

const int CViewport::Update(void)
{
	ProcessInput(m_pWindow);
	return static_cast<int>(m_error);
}

const int CViewport::Draw(void)
{
	glClearColor(m_fRed, m_fGreen, m_fBlue, m_fAlpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
	return static_cast<int>(m_error);
}

void CViewport::Finalize(void)
{
	glfwTerminate();
}

const int CViewport::LateDraw(void)
{
	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();

	return static_cast<int>(m_error);
}
