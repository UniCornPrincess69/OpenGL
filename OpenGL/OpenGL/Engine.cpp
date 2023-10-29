#include "Engine.h"
#include <iostream>



void CEngine::ProcessNode(aiNode* a_pNode, const aiScene* a_pScene)
{
	for (int i = 0; i < a_pNode->mNumMeshes; i++)
	{
		aiMesh* pMesh = a_pScene->mMeshes[a_pNode->mMeshes[i]];
		if (m_pMesh == nullptr) m_pMesh = ProcessMesh(pMesh, a_pScene);

	}

	for (int i = 0; i < a_pNode->mNumChildren; i++)
	{
		ProcessNode(a_pNode->mChildren[i], a_pScene);
	}
}

CMesh* CEngine::ProcessMesh(aiMesh* a_pMesh, const aiScene* a_pScene)
{
	std::vector<Vertex> vertices = {};
	std::vector<unsigned> indices = {};
	std::vector<Texture> textures = {};

	for (int i = 0; i < a_pMesh->mNumVertices; i++)
	{
		vertices.push_back(Vertex{ glm::vec3(a_pMesh->mVertices[i].x, a_pMesh->mVertices[i].y, a_pMesh->mVertices[i].z),
								  glm::vec3(1.0f, 1.0f, 1.0f),
								  glm::vec2(a_pMesh->mTextureCoords[0][i].x, a_pMesh->mTextureCoords[0][i].y),
								  glm::vec3(a_pMesh->mNormals[i].x, a_pMesh->mNormals[i].y, a_pMesh->mNormals[i].z) });
	}

	for (int i = 0; i < a_pMesh->mNumFaces; i++)
	{
		aiFace face = a_pMesh->mFaces[i];
		for (int i = 0; i < face.mNumIndices; i++)
		{
			indices.push_back(face.mIndices[i]);
		}
	}

	if (a_pMesh->mMaterialIndex >= 0)
	{
		aiMaterial* pMat = a_pScene->mMaterials[a_pMesh->mMaterialIndex];
		std::vector<Texture> diffuseMaps = m_pLoader->LoadMaterialTexture(pMat, aiTextureType_DIFFUSE, "texture_diffuse", m_sTextureDir);
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

		std::vector<Texture> specularMaps = m_pLoader->LoadMaterialTexture(pMat, aiTextureType_SPECULAR, "texture_specular", m_sTextureDir);
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}

	return new CMesh(vertices, indices, textures);
}

void CEngine::Awake(void)
{
	if (m_pLoader != nullptr)
	{
		const aiScene* pScene = m_pLoader->LoadMesh(M_S_MESH_PATH);
		ProcessNode(pScene->mRootNode, pScene);
	}
}

int CEngine::Initialize(void)
{



	if (m_pCamera == nullptr) m_pCamera = new CCamera(M_I_WIDTH, M_I_HEIGHT, glm::vec3(0.0f, 0.0f, 250.0f), glm::vec3(0.0f, 0.0f, -0.5f), glm::vec3(0.0f, 1.0f, 0.0f));

	if (m_pViewport == nullptr) m_pViewport = new CViewport(M_I_WIDTH, M_I_HEIGHT, M_I_MINOR, M_I_MAJOR, M_S_NAME, M_F_RED, M_F_GREEN, M_F_BLUE, M_F_ALPHA);
	//if (m_pMaterial == nullptr) m_pMaterial = new CMaterial(m_pDataManager , "Resource Files/Shader/DefaultVertex.glsl", "Resource Files/Shader/DefaultFragment.glsl");
	//if (m_pPhong == nullptr) m_pPhong = new CMaterial(m_pDataManager, "Resource Files/Shader/PhongVertex.glsl", "Resource Files/Shader/PhongFragment.glsl");
	if (m_pBlinn == nullptr) m_pBlinn = new CMaterial(m_pDataManager, "Resource Files/Shader/BlinnPhongVertex.glsl", "Resource Files/Shader/BlinnPhongFragment.glsl");
	if (m_pMesh != nullptr) m_pMesh->SetMaterial(m_pBlinn);
	//if (m_pMesh == nullptr) m_pMesh = new CMesh(m_vertices, m_indices);

	if (m_pViewport != nullptr && m_pCamera != nullptr)
	{
		m_pViewport->SetWInput([&](void) {m_pCamera->TranslatePosition(glm::vec3(0.0f, 0.0f, -1.0f)); });
		m_pViewport->SetAInput([&](void) {m_pCamera->TranslatePosition(glm::vec3(-0.1f, 0.0f, 0.0f)); });
		m_pViewport->SetSInput([&](void) {m_pCamera->TranslatePosition(glm::vec3(0.0f, 0.0f, 1.0f)); });
		m_pViewport->SetDInput([&](void) {m_pCamera->TranslatePosition(glm::vec3(0.1f, 0.0f, 0.0f)); });
	}


	//if (m_pAmbient == nullptr) m_pAmbient = new CMaterial(m_pDataManager, "Resource Files/Shader/AmbientVertex.glsl", "Resource Files/Shader/AmbientFragment.glsl");
	if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Initialize());
	//if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Initialize());
	//if (m_pPhong != nullptr) PROVE_RESULT(m_pPhong->Initialize());
	if (m_pBlinn != nullptr) PROVE_RESULT(m_pBlinn->Initialize());
	if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Initialize());
	//if (m_pAmbient != nullptr) m_pAmbient->AddUniformVector3(M_S_AMBIENT, 0.5f, 0.5f, 0.5f);
	//if (m_pAmbient != nullptr) PROVE_RESULT(m_pAmbient->Initialize());


	return 0;
}

