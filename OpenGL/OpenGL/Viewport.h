#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Object.h"
#include "ErrorType.h"
#include "Variables.h"
#include <vector>
#include <string>
#include <functional>



class CViewport : IObject
{
public:
	inline CViewport(int a_iWidth, int a_iHeight, int a_iMinor, int a_iMajor, std::string a_sTitle, 
					float a_fRed, float a_fGreen, float a_fBlue, float a_fAlpha)
			:	m_iWidth{a_iWidth}, m_iHeight{a_iHeight}, m_iMinor{a_iMinor}, m_iMajor{a_iMajor}, m_sTitle {a_sTitle},
				m_fRed{a_fRed}, m_fGreen{a_fGreen}, m_fBlue{a_fBlue}, m_fAlpha{a_fAlpha}
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_iMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_iMinor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_pWindow = glfwCreateWindow(m_iWidth, m_iHeight, m_sTitle.c_str(), nullptr, nullptr);
	}
	inline GLFWwindow* GetWindow(void) { return m_pWindow; }

	void SetWInput(std::function<void(void)> a_pInputW);
	void SetAInput(std::function<void(void)> a_pInputA);
	void SetSInput(std::function<void(void)> a_pInputS);
	void SetDInput(std::function<void(void)> a_pInputD);

	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;
	const int LateDraw(void);

private:
	GLFWwindow* m_pWindow = nullptr;
	E_ERROR_TYPE m_error = E_ERROR_TYPE::ET_SUCCESS;

	
	

	int m_iWidth = 0;
	int m_iHeight = 0;
	int m_iMinor = 0;
	int m_iMajor = 0;
	std::string m_sTitle = "";
	float m_fRed = 0.0f;
	float m_fGreen = 0.0f;
	float m_fBlue = 0.0f;
	float m_fAlpha = 0.0f;
};


#endif // !VIEWPORT_H


