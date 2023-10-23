#ifndef MESH_H
#define MESH_H

#include "Object.h"
#include "glm/vec3.hpp"
#include <vector>

class CMesh : public IObject
{
public:
	CMesh(std::vector<glm::vec3> a_pVertices)
		: m_pVertices{ a_pVertices }, m_pVAO(new unsigned(M_I_EMPTY)), m_pVBO(new unsigned(M_I_EMPTY))
	{

	}

	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;

private:
	const int M_I_EMPTY = 0;

	unsigned* m_pVAO = nullptr;
	unsigned* m_pVBO = nullptr;

	std::vector<glm::vec3> m_pVertices = {};
};


#endif // !MESH_H


