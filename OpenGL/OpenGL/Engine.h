#ifndef ENGINE_H
#define ENGINE_H

#include "Viewport.h"
#include "Material.h"
#include "Mesh.h"
#include "Defines.h"
#include "Utils.h"
#include "DataManager.h"
#include "Camera.h"
#include "ModelLoader.h"

class CEngine
{
public:
	inline CEngine(CDataManager* a_pDataManager, CModelLoader* a_pLoader)
		: m_pDataManager(a_pDataManager), m_pLoader(a_pLoader)
	{
		Awake();
	}
private:
	void ProcessNode(aiNode* a_pNode, const aiScene* a_pScene);
	CMesh* ProcessMesh(aiMesh* a_pMesh, const aiScene* a_pScene);

	void Awake(void);

public:
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
	const float M_F_FOV_DEGREE = 0.45f;
	const float M_F_NEAR_PLANE = 0.1f;
	const float M_F_FAR_PLANE = 1000.0f;

	const char* M_S_NAME = "Unicorn Engine";
	const char* M_S_CAM_NAME = "camMatrix";
	const char* M_S_AMBIENT = "ambientVec";
	const char* M_S_MESH_PATH = "Resource Files\Models\TreasureChest.obj";


	std::vector<Vertex> m_vertices = std::vector<Vertex>{
		
		Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
		Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) , glm::vec3(0.0f, 0.0f, -1.0f)},
		Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) , glm::vec3(0.0f, 0.0f, -1.0f)},
		Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) , glm::vec3(0.0f, 0.0f, -1.0f)},
		Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
		Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},

		Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) , glm::vec3(0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) , glm::vec3(0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) , glm::vec3(0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
		Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},

		Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f ), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f ), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f ), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f ), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f ), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f ), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},

		Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
		Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},

		Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
		Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) , glm::vec3(0.0f, -1.0f, 0.0f)},
		Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) , glm::vec3(0.0f, -1.0f, 0.0f)},
		Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) , glm::vec3(0.0f, -1.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},

		Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
		Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
		Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
		Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
		Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)}

		//Top of inverted pyramid
		//Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
		//Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
		//Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
		//Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
		//Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
		//Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

		////Front
		//Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3()},
		//Vertex{glm::vec3(0.5f, 0.5f, 0.5f) , glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec3()},
		//Vertex{glm::vec3(0.25f, 0.0f, 0.25f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f), glm::vec3()},
		//Vertex{glm::vec3(0.25f, 0.0f, 0.25f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f), glm::vec3()},
		//Vertex{glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f), glm::vec3()},
		//Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f), glm::vec3()},

		////Back
		//Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3()},
		//Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec3()},
		//Vertex{glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f), glm::vec3()},

		////Right
		//Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3()},
		//Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec3()},
		//Vertex{glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f), glm::vec3()},

		////Left
		//Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3()},
		//Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f), glm::vec3()},
		//Vertex{glm::vec3(0.0f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.5f, 1.0f), glm::vec3()}
	};

	std::vector<unsigned> m_indices = std::vector<unsigned>{
		0, 1, 2,
		2, 1, 3,
	};

	std::vector<Texture> m_texture = {
		Texture{0, "Resource Files/Texture/default_64x64_f1.jpg"}
	};

	CDataManager* m_pDataManager = nullptr;
	CModelLoader* m_pLoader = nullptr;

	CViewport* m_pViewport = nullptr;
	//CMaterial* m_pMaterial = nullptr;
	//CMaterial* m_pAmbient = nullptr;
	//CMaterial* m_pPhong = nullptr;
	CMaterial* m_pBlinn = nullptr;
	CMesh* m_pMesh = nullptr;
	CCamera* m_pCamera = nullptr;
	std::string m_sTextureDir = "";

};

#endif // !ENGINE_H


