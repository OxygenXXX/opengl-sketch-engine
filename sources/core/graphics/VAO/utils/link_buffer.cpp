#include "../VAO.hpp"

namespace sk::graphics
{
	/*

	void VAO::linkVertexBuffer(VBO v_buffer, GLuint b_layout)
	{
		v_buffer.bindVertexBuffer();

		glVertexAttribPointer(b_layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)(0));

		glEnableVertexAttribArray(b_layout);

		v_buffer.unbindVertexBuffer();
	}

	*/

	void VAO::linkVertexAttrib(VBO v_buffer, GLuint b_layout, GLuint c_count, GLenum v_type, GLsizeiptr v_stride, void* v_offset)
	{
		v_buffer.bindVertexBuffer();

		glVertexAttribPointer(b_layout, c_count, v_type, GL_FALSE, v_stride, v_offset);

		glEnableVertexAttribArray(b_layout);

		v_buffer.unbindVertexBuffer();
	}
}