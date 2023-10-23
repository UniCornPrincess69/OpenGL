#ifndef ENGINE_H
#define ENGINE_H

#include "Viewport.h"
#include "Material.h"
#include "Mesh.h"
#include "Defines.h"
#include "Utils.h"
#include "DataManager.h"
#include "Ambient.h"

class CEngine
{
public:
	CEngine(CDataManager* a_pDataManager)
		: m_pDataManager{a_pDataManager}
	{}
	
	int Initialize(void);
	int Run(void);
	void Finalize(void);


private:
	const int M_I_MAJOR = 3;
	const int M_I_MINOR = 3;
	const int M_I_WIDTH = 640;
	const int M_I_HEIGHT = 480;

	const float M_F_RED = 0.949f;
	const float M_F_GREEN = 0.298f;
	const float M_F_BLUE = 1.0f;
	const float M_F_ALPHA = 1.0f;

	const char* M_S_NAME = "Unicorn Engine";

	CDataManager* m_pDataManager = nullptr;
	CViewport* m_pViewport = nullptr;
	//CMaterial* m_pMaterial = nullptr;
	CAmbient* m_pAmbient = nullptr;
	CMesh* m_pMesh = nullptr;

	std::vector<glm::vec3> m_pVertices = std::vector<glm::vec3> {
			glm::vec3(- 0.9f, -1.0f, 0.0f), //links
			glm::vec3(0.0f, -1.0f, 0.0f),	//rechts
			glm::vec3(-0.45f, 0.0f, 0.0f),	//oben

			glm::vec3(0.0f, -1.0f, 0.0f),
			glm::vec3(0.9f, -1.0f, 0.0f),
			glm::vec3(0.45f, 0.0f, 0.0f),

			glm::vec3(-0.45f, 0.0f, 0.0f),
			glm::vec3(0.45f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f)
	};

	const char* m_szVertexShader = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\n\0";

	const char* m_szFragmentShader = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(0.8f, 1.0f, 0.5f, 0.1f);\n"
		"}\n\0";
};

#endif // !ENGINE_H


