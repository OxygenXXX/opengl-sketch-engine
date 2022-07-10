
#ifndef SKETCH_VBO_CLASS_H
#define SKETCH_VBO_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace sk::graphics
{
	class VBO
	{
		public:

		VBO(GLfloat* v_count, GLsizeiptr b_sizeptr);
		~VBO(void);

		void bindVertexBuffer();
		void unbindVertexBuffer();

		void createVertexBuffer();
		void deleteVertexBuffer();

		private:

		GLuint v_buffer_object;
	};
}

#endif