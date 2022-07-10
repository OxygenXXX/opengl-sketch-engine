
#ifndef SKETCH_EBO_CLASS_H
#define SKETCH_EBO_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace sk::graphics
{
	class EBO
	{
		public:

		EBO(GLuint* e_indices, GLsizeiptr b_sizeptr);
		~EBO(void);

		void bindVertexBuffer();
		void unbindVertexBuffer();

		void createVertexBuffer();
		void deleteVertexBuffer();

		private:

		GLuint v_buffer_object;
	};
}

#endif