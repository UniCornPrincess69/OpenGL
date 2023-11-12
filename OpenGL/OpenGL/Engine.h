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

	const float M_F_RED = 0.533f;
	const float M_F_GREEN = 0.788f;
	const float M_F_BLUE = 1.0f;
	const float M_F_ALPHA = 1.0f;
	const float M_F_FOV_DEGREE = 0.45f;
	const float M_F_NEAR_PLANE = 0.1f;
	const float M_F_FAR_PLANE = 1000.0f;

	const char* M_S_NAME = "Unicorn Engine";
	const char* M_S_CAM_NAME = "camMatrix";
	const char* M_S_AMBIENT = "ambientVec";

	const char* M_S_VERTEX_PATH = "Resource Files/Shader/VertexShader.glsl";
	const char* M_S_FRAGMENT_PATH = "Resource Files/Shader/FragmentShader.glsl";


	


	std::vector<Texture> m_texture = {
		Texture{0,"2D", "Resource Files/Textures/PyramidTex.jpg"},
		Texture{1,"Normal", "Resource Files/Textures/NormalMap.jpg"}
	};

	std::vector<Texture> m_skyTexture = {
		Texture{0, "UP", "Resource Files/Textures/up.jpg"},
		Texture{1, "DOWN", "Resource Files/Textures/down.jpg"},
		Texture{2, "FRONT", "Resource Files/Textures/front.jpg"},
		Texture{3, "BACK", "Resource Files/Textures/back.jpg"},
		Texture{4, "RIGHT", "Resource Files/Textures/right.jpg"},
		Texture{5, "LEFT", "Resource Files/Textures/left.jpg"}
	};


	CDataManager* m_pDataManager = nullptr;

	Pyramid* m_pPyramid = nullptr;
	CSkybox* m_pSkybox = nullptr;
	CViewport* m_pViewport = nullptr;
	CMaterial* m_pMaterial = nullptr;
	CMesh* m_pMesh = nullptr;
	CCamera* m_pCamera = nullptr;
	std::string m_sTextureDir = "";

};

#endif // !ENGINE_H


