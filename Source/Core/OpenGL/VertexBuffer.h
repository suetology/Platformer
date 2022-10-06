#pragma once

#include "GL/glew.h"

class VertexBuffer
{
public:
	VertexBuffer(const void* vertices, GLsizeiptr size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

private:
	unsigned int id;
};

