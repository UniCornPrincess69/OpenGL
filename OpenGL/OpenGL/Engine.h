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

#pragma region WindowVariables
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
#pragma endregion

#pragma region CameraVariables

	const glm::vec3 M_CAMERA_POS = glm::vec3(0.0f, 0.0f, 350.0f); 
	const glm::vec3 M_CAMERA_ORIENT = glm::vec3(0.0f, 0.0f, -1.0f); 
	const glm::vec3 M_CAMERA_UP = glm::vec3(0.0f, 1.0f, 0.0f);

#pragma endregion

#pragma region MovementVariables

	const glm::vec3 M_FORWARD = glm::vec3(0.0f, 0.0f, -1.0f);
	const glm::vec3 M_BACKWARD = glm::vec3(0.0f, 0.0f, 1.0f);
	const glm::vec3 M_RIGHT = glm::vec3(0.1f, 0.0f, 0.0f);
	const glm::vec3 M_LEFT = glm::vec3(-0.1f, 0.0f, 0.0f);

#pragma endregion

#pragma region ShaderVariables
	const char* M_S_CAM_NAME = "camMatrix";
	const char* M_S_AMBIENT = "ambientVec";
	const char* M_S_LIGHTPOS = "lightPos";
	const char* M_S_LIGHTVEC = "lightVec";
	const char* M_S_OBJECT_VEC = "objectVec";
	const char* M_S_VERTEX_PATH = "Resource Files/Shader/VertexShader.glsl";
	const char* M_S_FRAGMENT_PATH = "Resource Files/Shader/FragmentShader.glsl";

	const float M_F_LIGHT_POS_X = 0.0f;
	const float M_F_LIGHT_POS_Y = 0.0f;
	const float M_F_LIGHT_POS_Z = 5.0f;

	const float M_F_LIGHT_VEC_X = 60.0f;
	const float M_F_LIGHT_VEC_Y = 60.0f;
	const float M_F_LIGHT_VEC_Z = 60.0f;

	const float M_F_OBJECT_VEC_X = 1.0f;
	const float M_F_OBJECT_VEC_Y = 0.5f;
	const float M_F_OBJECT_VEC_Z = 0.31f;
#pragma endregion


	std::vector<Texture> m_texture = {
		Texture{new unsigned(0),"2D", "Resource Files/Textures/PyramidTex.jpg"},
		Texture{new unsigned(1),"Normal", "Resource Files/Textures/NormalMap.jpg"}
	};

	std::vector<Texture> m_skyTexture = {
		Texture{new unsigned(2), "UP", "Resource Files/Textures/up.jpg"},
		Texture{new unsigned(3), "DOWN", "Resource Files/Textures/down.jpg"},
		Texture{new unsigned(4), "FRONT", "Resource Files/Textures/front.jpg"},
		Texture{new unsigned(5), "BACK", "Resource Files/Textures/back.jpg"},
		Texture{new unsigned(6), "RIGHT", "Resource Files/Textures/right.jpg"},
		Texture{new unsigned(7), "LEFT", "Resource Files/Textures/left.jpg"}
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


