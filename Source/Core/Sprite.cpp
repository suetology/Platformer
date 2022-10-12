#include "Sprite.h"

Sprite::Sprite(Texture* texture, int width, int height, glm::vec2 startPosition)
	: texture(texture), width(width), height(height), startPosition(startPosition)
{
	aspectRatio = (float)width / height;
}
