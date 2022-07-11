#version 330 core

layout (location = 0) in vec3 vertex_pos;
layout (location = 1) in vec3 vertex_col;

uniform float vertex_scale;

out vec3 vertex_color;

void main(void)
{
	vec4 vertex_position = vec4(vertex_pos.x, vertex_pos.y, vertex_pos.z, 1.0);

	vertex_position.x = vertex_position.x + vertex_position.x * vertex_scale;
	vertex_position.y = vertex_position.y + vertex_position.y * vertex_scale;
	vertex_position.z = vertex_position.z + vertex_position.z * vertex_scale;

	gl_Position = vertex_position;

	vertex_color = vec3(vertex_col.x, vertex_col.y, vertex_col.z);
}