int CEngine::Run(void)
{
	while (!glfwWindowShouldClose(m_pViewport->GetWindow()))
	{
		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Update());
		//if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Update());
		//if (m_pAmbient != nullptr) PROVE_RESULT(m_pAmbient->Update());
		//if (m_pPhong != nullptr) PROVE_RESULT(m_pPhong->Update());
		if (m_pBlinn != nullptr) PROVE_RESULT(m_pBlinn->Update());
		if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Update());

		if (m_pCamera != nullptr) m_pCamera->SetData(CameraData{ M_F_FOV_DEGREE, M_F_NEAR_PLANE, M_F_FAR_PLANE, m_pBlinn->GetShaderProgram(), M_S_CAM_NAME });
		if (m_pCamera != nullptr) PROVE_RESULT(m_pCamera->Update());

		if (m_pCamera != nullptr) PROVE_RESULT(m_pCamera->Draw());
		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->Draw());
		//if (m_pMaterial != nullptr) PROVE_RESULT(m_pMaterial->Draw());
		//if (m_pAmbient != nullptr) PROVE_RESULT(m_pAmbient->Draw());
		//if (m_pPhong != nullptr) m_pPhong->AddUniformVector3("lightPos", 0.0f, 0.0f, 50.0f);
		//if (m_pPhong != nullptr) m_pPhong->AddUniformVector3("lightVec", 2.0f, 2.0f, 2.0f);
		//if (m_pPhong != nullptr) m_pPhong->AddUniformVector3("objectVec", 1.0f, 0.5f, 0.31f);
		//if (m_pPhong != nullptr) PROVE_RESULT(m_pPhong->Draw());
		if (m_pBlinn != nullptr) m_pBlinn->AddUniformVector3("lightPos", 0.0f, 0.0f, 50.0f);
		if (m_pBlinn != nullptr) m_pBlinn->AddUniformVector3("lightVec", 2.0f, 2.0f, 2.0f);
		if (m_pBlinn != nullptr) m_pBlinn->AddUniformVector3("objectVec", 1.0f, 0.5f, 0.31f);
		if (m_pBlinn != nullptr) PROVE_RESULT(m_pBlinn->Draw());
		if (m_pMesh != nullptr) PROVE_RESULT(m_pMesh->Draw());


		if (m_pViewport != nullptr) PROVE_RESULT(m_pViewport->LateDraw());
	}

	return 0;
}

void CEngine::Finalize(void)
{
	FINALIZE_DELETE(m_pMesh);
	//FINALIZE_DELETE(m_pAmbient);
	//FINALIZE_DELETE(m_pMaterial);
	//FINALIZE_DELETE(m_pPhong);
	FINALIZE_DELETE(m_pBlinn);
	FINALIZE_DELETE(m_pViewport);
	FINALIZE_DELETE(m_pCamera);
}
