#include "glad/glad.h"
#include "Shader.h"

Shader::Shader()
{
	this->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	this->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
}

Shader::Shader(String vsc, String fsc)
{
	this->vertex_sahder_code = vsc;
	this->fragment_shader_code = fsc;
	this->vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	this->fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
}

Shader::~Shader()
{
	glDeleteShader(this->vertex_shader);
	glDeleteShader(this->fragment_shader);

	if (this->shader_program) {
		glDeleteProgram(this->shader_program);
	}
}

void Shader::compile_shader()
{
	auto vsc = ((const char*)this->vertex_sahder_code);
	glShaderSource(this->vertex_shader, 1, &vsc, NULL);

	auto fsc = ((const char*)this->fragment_shader_code);
	glShaderSource(this->fragment_shader, 1, &fsc, NULL);

	glCompileShader(this->vertex_shader);
	glCompileShader(this->fragment_shader);
	int  success;
	char log[512];
	glGetShaderiv(this->vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(this->vertex_shader, 512, NULL, log);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << log << std::endl;
		return;
	}

	glGetShaderiv(this->fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(this->fragment_shader, 512, NULL, log);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << log << std::endl;
		return;
	}

	this->shader_program = glCreateProgram();
	glAttachShader(this->shader_program, this->vertex_shader);
	glAttachShader(this->shader_program, this->fragment_shader);
	glLinkProgram(this->shader_program);

	glGetProgramiv(this->shader_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->shader_program, 512, NULL, log);
		std::cout << "ERROR::SHADER::LINK::FAILED\n" << log << std::endl;
		return;
	}

}

void Shader::use_shader()
{
	if (this->shader_program) glUseProgram(this->shader_program);
}


