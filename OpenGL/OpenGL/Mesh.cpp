#include "Mesh.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

unsigned iVAO = 0;
unsigned iVBO = 0;

const int CMesh::Initialize(void)
{
	float vertices[] = {
		-0.9f, -0.5f, 0.0f, //links
		0.0f, -0.5f, 0.0f,	//rechts
		-0.45f, 0.5f, 0.0f,	//oben

		0.0f, -0.5f, 0.0f,
		0.9f, -0.5f, 0.0f,
		0.45f, 0.5f, 0.0f
	};



	glGenVertexArrays(1, &iVAO);
	glGenBuffers(1, &iVBO);

	glBindVertexArray(iVAO);

	glBindBuffer(GL_ARRAY_BUFFER, iVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);


    
    return 0;
}

const int CMesh::Update(void)
{
    return 0;
}

const int CMesh::Draw(void)
{
	glBindVertexArray(iVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	return 0;
}

void CMesh::Finalize(void)
{
	glDeleteVertexArrays(1, &iVAO);
	glDeleteBuffers(1, &iVBO);

}
