#ifndef ENGINE_H
#define ENGINE_H

#include "Viewport.h"
#include "Material.h"
#include "Mesh.h"
#include "Defines.h"
#include "Utils.h"
#include "DataManager.h"
#include "Ambient.h"
#include "Camera.h"

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


	std::vector<Vertex> m_vertices = std::vector<Vertex> {
			//Vertex{glm::vec3(-0.9f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)}, //links
			//Vertex{glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)},	//rechts
			//Vertex{glm::vec3(-0.45f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)},	//oben
			//
			//Vertex{glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
			//Vertex{glm::vec3(0.9f, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
			//Vertex{glm::vec3(0.45f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
			//
			//Vertex{glm::vec3(-0.45f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
			//Vertex{glm::vec3(0.45f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
			//Vertex{glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)}

			Vertex{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)},
			Vertex{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
			Vertex{glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
			Vertex{glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)}
	};

	std::vector<unsigned> m_indices = std::vector<unsigned>{
		0, 1, 2,
		2, 1, 3,
	};

	CDataManager* m_pDataManager = nullptr;
	CViewport* m_pViewport = nullptr;
	CMaterial* m_pMaterial = nullptr;
	//CAmbient* m_pAmbient = nullptr;
	CMesh* m_pMesh = nullptr;
	CCamera* m_pCamera = nullptr;
};

#endif // !ENGINE_H


