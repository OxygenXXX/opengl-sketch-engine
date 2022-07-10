#include "../shader.hpp"

namespace sk::graphics
{
	void Shader::activateShader()
	{
		glUseProgram(this->gl_shader_program);
	}

	void Shader::deleteShader()
	{
		glDeleteProgram(this->gl_shader_program);
	}
}