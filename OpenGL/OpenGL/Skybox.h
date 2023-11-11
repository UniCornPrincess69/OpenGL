#ifndef SKYBOX_H
#define SKYBOX_H

#include "Variables.h"
#include <vector>
#include "Object.h"
#include "DataManager.h"
#include "ErrorType.h"
#include <iostream>


class CSkybox : IObject
{
public:
	CSkybox(CDataManager* a_pLoader) : m_pVAO(new unsigned(M_I_EMPTY)), m_pVBO(new unsigned(M_I_EMPTY))
	{
		m_sVertex = a_pLoader->ReadFile(m_sVertexPath);
		m_sFragment = a_pLoader->ReadFile(m_sFragmentPath);
	}

private:
	const int InitCubeMap(void);
	const int InitShader(void);
	


public:
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;

private:
	const unsigned M_I_EMPTY = 0;

	std::vector<Texture> m_texture = {
		Texture{0, "UP", "Resource Files/Textures/up.jpg"},
		Texture{1, "DOWN", "Resource Files/Textures/down.jpg"},
		Texture{2, "FRONT", "Resource Files/Textures/front.jpg"},
		Texture{3, "BACK", "Resource Files/Textures/back.jpg"},
		Texture{4, "RIGHT", "Resource Files/Textures/right.jpg"},
		Texture{5, "LEFT", "Resource Files/Textures/left.jpg"}
	};

	std::vector<Vertex> m_vertices = {
		Vertex{glm::vec3(-1.0f, 1.0f, -1.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f, -1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
		Vertex{glm::vec3(1.0f, 1.0f, -1.0f)},
		Vertex{glm::vec3(-1.0f, 1.0f, -1.0f)},

		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f, -1.0f)},
		Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},
		Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},
		Vertex{glm::vec3(-1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
       
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f,  1.0f, -1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},

		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
		Vertex{glm::vec3(-1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f,  1.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},

		Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},
		Vertex{glm::vec3(1.0f,  1.0f, -1.0f)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(-1.0f,  1.0f,  1.0f)},
		Vertex{glm::vec3(-1.0f,  1.0f, -1.0f)},

		Vertex{glm::vec3(-1.0f, -1.0f, -1.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f, -1.0f)},
		Vertex{glm::vec3(-1.0f, -1.0f,  1.0f)},
		Vertex{glm::vec3(1.0f, -1.0f,  1.0f)}
	};
	unsigned m_pCubeMapTexture = 0;
	unsigned* m_pShaderProgram = nullptr;
	unsigned* m_pVAO = nullptr;
	unsigned* m_pVBO = nullptr;

	const char* m_sVertexPath = "Resource Files/Shader/SkyboxVertex.glsl";
	const char* m_sFragmentPath = "Resource Files/Shader/SkyboxFragment.glsl";
	E_ERROR_TYPE m_error = E_ERROR_TYPE::ET_SUCCESS;

	std::string m_sVertex = "";
	std::string m_sFragment = "";
};


#endif // !SKYBOX_H


