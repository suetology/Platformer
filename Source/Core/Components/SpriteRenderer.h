#pragma once

#include "../Sprite.h"
#include "Transform.h"
#include "../OpenGL/Shader.h"
#include "../OpenGL/VertexArray.h"
#include "../OpenGL/VertexBuffer.h"

class SpriteRenderer
{
private:
	static Shader* shader;
	static VertexArray* vao;
	VertexBuffer* vbo;
	Sprite* sprite;

public:
	SpriteRenderer();
	SpriteRenderer(Sprite* sprite);
	~SpriteRenderer();

	void AttachSprite(Sprite* sprite);
	void Render(Transform* transform);
};	

