#include "../EBO.hpp"

namespace sk::graphics
{
	void EBO::bindVertexBuffer()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->v_buffer_object);
	}

	void EBO::unbindVertexBuffer()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}