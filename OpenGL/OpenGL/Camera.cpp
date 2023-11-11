#include "Camera.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


const int CCamera::Initialize(void)
{
    m_view = glm::mat4x4(1.0f);
    m_projection = glm::mat4x4(1.0f);
    m_model = glm::mat4x4(1.0f);

    return 0;
}

//Update of the view, projection, and the rotation of the model.
//I looked up the rotation on learnopengl.com
const int CCamera::Update(void)
{
    m_view = glm::lookAt(m_position, m_position + m_orientation, m_up);
    m_projection = glm::perspective(glm::radians(m_data.fFOVDegree), static_cast<float>(m_iWidth / m_iHeight), m_data.fNearPlane, m_data.fFarPlane);
    m_model = glm::rotate(m_model, glm::radians(1.0f), glm::vec3(0.5f, 1.0f, 0.0f));

    return 0;
}

const int CCamera::Draw(void)
{
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, m_data.sName), 1, GL_FALSE, glm::value_ptr(m_projection * m_view * m_model));
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, "projection"), 1, GL_FALSE, glm::value_ptr(m_projection));
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, "view"), 1, GL_FALSE, glm::value_ptr(m_view));
    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, "model"), 1, GL_FALSE, glm::value_ptr(m_model));
    return 0;
}

void CCamera::Finalize(void)
{
}
