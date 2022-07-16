
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include <fstream>
#include <sstream>

#include <cstdint>
#include <string>

#include <cerrno>

#include <cmath>

#define STB_IMAGE_IMPLEMENTATION

#include <stb/stb_image.h>

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stb/stb_image_resize.h>
#include <stb/stb_image_write.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include "core/constants.hpp"

#include "core/graphics/VBO/VBO.hpp"
#include "core/graphics/VAO/VAO.hpp"
#include "core/graphics/EBO/EBO.hpp"

#include "core/graphics/shader/shader.hpp"

GLFWwindow* window_controller = nullptr;

GLfloat vertices_data[] =
{
	-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
	 0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	1.0f, 1.0f,
	 0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	1.0f, 0.0f
};

GLuint indices_data[] = { 0, 2, 1, 0, 3, 2 };

static int image_width = 0;
static int image_height = 0;

static int image_channels = 0;

signed int main(void)
{
	using sk::graphics::Shader;
	
	using sk::graphics::VBO;
	using sk::graphics::VAO;
	using sk::graphics::EBO;

	if (glfwInit() == NULL)
	{
		std::cout << "Unable to initialize GLFW!" << std::endl;

		return EXIT_FAILURE;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window_controller = glfwCreateWindow(sk::window_width, sk::window_height, sk::window_title, NULL, NULL);

	if (window_controller == NULL)
	{
		std::cout << "Unable to create window!" << std::endl;

		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window_controller);

	gladLoadGL();

	glViewport(0, 0, sk::window_width, sk::window_height);

	Shader default_shader("assets/shaders/default.vert", "assets/shaders/default.frag");

	VAO vertex_array_objet;

	vertex_array_objet.bindArrayBuffer();

	VBO vertex_buffer_object(vertices_data, sizeof(vertices_data));
	EBO element_buffer_object(indices_data, sizeof(indices_data));

	vertex_array_objet.linkVertexAttrib(vertex_buffer_object, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)(0));
	vertex_array_objet.linkVertexAttrib(vertex_buffer_object, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	vertex_array_objet.linkVertexAttrib(vertex_buffer_object, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	vertex_array_objet.unbindArrayBuffer();

	vertex_buffer_object.unbindVertexBuffer();
	element_buffer_object.unbindVertexBuffer();

	GLuint sh_scale_uniform = glGetUniformLocation(default_shader.gl_shader_program, "vertex_scale");

	stbi_uc* image_data = stbi_load("assets/textures/example.png", &image_width, &image_height, &image_channels, STBI_rgb_alpha);

	GLuint gl_texture;

	glGenTextures(1, &gl_texture);

	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, gl_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(image_data);

	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint sh_texture_uniform = glGetUniformLocation(default_shader.gl_shader_program, "texture_data");

	default_shader.activateShader();

	glUniform1i(sh_texture_uniform, 0);

	while (!glfwWindowShouldClose(window_controller))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		default_shader.activateShader();

		glUniform1f(sh_scale_uniform, 0.0f);

		glBindTexture(GL_TEXTURE_2D, gl_texture);

		vertex_array_objet.bindArrayBuffer();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window_controller);

		glfwPollEvents();
	}

	vertex_array_objet.deleteArrayBuffer();

	vertex_buffer_object.deleteVertexBuffer();
	element_buffer_object.deleteVertexBuffer();

	default_shader.deleteShader();

	glDeleteTextures(1, &gl_texture);

	glfwDestroyWindow(window_controller);

	glfwTerminate();

	return EXIT_SUCCESS;
}