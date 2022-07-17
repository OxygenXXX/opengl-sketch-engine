#include "texture.hpp"

namespace sk::graphics
{
	Texture::Texture(string t_file, GLenum t_type, GLenum p_type, GLenum t_slot, GLenum t_format)
	{
		this->gl_texture_type = t_type;

		stbi_set_flip_vertically_on_load(true);

		stbi_uc* image_data = stbi_load
			(t_file.c_str(), &this->texture_width, &this->texture_width, &this->texture_channels, STBI_rgb_alpha);

		glGenTextures(1, &this->gl_texture);

		glActiveTexture(GL_TEXTURE0);

		glBindTexture(GL_TEXTURE_2D, this->gl_texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->texture_width, this->texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(image_data);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
}