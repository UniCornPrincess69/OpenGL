#include "Mesh.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Defines.h"


const int CMesh::Initialize(void)
{

	glGenVertexArrays(M_I_BUFFER_SIZE, m_pVBO);
	glBindVertexArray(*m_pVBO);


	glGenBuffers(M_I_BUFFER_SIZE, m_pVBO);
	glBindBuffer(GL_ARRAY_BUFFER, *m_pVBO);

	glGenBuffers(M_I_BUFFER_SIZE, m_pEBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *m_pEBO);

	glBufferData(GL_ARRAY_BUFFER, (sizeof(Vertex) * m_vertices.size()), &m_vertices[0], GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (sizeof(unsigned) * m_indices.size()), &m_indices.front(), GL_STATIC_DRAW);
	
	glVertexAttribPointer(M_I_POSITION_IDX, GetPositionNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(M_I_EMPTY));
	glEnableVertexAttribArray(M_I_POSITION_IDX);

	glVertexAttribPointer(M_I_COLOR_IDX, GetColorNum(), GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(GetPositionSize()));
	glEnableVertexAttribArray(M_I_COLOR_IDX);

	glBindBuffer(GL_ARRAY_BUFFER, 0);



    
    return 0;
}

const int CMesh::Update(void)
{
    return 0;
}

const int CMesh::Draw(void)
{
	glBindVertexArray(*m_pVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *m_pEBO);

	glDrawArrays(GL_TRIANGLES, M_I_POSITION_IDX, m_vertices.size());
	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, (void*)M_I_EMPTY);

	return 0;
}

void CMesh::Finalize(void)
{
	if (m_pEBO != nullptr) glDeleteBuffers(M_I_BUFFER_SIZE, m_pEBO);
	if (m_pVBO != nullptr) glDeleteVertexArrays(M_I_BUFFER_SIZE, m_pVBO);

}
