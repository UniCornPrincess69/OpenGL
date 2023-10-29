#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <assimp/scene.h>
#include <vector>
#include "ErrorType.h"
#include "Variables.h"

class CModelLoader
{
	const unsigned LoadTextureFromFile(const char* a_sPath, const std::string& a_sDir);

public:
	inline const E_ERROR_TYPE GetErrorCode(void) { return m_error; }

	const aiScene* LoadMesh(const std::string& a_sDir);
	const std::vector<Texture> LoadMaterialTexture(aiMaterial* a_pMat, aiTextureType a_type, std::string a_sType, std::string a_sDir);


private:
	E_ERROR_TYPE m_error = E_ERROR_TYPE::ET_SUCCESS;


	const int M_I_TEXTURE_SIZE = 1;
};


#endif // !MODEL_LOADER_H
