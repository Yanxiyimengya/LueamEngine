#pragma once
#include "Core/UString.h"
#include <map>

class Shader
{
	String vertex_sahder_code;
	String fragment_shader_code;

public:
	unsigned int shader_program = 0;
	unsigned int vertex_shader = 0;
	unsigned int fragment_shader = 0;
	Shader();
	Shader(String vsc, String fsc);
	~Shader();

	void compile_shader();
	void use_shader();
};

