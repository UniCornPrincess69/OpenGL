#include "Engine.h"
#include <iostream>



int CEngine::Initialize(void)
{
	if (m_pViewport == nullptr) m_pViewport = new CViewport(M_I_WIDTH, M_I_HEIGHT, M_I_MINOR, M_I_MAJOR, M_S_NAME, M_F_RED, M_F_GREEN, M_F_BLUE, M_F_ALPHA);
	if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Initialize());
    
	//Material
	if (m_pMaterial == nullptr) m_pMaterial = new CMaterial();
	if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Initialize());

	// Mesh
	if (m_pMesh == nullptr) m_pMesh = new CMesh();
	if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Initialize());

    return 0;
}

int CEngine::Run(void)
{
	while (!glfwWindowShouldClose(m_pViewport->GetWindow()))
	{
		
		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Update());
		if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Update());
		if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Update());
		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Draw());
		if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Draw());
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
}
