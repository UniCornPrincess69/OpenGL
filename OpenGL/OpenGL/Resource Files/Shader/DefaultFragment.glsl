#version 330 core

out vec4 FragColor;

in vec3 vertexColor;
in vec3 uv;

void main()
{
		FragColor = vec4(vertexColor, 0.1f);
}