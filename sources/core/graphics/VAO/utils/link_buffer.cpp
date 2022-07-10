#include "../VAO.hpp"

namespace sk::graphics
{
	void VAO::linkVertexBuffer(VBO v_buffer, GLuint b_layout)
	{
		v_buffer.bindVertexBuffer();

		glVertexAttribPointer(b_layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)(0));

		glEnableVertexAttribArray(b_layout);

		v_buffer.unbindVertexBuffer();
	}
}