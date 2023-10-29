#include "Camera.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


const int CCamera::Initialize(void)
{
    m_view = glm::mat4x4(1.0f);
    m_projection = glm::mat4x4(1.0f);

    return 0;
}

const int CCamera::Update(void)
{
   

    m_view = glm::lookAt(m_position, m_position + m_orientation, m_up);
    m_projection = glm::perspective(glm::radians(m_data.fFOVDegree), static_cast<float>(m_iWidth / m_iHeight), m_data.fNearPlane, m_data.fFarPlane);


    return 0;
}

const int CCamera::Draw(void)
{
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, m_data.sName), 1, GL_FALSE, glm::value_ptr(m_projection * m_view));
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, "projection"), 1, GL_FALSE, glm::value_ptr(m_projection));
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, "view"), 1, GL_FALSE, glm::value_ptr(m_view));
    return 0;
}

void CCamera::Finalize(void)
{
}
