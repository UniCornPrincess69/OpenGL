#include "Skybox.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

const int CSkybox::InitCubeMap(void)
{
	//TODO: Access violation wenn auf ID zugegriffen werden soll.
	int iWidth, iHeight, iChannelNo;
	for (unsigned i = 0; i < m_texture.size(); i++)
	{
		auto iID = m_texture[i].iID;
		glGenTextures(1, iID);
		glBindTexture(GL_TEXTURE_CUBE_MAP, *iID);
		unsigned char* pData = stbi_load(m_texture[i].sPath.c_str(), &iWidth, &iHeight, &iChannelNo, 0);
		if (pData)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, iWidth, iHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pData);
			stbi_image_free(pData);
		}
		else
		{
			std::cout << "Cubemap could not be loaded at path:" << m_texture[i].sPath << std::endl;
			stbi_image_free(pData);
		}
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	}
	return static_cast<int>(m_error);
}

const int CSkybox::InitShader(void)
{

	const char* szVertex = m_sVertex.c_str();
	const char* szFragment = m_sFragment.c_str();

	//Vertex Shader
	unsigned iVertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(iVertexShader, 1, &szVertex, nullptr);
	glCompileShader(iVertexShader);

	int iSuccess = 0;
	char sInfoLog[512];

	glGetShaderiv(iVertexShader, GL_COMPILE_STATUS, &iSuccess);

	if (!iSuccess)
	{
		glGetShaderInfoLog(iVertexShader, 512, nullptr, sInfoLog);
		std::cout << "Error: Skybox Vertex-Shader Compilation failed!" << std::endl;
		return static_cast<int>(E_ERROR_TYPE::ET_SKYBOX_VERTEX_COMP_FAILED);
	}

	//Fragment Shader
	unsigned iFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(iFragmentShader, 1, &szFragment, nullptr);
	glCompileShader(iFragmentShader);
	glGetShaderiv(iFragmentShader, GL_COMPILE_STATUS, &iSuccess);

	if (!iSuccess)
	{
		glGetShaderInfoLog(iFragmentShader, 512, nullptr, sInfoLog);
		std::cout << "Error: Skybox Fragment-Shader Compilation failed!" << std::endl;
		return static_cast<int>(E_ERROR_TYPE::ET_SKYBOX_FRAGMENT_COMP_FAILED);
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
		return static_cast<int>(E_ERROR_TYPE::ET_SHADER_PROGRAM_LINK_FAILED);
	}

	glDeleteShader(iVertexShader);
	glDeleteShader(iFragmentShader);

	return static_cast<int>(m_error);
}

const int CSkybox::Initialize(void)
{
	m_pCubeMapTexture = InitCubeMap();
	InitShader();

	glGenVertexArrays(1, m_pVAO);
	glGenBuffers(1, m_pVBO);
	glBindVertexArray(*m_pVAO);
	glBindBuffer(GL_ARRAY_BUFFER, *m_pVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_vertices.size(), &m_vertices.front(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	return 0;
}

const int CSkybox::Update(void)
{
	return 0;
}

const int CSkybox::Draw(void)
{
	glUseProgram(*m_pShaderProgram);
	return 0;
}

void CSkybox::Finalize(void)
{
	glDeleteShader(*m_pShaderProgram);
}
