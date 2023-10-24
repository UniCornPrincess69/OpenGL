#pragma once
#include "Material.h"
#include "glm/vec3.hpp"

class CAmbient :
    public CMaterial
{
public:
	inline CAmbient(CDataManager* a_pDataManager, const char* a_szVertexShader, const char* a_szFragmentShader)
		: CMaterial(a_pDataManager, a_szVertexShader, a_szFragmentShader)
	{}

	inline void SetLightColor(const glm::vec3& a_lightColor) { m_lightColor = a_lightColor; }

	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;

private:
	glm::vec3 m_lightColor = {};

};

