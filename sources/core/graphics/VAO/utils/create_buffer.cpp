#include "../VAO.hpp"

namespace sk::graphics
{
	void VAO::createArrayBuffer()
	{
		glGenVertexArrays(1, &this->v_array_object);
	}

	void VAO::deleteArrayBuffer()
	{
		glDeleteVertexArrays(1, &this->v_array_object);
	}
}