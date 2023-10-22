#include "Material.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "ErrorType.h"

const char* szVertexShader = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n\0";

const char* szFragmentShader = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(1.0f, 0.5f, 0.2f, 0.1f);\n"
"}\n\0";

unsigned iShaderProgram = 0;


const int CMaterial::Initialize(void)
{
	//Material

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
	iShaderProgram = glCreateProgram();
	glAttachShader(iShaderProgram, iVertexShader);
	glAttachShader(iShaderProgram, iFragmentShader);
	glLinkProgram(iShaderProgram);
	glGetProgramiv(iShaderProgram, GL_LINK_STATUS, &iSuccess);

	if (!iSuccess)
	{
		glGetProgramInfoLog(iShaderProgram, 512, nullptr, sInfoLog);
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
	glUseProgram(iShaderProgram);
	return 0;
}

void CMaterial::Finalize(void)
{
	glDeleteProgram(iShaderProgram);
}
