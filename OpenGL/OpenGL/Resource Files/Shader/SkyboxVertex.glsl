#version 330 core
layout (location = 0) in vec3 positon;

out vec3 uv;

uniform mat4 projection;
uniform mat 4 view;

void main()
{
	uv = position;
	gl_Position = projection * view *vec4(position, 1.0);
}