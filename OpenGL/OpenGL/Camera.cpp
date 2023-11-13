#include "Camera.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


const int CCamera::Initialize(void)
{
    m_view = glm::mat4x4(M_F_ONE);
    m_projection = glm::mat4x4(M_F_ONE);
    m_model = glm::mat4x4(M_F_ONE);

    return 0;
}

//Update of the view, projection, and the rotation of the model.
//I looked up the rotation on learnopengl.com
const int CCamera::Update(void)
{
    m_view = glm::lookAt(m_position, m_position + m_orientation, m_up);
    m_projection = glm::perspective(glm::radians(m_data.fFOVDegree), static_cast<float>(m_iWidth / m_iHeight), m_data.fNearPlane, m_data.fFarPlane);
    m_model = glm::rotate(m_model, glm::radians(M_F_HALF), M_ROT_AXIS);

    return 0;
}

const int CCamera::Draw(void)
{
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, m_data.sName), M_F_ONE, GL_FALSE, glm::value_ptr(m_projection * m_view * m_model));
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, M_S_PROJECTION), M_F_ONE, GL_FALSE, glm::value_ptr(m_projection));
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, M_S_VIEW), M_F_ONE, GL_FALSE, glm::value_ptr(m_view));
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, M_S_MODEL), M_F_ONE, GL_FALSE, glm::value_ptr(m_model));
    float time = glfwGetTime();
    glUniform1f(glGetUniformLocation(*m_data.pShaderID, M_S_TIME), time);
    return 0;
}

void CCamera::Finalize(void)
{
}
