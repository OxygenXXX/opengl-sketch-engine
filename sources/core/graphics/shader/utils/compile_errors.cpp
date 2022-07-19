#include "../shader.hpp"

namespace sk::graphics
{
	void compileShaderErrors(GLuint shader_source, const char* shader_type)
	{
		GLint compilation_status;

		char compilation_logs[1024];

		if (shader_type != "PROGRAM")
		{
			glGetShaderiv(shader_source, GL_COMPILE_STATUS, &compilation_status);

			if (compilation_status == GL_FALSE)
			{
				glGetShaderInfoLog(shader_source, 1024, NULL, compilation_logs);

				std::cout << "SHADER_COMPILATION_ERROR for:" << shader_type << "\n" << compilation_logs << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader_source, GL_LINK_STATUS, &compilation_status);

			if (compilation_status == GL_FALSE)
			{
				glGetProgramInfoLog(shader_source, 1024, NULL, compilation_logs);

				std::cout << "SHADER_LINKING_ERROR for:" << shader_type << "\n" << compilation_logs << std::endl;
			}
		}
	}
}