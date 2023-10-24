#include "Material.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "ErrorType.h"



const int CMaterial::Initialize(void)
{
	//Material
	const char* szVertexShader = m_szVertexShader.c_str();
	const char* szFragmentShader = m_szFragmentShader.c_str();


	//Vertex Shader
	unsigned iVertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(iVertexShader, 1, &szVertexShader, nullptr);
	glCompileShader(iVertexShader);

	int iSuccess = 0;
	char sInfoLog[512];

	glGetShaderiv(iVertexShader, GL_COMPILE_STATUS, &iSuccess);

	if (!iSuccess)
	{
		glGetShaderInfoLog(iVertexShader, 512, nullptr, sInfoLog);
		std::cout << "Error: Vertex-Shader Compilation failed!" << std::endl;
		return static_cast<int>(ErrorType::ET_VERTEX_SHADER_COMPILATION_FAILED);
	}

	//Fragment Shader
	unsigned iFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(iFragmentShader, 1, &szFragmentShader, nullptr);
	glCompileShader(iFragmentShader);
	glGetShaderiv(iFragmentShader, GL_COMPILE_STATUS, &iSuccess);

	if (!iSuccess)
	{
		glGetShaderInfoLog(iFragmentShader, 512, nullptr, sInfoLog);
		std::cout << "Error: Fragment-Shader Compilation failed!" << std::endl;
		return static_cast<int>(ErrorType::ET_FRAGMENT_SHADER_COMPILATION_FAILED);
	}

	//Link Shaders
	*m_pShaderProgram = glCreateProgram();
	glAttachShader(*m_pShaderProgram, iVertexShader);
	glAttachShader(*m_pShaderProgram, iFragmentShader);
	glLinkProgram(*m_pShaderProgram);
	glGetProgramiv(*m_pShaderProgram, GL_LINK_STATUS, &iSuccess);

	if (!iSuccess)
	{
		glGetProgramInfoLog(*m_pShaderProgram, 512, nullptr, sInfoLog);
		std::cout << "Error: Shader Program Link failed!" << std::endl;
		return static_cast<int>(ErrorType::ET_SHADER_PROGRAM_LINK_FAILED);
	}

	glDeleteShader(iVertexShader);
	glDeleteShader(iFragmentShader);

    return 0;
}

const int CMaterial::Update(void)
{
    return 0;
}

const int CMaterial::Draw(void)
{
	glUseProgram(*m_pShaderProgram);
	return 0;
}

void CMaterial::Finalize(void)
{
	glDeleteProgram(*m_pShaderProgram);
}
