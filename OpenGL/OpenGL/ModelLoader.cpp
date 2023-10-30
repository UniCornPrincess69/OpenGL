#include "ModelLoader.h"
#include <glad/glad.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <stb/stb_image.h>
#include <iostream>

const unsigned CModelLoader::LoadTextureFromFile(const char* a_sPath, const std::string& a_sDir)
{
    std::string sFilename = a_sDir;
    sFilename.append("/");
    sFilename.append(a_sPath);

    unsigned iTextureID = 0;
    glGenTextures(M_I_TEXTURE_SIZE, &iTextureID);

    int iWidth = 0;
    int iHeight = 0;
    int iChannelNum = 0;

    unsigned char* pData = stbi_load(sFilename.c_str(), &iWidth, &iHeight, &iChannelNum, 0);
    if (pData)
    {
        GLenum format;

        if (iChannelNum == 1) format = GL_RED;
        else if (iChannelNum == 3) format = GL_RGB;
        else if (iChannelNum == 4) format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, iTextureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, iWidth, iHeight, 0, format, GL_UNSIGNED_BYTE, pData);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(pData);
    }
    else
    {
        m_error = E_ERROR_TYPE::ET_FAILED_LOAD_TEXTURE;
        std::cout << "Error: Texture failed loading!" << std::endl;
        return 0;
    }
    
    return iTextureID;
}

const aiScene* CModelLoader::LoadMesh(const std::string& a_sPath)
{
    Assimp::Importer imp;
    const aiScene* pScene = imp.ReadFile(a_sPath, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if (!pScene || pScene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !pScene->mRootNode)
    {
        std::cout << "Error:" << imp.GetErrorString() << std::endl;
        m_error = E_ERROR_TYPE::ET_ASSIMP_MESH_FAILED_READING_FILE;
        return nullptr;
    }
    return pScene;
}

const std::vector<Texture> CModelLoader::LoadMaterialTexture(aiMaterial* a_pMat, aiTextureType a_type, std::string a_sType, std::string a_sDir)
{
    std::vector<Texture> textures = {};

    for (int i = 0; i < a_pMat->GetTextureCount(a_type); i++)
    {
        aiString sPath;
        a_pMat->GetTexture(a_type, i, &sPath);
        textures.push_back(Texture{ LoadTextureFromFile(sPath.C_Str(), a_sDir), a_sType, sPath.C_Str() });
    }

    return textures;
}
