#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aUv;
layout (location = 3) in vec3 aNormal;

out vec3 fragPos;
out vec3 vertexColor;
out vec3 normal;
out vec3 lightOutputPos;

uniform vec3 lightPos;
uniform mat4 camMatrix;
uniform mat4 view;

void main()
{
	gl_Position = camMatrix * vec4(aPosition, 1.0);
	vertexColor = aColor;
	fragPos = vec3(view * vec4(aPosition, 1.0));
	normal = mat3(transpose(inverse(view))) * aNormal;

	lightOutputPos = vec3(camMatrix * vec4(lightPos, 1.0));
}
