
#ifndef SKETCH_SHADER_H
#define SKETCH_SHADER_H

#include <string>
#include <cstdint>

#include <fstream>
#include <sstream>

#include <cerrno>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace sk::graphics
{
	class Shader
	{
		public:

		Shader(std::string v_shader, std::string f_shader);

		~Shader(void) { };

		void activateShader();
		void deleteShader();

		public:
	
		GLuint gl_shader_program;

		private:

		std::string vertex_shader_source = "";
		std::string fragment_shader_source = "";

		std::string read_shader_file(std::string file_path);
	};
}

#endif
