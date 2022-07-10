
#ifndef SKETCH_VAO_CLASS_H
#define SKETCH_VAO_CLASS_H

#include <glad/glad.h>

#include "../VBO/VBO.hpp"

namespace sk::graphics
{
	class VAO
	{
		public:

		VAO(void);

		~VAO(void) { };

		void linkVertexBuffer(VBO v_buffer, GLuint b_layout);

		void bindArrayBuffer();
		void unbindArrayBuffer();

		void createArrayBuffer();
		void deleteArrayBuffer();

		private:

		GLuint v_array_object;
	};
}

#endif