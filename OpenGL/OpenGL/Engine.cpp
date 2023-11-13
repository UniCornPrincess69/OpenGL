#include "Engine.h"
#include <iostream>


void CEngine::Awake(void)
{
}

int CEngine::Initialize(void)
{

	
	if (m_pPyramid == nullptr) m_pPyramid = new Pyramid();
	//if (m_pSkybox == nullptr) m_pSkybox = new CSkybox(m_pDataManager, m_skyTexture);

	if (m_pCamera == nullptr) m_pCamera = new CCamera(M_I_WIDTH, M_I_HEIGHT, M_CAMERA_POS, M_CAMERA_ORIENT, M_CAMERA_UP);

	if (m_pViewport == nullptr) m_pViewport = new CViewport(M_I_WIDTH, M_I_HEIGHT, M_I_MINOR, M_I_MAJOR, M_S_NAME, M_F_RED, M_F_GREEN, M_F_BLUE, M_F_ALPHA);
	if (m_pMaterial == nullptr) m_pMaterial = new CMaterial(m_pDataManager, M_S_VERTEX_PATH, M_S_FRAGMENT_PATH);
	if (m_pMesh == nullptr) m_pMesh = new CMesh(m_pPyramid->GetVertices(), m_pPyramid->GetIndices(), m_texture);
	if (m_pMesh != nullptr) m_pMesh->SetMaterial(m_pMaterial);

	if (m_pViewport != nullptr && m_pCamera != nullptr)
	{
		m_pViewport->SetWInput([&](void) {m_pCamera->TranslatePosition(M_FORWARD); });
		m_pViewport->SetAInput([&](void) {m_pCamera->TranslatePosition(M_LEFT); });
		m_pViewport->SetSInput([&](void) {m_pCamera->TranslatePosition(M_BACKWARD); });
		m_pViewport->SetDInput([&](void) {m_pCamera->TranslatePosition(M_RIGHT); });
	}
	
	//if (m_pSkybox != nullptr) PROVE_RESULT(m_pSkybox->Initialize());
	if (m_pCamera != nullptr) PROVE_RESULT(m_pCamera->Initialize());
	if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Initialize());
	if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Initialize());
	if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Initialize());


	return 0;
}

int CEngine::Run(void)
{
	while (!glfwWindowShouldClose(m_pViewport->GetWindow()))
	{
		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Update());
		if (m_pPyramid != nullptr) m_pPyramid->CalculateNTB();
		if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Update());
		if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Update());

		if (m_pCamera != nullptr) m_pCamera->SetData(CameraData{ M_F_FOV_DEGREE, M_F_NEAR_PLANE, M_F_FAR_PLANE, m_pMaterial->GetShaderProgram(), M_S_CAM_NAME });
		if (m_pCamera != nullptr) PROVE_RESULT(m_pCamera->Update());

		if (m_pCamera != nullptr) PROVE_RESULT(m_pCamera->Draw());
		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Draw());
		if (m_pMaterial != nullptr) m_pMaterial->AddUniformVector3(M_S_LIGHTPOS, M_F_LIGHT_POS_X, M_F_LIGHT_POS_Y, M_F_LIGHT_POS_Z);
		if (m_pMaterial != nullptr) m_pMaterial->AddUniformVector3(M_S_LIGHTVEC, M_F_LIGHT_VEC_X, M_F_LIGHT_VEC_Y, M_F_LIGHT_VEC_Z);
		if (m_pMaterial != nullptr) m_pMaterial->AddUniformVector3(M_S_OBJECT_VEC, M_F_OBJECT_VEC_X, M_F_OBJECT_VEC_Y, M_F_OBJECT_VEC_Z);
		if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Draw());
		//if (m_pSkybox != nullptr) PROVE_RESULT(m_pSkybox->Draw());
		if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Draw());


		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->LateDraw());
	}

	return 0;
}

void CEngine::Finalize(void)
{
	FINALIZE_DELETE(m_pMesh);
	FINALIZE_DELETE(m_pMaterial);
	FINALIZE_DELETE(m_pViewport);
	FINALIZE_DELETE(m_pCamera);
	//FINALIZE_DELETE(m_pSkybox);
	SAFE_DELETE(m_pPyramid);
}
