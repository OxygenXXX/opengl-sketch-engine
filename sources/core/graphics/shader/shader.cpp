#include "shader.hpp"

namespace sk::graphics
{
	Shader::Shader(std::string v_shader, std::string f_shader)
	{
		this->vertex_shader_source = this->read_shader_file(v_shader);
		this->fragment_shader_source = this->read_shader_file(f_shader);

		const char* vertex_shader_code = this->vertex_shader_source.c_str();
		const char* fragment_shader_code = this->fragment_shader_source.c_str();

		GLuint gl_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		GLuint gl_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(gl_vertex_shader, 1, &vertex_shader_code, NULL);
		glCompileShader(gl_vertex_shader);

		glShaderSource(gl_fragment_shader, 1, &fragment_shader_code, NULL);
		glCompileShader(gl_fragment_shader);

		this->gl_shader_program = glCreateProgram();

		glAttachShader(this->gl_shader_program, gl_vertex_shader);
		glAttachShader(this->gl_shader_program, gl_fragment_shader);

		glLinkProgram(this->gl_shader_program);

		glDeleteShader(gl_vertex_shader);
		glDeleteShader(gl_fragment_shader);

		delete vertex_shader_code;
		delete fragment_shader_code;
	}

	Shader::~Shader(void)
	{
		this->deleteShader();
	}
}