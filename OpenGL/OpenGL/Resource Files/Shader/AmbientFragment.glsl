#version 330 core

out vec4 fragColor;

in vec3 vertexColor;

uniform vec3 ambientVec;

void main()
{
	vec3 modelColor = vec3(0.75, 0.75, 0.75);
	vec3 resultColor = modelColor * ambientVec;

	fragColor = vec4(resultColor + vertexColor, 1.0);
}