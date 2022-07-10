#include "../VBO.hpp"

namespace sk::graphics
{
	void VBO::bindVertexBuffer()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->v_buffer_object);
	}

	void VBO::unbindVertexBuffer()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}