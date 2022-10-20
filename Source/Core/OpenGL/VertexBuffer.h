#pragma once

#include "GL/glew.h"

#include "../Sprite.h"

class VertexBuffer
{
public:
	VertexBuffer(const void* vertices, GLsizeiptr size);
	VertexBuffer(Sprite* sprite);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

private:
	unsigned int id;
};

