#ifndef MATERIAL_H
#define MATERIAL_H
#include "Object.h"

class CMaterial : public IObject
{
public:
	CMaterial(const char* a_szVertexShader, const char* a_szFragmentShader)
		: m_szVertexShader{a_szVertexShader}, m_szFragmentShader{a_szFragmentShader}, m_pShaderProgram(new unsigned(M_I_EMPTY))
	{}
protected:
	unsigned* GetShaderProgram(void) { return m_pShaderProgram; }

public:
	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;

private:
	const int M_I_EMPTY = 0;

	const char* m_szVertexShader = "";
	const char* m_szFragmentShader = "";

	unsigned* m_pShaderProgram = nullptr;

};

#endif // !MATERIAL_H


