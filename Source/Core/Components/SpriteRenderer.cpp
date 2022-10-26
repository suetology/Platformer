#include "SpriteRenderer.h"

#include "../Window.h"

SpriteRenderer::SpriteRenderer()
{
	if (!vao)
	{
		vao = new VertexArray();
	}
	shader = load_shader("Resources/basic.vertex", "Resources/basic.fragment");
	shader->Use();
	shader->UniformFloat("aspectRatio", Window::GetAspectRatio());
}

SpriteRenderer::SpriteRenderer(Sprite* sprite)
{
	SpriteRenderer();

	AttachSprite(sprite);
}

void SpriteRenderer::AttachSprite(Sprite* sprite)
{
	this->sprite = sprite;
	vao->Bind();
	vbo = new VertexBuffer(sprite);

}

void SpriteRenderer::Render(Transform* transform)
{
}
