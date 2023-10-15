#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>




void HandleFramebufferSize(GLFWwindow* a_pWindow, int a_iWidth, int a_iHeight)
{
	glViewport(0, 0, a_iWidth, a_iHeight);
}


void ProcessInput(GLFWwindow* a_pWindow)
{
	if (glfwGetKey(a_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(a_pWindow, true);
	}
}

int main(int a_iArgV, const char* a_argsC[])
{

#pragma region Initialize
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Window
	GLFWwindow* pWindow = glfwCreateWindow(640, 480, "Unicorn Engine", nullptr, nullptr);
	if (pWindow == nullptr)
	{
		std::cout << "ERROR: GLFW Window Creation failed!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(pWindow);
	glfwSetFramebufferSizeCallback(pWindow, HandleFramebufferSize);

	//GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: GLAD Initialisation failed" << std::endl;
		return -2;
	}
#pragma endregion

#pragma region Run
	while (!glfwWindowShouldClose(pWindow))
	{
		ProcessInput(pWindow);
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(pWindow);
		glfwPollEvents();
	}
#pragma endregion

#pragma region Finalize
	glfwTerminate();
#pragma endregion
	return 0;
}