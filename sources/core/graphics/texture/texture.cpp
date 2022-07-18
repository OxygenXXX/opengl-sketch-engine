#include "texture.hpp"

namespace sk::graphics
{
	Texture::Texture(string t_file, GLenum t_type, GLenum p_type, GLenum t_slot, GLenum t_format)
	{
		this->gl_texture_type = t_type;

		stbi_set_flip_vertically_on_load(true);

		stbi_uc* image_data = stbi_load
			(t_file.c_str(), &this->texture_width, &this->texture_width, &this->texture_channels, STBI_rgb_alpha);

		this->createTexture();

		glActiveTexture(t_slot);

		this->bindTexture();

		glTexParameteri(this->gl_texture_type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(this->gl_texture_type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(this->gl_texture_type, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(this->gl_texture_type, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(this->gl_texture_type, 0, GL_RGBA, this->texture_width, this->texture_height, 0, t_format, p_type, image_data);

		glGenerateMipmap(this->gl_texture_type);

		stbi_image_free(image_data);

		this->unbindTexture();
	}
}