#ifndef MESH_H
#define MESH_H

#include "Object.h"
class CMesh : public IObject
{
public:
	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;
};


#endif // !MESH_H


