#include "../EBO.hpp"

namespace sk::graphics
{
	void EBO::createVertexBuffer()
	{
		glGenBuffers(1, &this->v_buffer_object);
	}

	void EBO::deleteVertexBuffer()
	{
		glDeleteBuffers(1, &this->v_buffer_object);
	}
}