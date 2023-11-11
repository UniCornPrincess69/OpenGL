#include "Pyramid.h"
#include <glm/glm.hpp>

/// <summary>
/// Method to calculate the Normal, Binormal and Tangent.
/// Inspired by ChatGPT, adjusted to be more modular.
/// </summary>
/// <param name=""></param>
void Pyramid::CalculateNTB(void)
{
    for (int i = 0; i < m_vertices.size(); i += M_I_THREE)
    {
        //Calculation of the edges
        glm::vec3 edge1 = m_vertices[i + M_I_ONE].position - m_vertices[i].position;
        glm::vec3 edge2 = m_vertices[i + M_I_TWO].position - m_vertices[i].position;

        //Calulation of the difference of UVs
        glm::vec2 deltaUV1 = m_vertices[i + M_I_ONE].uv - m_vertices[i].uv;
        glm::vec2 deltaUV2 = m_vertices[i + M_I_TWO].uv - m_vertices[i].uv;

        //Calculate tangent and binormal
        float factor = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
        glm::vec3 tangent = factor * (deltaUV2.y * edge1 - deltaUV1.y * edge2);
        glm::vec3 binormal = factor * (-deltaUV2.x * edge1 + deltaUV1.x * edge2);

        glm::vec3 normal = glm::normalize(glm::cross(edge1, edge2));

        m_vertices[i].normal = normal;
        m_vertices[i].binormal = binormal;
        m_vertices[i].tangent = tangent;
        m_vertices[i + M_I_ONE].normal = normal;
        m_vertices[i + M_I_ONE].binormal = binormal;
        m_vertices[i + M_I_ONE].tangent = tangent;
        m_vertices[i + M_I_TWO].normal = normal;
        m_vertices[i + M_I_TWO].binormal = binormal;
        m_vertices[i + M_I_TWO].tangent = tangent;
    }

}
