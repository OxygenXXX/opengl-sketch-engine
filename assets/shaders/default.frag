#version 330 core

in vec3 vertex_color;
in vec2 vertex_texture;

uniform sampler2D texture_data;

out vec4 fragment_color;

void main(void)
{
    fragment_color = texture(texture_data, vertex_texture);
}