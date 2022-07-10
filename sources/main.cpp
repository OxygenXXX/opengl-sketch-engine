
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <iostream>

#include <fstream>
#include <sstream>

#include <cstdint>
#include <string>

#include <cerrno>

#include <cmath>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include "core/constants.hpp"

#include "core/graphics/VBO/VBO.hpp"
#include "core/graphics/VAO/VAO.hpp"
#include "core/graphics/EBO/EBO.hpp"

#include "core/graphics/shader/shader.hpp"

GLFWwindow* window_controller = nullptr;

GLfloat triangle_vertices[] =
{
	-0.5f, -0.5f * float(std::sqrt(3)) / 3, 0.0f,
	 0.5f, -0.5f * float(std::sqrt(3)) / 3, 0.0f,
	 0.0f,  0.5f * float(std::sqrt(3)) * 2 / 3, 0.0f,
	-0.5f / 2 , 0.5f * float(std::sqrt(3)) / 6, 0.0f,
	 0.5f / 2, 0.5f * float(std::sqrt(3)) / 6, 0.0f,
	 0.0f, -0.5f * float(std::sqrt(3)) / 3, 0.0f,
};

GLuint triangle_indices[] = { 0, 3, 5, 3, 2, 4, 5, 4, 1 };

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

	VBO vertex_buffer_object(triangle_vertices, sizeof(triangle_vertices));
	EBO element_buffer_object(triangle_indices, sizeof(triangle_indices));

	vertex_array_objet.linkVertexBuffer(vertex_buffer_object, 0);

	vertex_array_objet.unbindArrayBuffer();

	vertex_buffer_object.unbindVertexBuffer();
	element_buffer_object.unbindVertexBuffer();

	while (!glfwWindowShouldClose(window_controller))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		default_shader.activateShader();

		vertex_array_objet.bindArrayBuffer();

		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window_controller);

		glfwPollEvents();
	}

	vertex_array_objet.deleteArrayBuffer();

	vertex_buffer_object.deleteVertexBuffer();
	element_buffer_object.deleteVertexBuffer();

	default_shader.deleteShader();

	glfwDestroyWindow(window_controller);

	glfwTerminate();

	return EXIT_SUCCESS;
}