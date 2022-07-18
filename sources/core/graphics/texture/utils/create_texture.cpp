#include "../texture.hpp"

namespace sk::graphics
{
	void Texture::createTexture(void)
	{
		glGenTextures(1, &this->gl_texture);
	}

	void Texture::deleteTexture(void)
	{
		glDeleteTextures(1, &this->gl_texture);
	}
}