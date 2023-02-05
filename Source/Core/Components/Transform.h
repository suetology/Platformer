#pragma once

#include <typeinfo>

#include <glm/glm.hpp>

class Transform
{
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	Transform(glm::vec3 position = glm::vec3(0.0f), glm::vec3 rotation = glm::vec3(0.0f), glm::vec3 scale = glm::vec3(1.0f))
		: position(position), rotation(rotation), scale(scale) {}
};

