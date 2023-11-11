#ifndef PYRAMID_H
#define PYRAMID_H

#include "Variables.h"
#include <vector>

struct Pyramid
{
public:
	Pyramid()
	{
		CalculateNTB();
	}

	inline std::vector<Vertex> GetVertices() { return m_vertices; }
	inline std::vector<unsigned> GetIndices() { return m_indices; }

private:
	void CalculateNTB(void);


	const int M_I_ONE = 1;
	const int M_I_TWO = 2;
	const int M_I_THREE = 3;

	std::vector<Vertex> m_vertices = std::vector<Vertex>{

		Vertex{ glm::vec3(-0.5f, 0.5f,  0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.0f, 0.0f)},
		Vertex{ glm::vec3( 0.5f, 0.5f,  0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(1.0f, 0.0f)},
		Vertex{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.0f, 1.0f)},
		Vertex{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.0f, 1.0f)},
		Vertex{ glm::vec3( 0.5f, 0.5f,  0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(1.0f, 0.0f)},
		Vertex{ glm::vec3( 0.5f, 0.5f, -0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(1.0f, 1.0f)},

		//Back
		Vertex{ glm::vec3(-0.5f,  0.5f, 0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.0f, 0.0f)},
		Vertex{ glm::vec3( 0.5f,  0.5f, 0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(1.0f, 0.0f)},
		Vertex{ glm::vec3( 0.0f, -0.5f, 0.0f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.5f, 1.0f)},

		//Front
		Vertex{ glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.0f, 0.0f)},
		Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(1.0f, 0.0f)},
		Vertex{ glm::vec3( 0.0f, -0.5f,  0.0f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.5f, 1.0f)},
																									
		//Right
		Vertex{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.0f, 0.0f)},
		Vertex{ glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(1.0f, 0.0f)},
		Vertex{ glm::vec3(0.0f, -0.5f,  0.0f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.5f, 1.0f)},

		//Left
		Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.0f, 0.0f)},
		Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(1.0f, 0.0f)},
		Vertex{ glm::vec3( 0.0f, -0.5f,  0.0f), glm::vec3(0.988f, 0.788f, 0.243f), glm::vec2(0.5f, 1.0f)}
	};

	std::vector<unsigned> m_indices = std::vector<unsigned>{
		0, 1, 2,
		2, 1, 3,
	};
};

#endif // !PYRAMID_H

