#include "../VAO.hpp"

namespace sk::graphics
{
	void VAO::bindArrayBuffer()
	{
		glBindVertexArray(this->v_array_object);
	}

	void VAO::unbindArrayBuffer()
	{
		glBindVertexArray(0);
	}
}