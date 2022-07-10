#include "../shader.hpp"

namespace sk::graphics
{
	std::string Shader::read_shader_file(std::string file_path)
	{
		std::ifstream file_input(file_path, std::ios::binary);

		if (file_input)
		{
			std::string file_content;

			file_input.seekg(0, std::ios::end);

			file_content.resize(file_input.tellg());

			file_input.seekg(0, std::ios::beg);

			file_input.read(&file_content[0], file_content.size());

			file_input.close();

			return file_content;
		}

		throw (errno);
	}
}