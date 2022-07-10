#include "../VBO.hpp"

namespace sk::graphics
{
	void VBO::createVertexBuffer()
	{
		glGenBuffers(1, &this->v_buffer_object);
	}

	void VBO::deleteVertexBuffer()
	{
		glDeleteBuffers(1, &this->v_buffer_object);
	}
}