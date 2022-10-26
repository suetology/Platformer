#pragma once

#include "GL/glew.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>

class Shader
{
public:
	unsigned int id;

	Shader(unsigned int id);
	~Shader();

	void Use() const;
	
	void UniformFloat(const char* name, float value);
	void UniformVec4f(const char* name, float f1, float f2, float f3, float f4);
	void UniformMat4f(const char* name, glm::mat4 data);
};

Shader* load_shader(const std::string& vsFilepath, const std::string& fsFilepath);

