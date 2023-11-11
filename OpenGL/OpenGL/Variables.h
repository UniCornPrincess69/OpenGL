#ifndef VARIABLES_H
#define VARIABLES_H

#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include <string>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 uv;
	glm::vec3 normal;
	glm::vec3 tangent;
	glm::vec3 binormal;
};

struct CameraData
{
	float fFOVDegree;
	float fNearPlane;
	float fFarPlane;
	unsigned* pShaderID;
	const char* sName;
};

struct Texture
{
	unsigned iID;
	std::string sType;
	std::string sPath;
};

struct Transform
{
	glm::vec3 position;
	glm::vec3 scale;

};


#endif // !VARIABLES_H

