#ifndef ENGINE_H
#define ENGINE_H

#include "Viewport.h"
#include "Material.h"
#include "Mesh.h"
#include "Defines.h"
#include "Utils.h"

class CEngine
{
public:
	int Initialize(void);
	int Run(void);
	void Finalize(void);


private:
	const int M_I_MAJOR = 3;
	const int M_I_MINOR = 3;
	const int M_I_WIDTH = 640;
	const int M_I_HEIGHT = 480;

	const float M_F_RED = 0.949f;
	const float M_F_GREEN = 0.298f;
	const float M_F_BLUE = 1.0f;
	const float M_F_ALPHA = 1.0f;

	const char* M_S_NAME = "Unicorn Engine";

	CViewport* m_pViewport = nullptr;
	CMaterial* m_pMaterial = nullptr;
	CMesh* m_pMesh = nullptr;
};

#endif // !ENGINE_H


