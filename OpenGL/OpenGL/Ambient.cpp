#include "Ambient.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

const int CAmbient::Initialize(void)
{
    return CMaterial::Initialize();
}

const int CAmbient::Update(void)
{
    return CMaterial::Update();
}

const int CAmbient::Draw(void)
{
    GLuint iLocation = glGetUniformLocation((GLuint)GetShaderProgram(), "ambientVec");
    
    glUniform3f(iLocation, m_lightColor.r, m_lightColor.g, m_lightColor.b);

    return CMaterial::Draw();
}

void CAmbient::Finalize(void)
{
    CMaterial::Finalize();
}
