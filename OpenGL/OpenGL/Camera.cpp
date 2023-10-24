#include "Camera.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const int CCamera::Initialize(void)
{
    

    return 0;
}

const int CCamera::Update(void)
{
    glm::mat4x4 view = glm::mat4x4(1.0f);
    glm::mat4x4 projection = glm::mat4x4(1.0f);

    view = glm::lookAt(m_position, m_position + m_orientation, m_up);

    glUniformMatrix4fv(glGetUniformLocation(*m_data.pShaderID, m_data.sName), 1, GL_FALSE, glm::value_ptr(projection * view));

    return 0;
}

const int CCamera::Draw(void)
{
    return 0;
}

void CCamera::Finalize(void)
{
}
