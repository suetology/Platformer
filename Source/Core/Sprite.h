#pragma once

#include <glm/glm.hpp>

#include "OpenGL/Texture.h"

class Sprite
{
public:
	Sprite(Texture* texture, int width = 0, int height = 0, glm::vec2 startPosition = glm::vec2(0.0f));

	inline float GetAspectRatio() const { return aspectRatio; }

private:
	Texture* texture;
	glm::vec2 startPosition;
	int width, height;
	float aspectRatio;
};

