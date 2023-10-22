#ifndef MATERIAL_H
#define MATERIAL_H
#include "Object.h"

class CMaterial : public IObject
{
public:
	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;

};

#endif // !MATERIAL_H


