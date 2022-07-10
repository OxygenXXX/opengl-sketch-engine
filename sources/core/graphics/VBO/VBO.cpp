#include "VBO.hpp"

namespace sk::graphics
{
	VBO::VBO(GLfloat* v_count, GLsizeiptr b_sizeptr)
	{
		this->createVertexBuffer();
		this->bindVertexBuffer();

		glBufferData(GL_ARRAY_BUFFER, b_sizeptr, v_count, GL_STATIC_DRAW);
	}

	VBO::~VBO(void)
	{
		this->deleteVertexBuffer();
	}
}
