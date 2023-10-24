#ifndef VARIABLES_H
#define VARIABLES_H

#include "glm/vec3.hpp"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
};

struct CameraData
{
	float fFOVDegree;
	float fNearPlane;
	float fFarPlane;
	unsigned* pShaderID;
	const char* sName;
};


#endif // !VARIABLES_H

