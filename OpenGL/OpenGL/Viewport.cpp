#include "Viewport.h"
#include <iostream>

const int M_I_OFFSET_X = 0;
const int M_I_OFFSET_Y = 0;

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
}

const int CViewport::Initialize(void)
{
	if (m_pWindow == nullptr)
	{
		m_error = ErrorType::ET_WINDOW_CREATION_FAILED;
		std::cout << "ERROR: GLFW Window Creation failed!" << std::endl;
		glfwTerminate();
		return static_cast<int>(m_error);
	}
	glfwMakeContextCurrent(m_pWindow);
	glfwSetFramebufferSizeCallback(m_pWindow, HandleFramebufferSize);

	//GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		m_error = ErrorType::ET_GLAD_INITIALISATION_FAILED;
		std::cout << "ERROR: GLAD Initialisation failed" << std::endl;
		return static_cast<int>(m_error);
	}
	
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
	glClear(GL_COLOR_BUFFER_BIT);

	
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
