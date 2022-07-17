#pragma once

#include <string>
#include <cstdint>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb/stb_image.h>

#include "../shader/shader.hpp"

using std::string;

namespace sk::graphics
{
	class Texture
	{
		public:

		Texture(string t_file, GLenum t_type, GLenum p_type, GLenum t_slot, GLenum t_format);

		void textureUniform(Shader gl_shader, string uf_name, GLuint uf_value);

		void bindTexture();
		void unbindTexture();

		void deleteTexture();

		private:

		GLuint gl_texture;

		GLenum gl_texture_type;

		int texture_width = 0;
		int texture_height = 0;

		int texture_channels = 0;


	};
}

