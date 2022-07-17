#include "../texture.hpp"

namespace sk::graphics
{
	void Texture::textureUniform(Shader gl_shader, string uf_name, GLuint uf_value)
	{
		GLuint texture_uniform = glGetUniformLocation(gl_shader.gl_shader_program, uf_name.c_str());

		gl_shader.activateShader();

		glUniform1i(texture_uniform, uf_value);
	}
}