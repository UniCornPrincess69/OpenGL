#ifndef MESH_H
#define MESH_H

#include "Object.h"
#include "Variables.h"
#include <vector>
#include "Material.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CMesh : public IObject
{
public:
	CMesh(std::vector<Vertex> a_vertices, std::vector<unsigned> a_indices, std::vector<Texture> a_textures = {}, Transform* a_pTrans = nullptr)
		: m_vertices(TranslateVertices(a_vertices, a_pTrans)), m_indices(a_indices), m_textures(a_textures), m_pTransform(a_pTrans),
		m_pVBO(new unsigned(M_I_EMPTY)), m_pEBO(new unsigned(M_I_EMPTY))
	{}

private:
	inline constexpr const int GetPositionSize(void) const { return sizeof(glm::vec3); }
	inline constexpr const int GetColorSize(void) const { return sizeof(glm::vec3); }
	inline constexpr const int GetTexCoordSize(void) const { return sizeof(glm::vec2); }
	inline constexpr const int GetNormalSize(void) const { return sizeof(glm::vec3); }
	inline constexpr const int GetBiNormalSize(void) const { return sizeof(glm::vec3); }
	inline constexpr const int GetTangentSize(void) const { return sizeof(glm::vec3); }

	inline constexpr const int GetPositionNum(void) const { return GetPositionSize() / sizeof(float); }
	inline constexpr const int GetColorNum(void) const { return GetColorSize() / sizeof(float); }
	inline constexpr const int GetUVCoordNum(void) const { return GetTexCoordSize() / sizeof(float); }
	inline constexpr const int GetNormalCoordNum(void) const { return GetNormalSize() / sizeof(float); }
	inline constexpr const int GetBiNormalCoordNum(void) const { return GetBiNormalSize() / sizeof(float); }
	inline constexpr const int GetTangentCoordNum(void) const { return GetTangentSize() / sizeof(float); }


	std::vector<Vertex> TranslateVertices(std::vector<Vertex> a_vertices, Transform* a_pTrans);

	const int InitTextures(void);
public:
	inline const Transform* GetTransform(void) const { return m_pTransform; }
	inline void SetMaterial(CMaterial* a_pMat)
	{ 
		if (a_pMat == nullptr) return;
 		m_pMaterial = a_pMat; 
	}
	void InitBuffers(void);
	void InitVertices(void);
	void SetTransform(Transform& a_trans);


	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;

private:
	const int M_I_EMPTY = 0;
	const int M_I_POSITION_IDX = 0;
	const int M_I_COLOR_IDX = 1;
	const int M_I_BUFFER_SIZE = 1;
	const int M_I_UV_COORD_IDX = 2;
	const int M_I_NORMAL_IDX = 3;
	const int M_I_BINORMAL_IDX = 4;
	const int M_I_TANGENT_IDX = 5;

	unsigned* m_pVBO = nullptr;
	unsigned* m_pEBO = nullptr;

	std::vector<Vertex> m_vertices = {};
	std::vector<unsigned> m_indices = {};
	std::vector<Texture> m_textures = {};
	glm::mat4x4 m_model = {};

	CMaterial* m_pMaterial = nullptr;
	Transform* m_pTransform = nullptr;
};


#endif // !MESH_H


