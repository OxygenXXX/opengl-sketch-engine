#include "EBO.hpp"

namespace sk::graphics
{
	EBO::EBO(GLuint* v_indices, GLsizeiptr b_sizeptr)
	{
		this->createVertexBuffer();
		this->bindVertexBuffer();

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, b_sizeptr, v_indices, GL_STATIC_DRAW);
	}
}
