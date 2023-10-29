#ifndef MATERIAL_H
#define MATERIAL_H
#include "Object.h"
#include "DataManager.h"

class CMaterial : public IObject
{
public:
	inline CMaterial(CDataManager* a_pDataManager, const char* a_szVertexShader, const char* a_szFragmentShader)
		: m_pDataManager{a_pDataManager}, m_pShaderProgram(new unsigned(M_I_EMPTY))
	{
		if (m_pDataManager == nullptr) return;
		m_szVertexShader = m_pDataManager->ReadFile(a_szVertexShader);
		m_szFragmentShader = m_pDataManager->ReadFile(a_szFragmentShader);

	}

	void AddUniformVector3(std::string a_sName, float a_fR, float a_fG, float a_fB);
	inline unsigned* GetShaderProgram(void) { return m_pShaderProgram; }

public:
	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;

private:
	const int M_I_EMPTY = 0;

	CDataManager* m_pDataManager = nullptr;

	std::string m_szVertexShader = "";
	std::string m_szFragmentShader = "";

	unsigned* m_pShaderProgram = nullptr;

};

#endif // !MATERIAL_H


