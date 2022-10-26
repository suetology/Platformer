#include "VertexBuffer.h"

#include "../Window.h"

VertexBuffer::VertexBuffer(const void* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::VertexBuffer(Sprite* sprite)
{
	glm::vec2 startPos = glm::vec2(sprite->GetStartPosition().x / sprite->GetTexture()->GetWidth(),
								   sprite->GetStartPosition().y / sprite->GetTexture()->GetHeight());
	glm::vec2 size = glm::vec2(sprite->GetWidth() / sprite->GetTexture()->GetWidth(),
							   sprite->GetHeight() / sprite->GetTexture()->GetHeight());
	float ar = sprite->GetAspectRatio();

	float vertices[] = {
		-0.5f * ar, -0.5f, startPos.x,			startPos.y,
		-0.5f * ar,  0.5f, startPos.x,			startPos.y + size.y,
		 0.5f * ar,  0.5f, startPos.x + size.x,	startPos.y + size.y,
		-0.5f * ar, -0.5f, startPos.x,			startPos.y,
	     0.5f * ar,  0.5f, startPos.x + size.x,	startPos.y + size.y,
		 0.5f * ar, -0.5f, startPos.x + size.x,	startPos.y
	};

	glGenBuffers(1, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &id);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

