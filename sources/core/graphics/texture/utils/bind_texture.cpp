#include "../texture.hpp"

namespace sk::graphics
{
	void Texture::bindTexture()
	{
		glBindTexture(this->gl_texture_type, this->gl_texture);
	}

	void Texture::unbindTexture()
	{
		glBindTexture(this->gl_texture_type, 0);
	}
}