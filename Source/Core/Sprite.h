#pragma once

#include <glm/glm.hpp>

#include "OpenGL/Texture.h"

class Sprite
{
public:
	Sprite(Texture* texture, int width = 0, int height = 0, glm::vec2 startPosition = glm::vec2(0.0f));

	inline float GetWidth() const { return width; }
	inline float GetHeight() const { return height; }
	inline glm::vec2 GetStartPosition() const { return startPosition; }
	inline float GetAspectRatio() const { return aspectRatio; }
	inline Texture* GetTexture() const { return texture; }

private:
	Texture* texture;
	glm::vec2 startPosition;
	int width, height;
	float aspectRatio;
};

