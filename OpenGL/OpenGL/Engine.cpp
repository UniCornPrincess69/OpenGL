#include "Engine.h"
#include <iostream>



int CEngine::Initialize(void)
{
	

	if (m_pDataManager == nullptr) return static_cast<int>(ErrorType::ET_DATA_MANAGER_INIT_FAILED);
	std::string szAmbientVertexShader = m_pDataManager->ReadFile("Resource Files/Shader/AmbientVertex.glsl");
	std::string szAmbientFragmentShader = m_pDataManager->ReadFile("Resource Files/Shader/AmbientFragment.glsl");

	if (m_pCamera == nullptr) m_pCamera = new CCamera(M_I_WIDTH, M_I_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f));

	if (m_pViewport == nullptr) m_pViewport = new CViewport(M_I_WIDTH, M_I_HEIGHT, M_I_MINOR, M_I_MAJOR, M_S_NAME, M_F_RED, M_F_GREEN, M_F_BLUE, M_F_ALPHA);
	if (m_pMaterial == nullptr) m_pMaterial = new CMaterial(m_pDataManager , "Resource Files/Shader/DefaultVertex.glsl", "Resource Files/Shader/DefaultFragment.glsl");
	if (m_pMesh == nullptr) m_pMesh = new CMesh(m_vertices, m_indices);
    
	/*if (m_pViewport != nullptr && m_pCamera != nullptr) 
	{
		m_pInputW = [&](void) {m_pCamera->TranslatePosition(glm::vec3(1.0f, 0.0f, 0.0f)); };
		m_pInputA = [&](void) {m_pCamera->TranslatePosition(glm::vec3(0.0f, 0.0f, -1.0f)); };
		m_pInputS = [&](void) {m_pCamera->TranslatePosition(glm::vec3(-1.0f, 0.0f, 0.0f)); };
		m_pInputD = [&](void) {m_pCamera->TranslatePosition(glm::vec3(0.0f, 0.0f, 1.0f)); };
	}*/


	//if (m_pAmbient != nullptr) m_pAmbient = new CAmbient(szAmbientVertexShader.c_str(), szAmbientFragmentShader.c_str());
	if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Initialize());
	if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Initialize());
	if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Initialize());
	//if (m_pAmbient != nullptr) m_pAmbient->SetLightColor(glm::vec3(0.8f, 0.2f, 0.5f));
	//if (m_pAmbient != nullptr) PROVE_RESULT(m_pAmbient->Initialize());


    return 0;
}

int CEngine::Run(void)
{
	while (!glfwWindowShouldClose(m_pViewport->GetWindow()))
	{
		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Update());
		if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Update());
		//if (m_pAmbient != nullptr) PROVE_RESULT(m_pAmbient->Update());
		if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Update());

		if (m_pCamera != nullptr) m_pCamera->SetData(CameraData{ 0.45f, 0.1f, 1000.0f, m_pMaterial->GetShaderProgram(), "CamMatrix" });
		if (m_pCamera != nullptr) m_pCamera->Update();

		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Draw());
		if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Draw());
		//if (m_pAmbient != nullptr) PROVE_RESULT(m_pAmbient->Draw());
		if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Draw());


		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->LateDraw());
	}
	
	return 0;
}

void CEngine::Finalize(void)
{
	FINALIZE_DELETE(m_pMesh);
	//FINALIZE_DELETE(m_pAmbient);
	FINALIZE_DELETE(m_pMaterial);
	FINALIZE_DELETE(m_pViewport);
}
