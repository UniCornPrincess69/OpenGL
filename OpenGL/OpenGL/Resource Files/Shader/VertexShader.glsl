# version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec3 normal;
layout (location = 4) in vec3 binormal;
layout (location = 5) in vec3 tangent;

out vec3 fragPos;
out vec3 vertexColor;
out vec2 texCoord;
out vec3 lightNormal;
out vec3 lightBiNormal;
out vec3 lightTangent;
out vec3 lightOutputPos;

uniform mat4 camMatrix;
uniform mat4 view;
uniform vec3 lightPos;

void main()
{
    gl_Position = camMatrix * vec4(position, 1.0);
    vertexColor = color;
    texCoord = uv;
    fragPos = vec3(view * vec4(position, 1.0));
    lightNormal = mat3(transpose(inverse(view))) * normal;
    lightBiNormal = mat3(transpose(inverse(view))) * binormal;
    lightTangent = mat3(transpose(inverse(view))) * tangent;

    lightOutputPos = vec3(camMatrix * vec4(lightPos, 1.0));
}