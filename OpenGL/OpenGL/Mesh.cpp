#include "Mesh.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Defines.h"


const int CMesh::Initialize(void)
{

	glGenVertexArrays(1, m_pVAO);
	glGenBuffers(1, m_pVBO);

	glBindVertexArray(*m_pVAO);

	glBindBuffer(GL_ARRAY_BUFFER, *m_pVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_pVertices) * (sizeof(glm::vec3) * m_pVertices.size()), &m_pVertices[0], GL_STATIC_DRAW);

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
	glBindVertexArray(*m_pVAO);
	glDrawArrays(GL_TRIANGLES, 0, 9);

	return 0;
}

void CMesh::Finalize(void)
{
	glDeleteVertexArrays(1, m_pVAO);
	glDeleteBuffers(1, m_pVBO);

}
