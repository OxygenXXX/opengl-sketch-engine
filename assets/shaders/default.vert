#version 330 core

layout (location = 0) in vec3 vertex_pos;
layout (location = 1) in vec3 vertex_col;

out vec3 vertex_color;

void main(void)
{
	gl_Position = vec4(vertex_pos.x, vertex_pos.y, vertex_pos.z, 1.0);

	vertex_color = vec3(vertex_col.x, vertex_col.y, vertex_col.z);
}