#ifndef ENGINE_H
#define ENGINE_H

#include "Viewport.h"
#include "Material.h"
#include "Mesh.h"
#include "Defines.h"
#include "Utils.h"
#include "DataManager.h"
#include "Camera.h"
#include "Pyramid.h"
#include "Skybox.h"

class CEngine
{
public:
	inline CEngine(CDataManager* a_pDataManager)
		: m_pDataManager(a_pDataManager)
	{
		Awake();
	}
private:

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
	const char* M_S_MESH_PATH = "Resource Files\Model\eyeball.obj";


	


	std::vector<Texture> m_texture = {
		Texture{0,"2D", "Resource Files/Textures/PyramidTex.jpg"}
	};


	CDataManager* m_pDataManager = nullptr;

	Pyramid* m_pPyramid = nullptr;
	CSkybox* m_pSkybox = nullptr;
	CViewport* m_pViewport = nullptr;
	CMaterial* m_pBlinn = nullptr;
	CMesh* m_pMesh = nullptr;
	CCamera* m_pCamera = nullptr;
	std::string m_sTextureDir = "";

};

#endif // !ENGINE_H


