
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

std::string vertex_shader_content = get_shader_content("assets/shaders/default.vert");
std::string fragment_shader_content = get_shader_content("assets/shaders/default.frag");

const char* vertex_shader_source = vertex_shader_content.c_str();
const char* fragment_shader_source = fragment_shader_content.c_str();

signed int main(void)
{
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

	GLuint triangle_indices[] =
	{
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	GLuint vertex_array_object;
	GLuint vertex_buffer_object;

	GLuint element_buffer_object;

	glGenVertexArrays(1, &vertex_array_object);

	glGenBuffers(1, &vertex_buffer_object);
	glGenBuffers(1, &element_buffer_object);

	glBindVertexArray(vertex_array_object);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);

	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_object);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle_indices), triangle_indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(0));
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window_controller);

	while (!glfwWindowShouldClose(window_controller))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(gl_shader_program);

		glBindVertexArray(vertex_array_object);

		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window_controller);

		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &vertex_array_object);

	glDeleteBuffers(1, &vertex_buffer_object);
	glDeleteBuffers(1, &element_buffer_object);

	glDeleteProgram(gl_shader_program);

	glfwDestroyWindow(window_controller);

	glfwTerminate();

	return EXIT_SUCCESS;
}