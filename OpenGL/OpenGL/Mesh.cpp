#include "Mesh.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Defines.h"
#include <stb/stb_image.h>
#include <iostream>
#include "ErrorType.h"




std::vector<Vertex> CMesh::TranslateVertices(std::vector<Vertex> a_vertices, Transform* a_pTrans)
{
	if (a_pTrans == nullptr) return a_vertices;

	for (auto&& vert : a_vertices)
	{
		vert.position.x += a_pTrans->position.x;
		vert.position.y += a_pTrans->position.y;
		vert.position.z += a_pTrans->position.z;

		vert.position.x *= a_pTrans->scale.x;
		vert.position.y *= a_pTrans->scale.y;
		vert.position.z *= a_pTrans->scale.z;
	}
	return a_vertices;
}

const int CMesh::InitTextures(void)
{
	int iWidth = 0, iHeight = 0, iChannelNum = 0;
	glUniform1i(glGetUniformLocation(*m_pMaterial->GetShaderProgram(), "PyramidTexture"), 0);
	glUniform1i(glGetUniformLocation(*m_pMaterial->GetShaderProgram(), "NormalMap"), 1);
	for (int i = 0; i < m_textures.size(); i++)
	{
		glGenTextures(1, &m_textures[i].iID);
		glBindTexture(GL_TEXTURE_2D, m_textures[i].iID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);

		unsigned char* pData = stbi_load(m_textures[i].sPath.c_str(), &iWidth, &iHeight, &iChannelNum, 0);
		if (pData)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, iWidth, iHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, pData);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Error: Failed Texture loading" << std::endl;
			return static_cast<int>(E_ERROR_TYPE::ET_FAILED_LOAD_TEXTURE);
		}

		stbi_image_free(pData);
	}
	return static_cast<int>(E_ERROR_TYPE::ET_SUCCESS);
}

void CMesh::InitBuffers(void)
{
	glGenVertexArrays(M_I_BUFFER_SIZE, m_pVBO);
	glBindVertexArray(*m_pVBO);


	glGenBuffers(M_I_BUFFER_SIZE, m_pVBO);
	glBindBuffer(GL_ARRAY_BUFFER, *m_pVBO);

	glGenBuffers(M_I_BUFFER_SIZE, m_pEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *m_pEBO);
}

void CMesh::InitVertices(void)
{
	glBufferData(GL_ARRAY_BUFFER, (sizeof(Vertex) * m_vertices.size()), &m_vertices[0], GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(unsigned) * m_indices.size()), &m_indices.front(), GL_STATIC_DRAW);

	glVertexAttribPointer(M_I_POSITION_IDX, GetPositionNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY));
	glEnableVertexAttribArray(M_I_POSITION_IDX);

	glVertexAttribPointer(M_I_COLOR_IDX, GetColorNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY + GetPositionSize()));
	glEnableVertexAttribArray(M_I_COLOR_IDX);

	glVertexAttribPointer(M_I_UV_COORD_IDX, GetUVCoordNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY + GetPositionSize() + GetColorSize()));
	glEnableVertexAttribArray(M_I_UV_COORD_IDX);

	glVertexAttribPointer(M_I_NORMAL_IDX, GetNormalCoordNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY + GetPositionSize() + GetColorSize() + GetTexCoordSize()));
	glEnableVertexAttribArray(M_I_NORMAL_IDX);

	glVertexAttribPointer(M_I_BINORMAL_IDX, GetBiNormalCoordNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY + GetPositionSize() + GetColorSize() + GetTexCoordSize() + GetNormalSize()));
	glEnableVertexAttribArray(M_I_BINORMAL_IDX);

	glVertexAttribPointer(M_I_TANGENT_IDX, GetTangentCoordNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY + GetPositionSize() + GetColorSize() + GetTexCoordSize() + GetNormalSize() + GetBiNormalSize()));
	glEnableVertexAttribArray(M_I_TANGENT_IDX);
}

void CMesh::SetTransform(Transform& a_trans)
{
	m_pTransform = &a_trans;
	TranslateVertices(m_vertices, m_pTransform);
}

const int CMesh::Initialize(void)
{
	m_model = glm::mat4x4(1.0f);
	
	InitBuffers();

	InitVertices();

	if (m_textures.size() == 0) return static_cast<int>(E_ERROR_TYPE::ET_SUCCESS);
	else return InitTextures();
    
    return 0;
}

const int CMesh::Update(void)
{
    return 0;
}

const int CMesh::Draw(void)
{
	unsigned iDiffuseNumb = 0;
	unsigned iSpecularNumb = 0;
	
	for (int i = 0; i < m_textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);

		std::string sNumb = "";
		std::string sName = m_textures[i].sType;
		
		if (sName == "texture_diffuse") sNumb = std::to_string(iDiffuseNumb++);
		else if (sName == "texture_specular") sNumb = std::to_string(iSpecularNumb++);
		GLint location = glGetUniformLocation((GLuint)*m_pMaterial->GetShaderProgram(), (sName + sNumb).c_str());
		glUniform1i(location, i);

		glBindTexture(GL_TEXTURE_2D, m_textures[i].iID);
	}
	
	glBindVertexArray(*m_pVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *m_pEBO);

	glDrawArrays(GL_TRIANGLES, M_I_POSITION_IDX, m_vertices.size());
	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, (void*)M_I_EMPTY);

	return 0;
}

void CMesh::Finalize(void)
{
	if (m_pEBO != nullptr) glDeleteBuffers(M_I_BUFFER_SIZE, m_pEBO);
	if (m_pVBO != nullptr) glDeleteVertexArrays(M_I_BUFFER_SIZE, m_pVBO);

}
