#ifndef MESH_H
#define MESH_H

#include "Object.h"
#include "Variables.h"
#include <vector>

class CMesh : public IObject
{
public:
	CMesh(std::vector<Vertex> a_vertices, std::vector<unsigned> a_indices)
		: m_vertices{ a_vertices }, m_indices {a_indices},
		m_pVBO(new unsigned(M_I_EMPTY)), m_pEBO(new unsigned(M_I_EMPTY))
	{}

private:
	inline constexpr const int GetPositionSize(void) const { return sizeof(glm::vec3); }

	inline constexpr const int GetPositionNum(void) const { return GetPositionSize() / sizeof(float); }
	inline constexpr const int GetColorNum(void) const { return sizeof(glm::vec3) / sizeof(float); }

public:
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

	unsigned* m_pVBO = nullptr;
	unsigned* m_pEBO = nullptr;

	std::vector<Vertex> m_vertices = {};
	std::vector<unsigned> m_indices = {};
};


#endif // !MESH_H


