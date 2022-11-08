#include "SpriteRenderer.h"

#include "../Window.h"

Shader* SpriteRenderer::shader;
VertexArray* SpriteRenderer::vao;

SpriteRenderer::SpriteRenderer()
{
	if (!vao)
	{
		vao = new VertexArray();
	}
	if (!shader)
	{
		shader = load_shader("Resources/basic.vertex", "Resources/basic.fragment");
	}
	shader->Use();
	shader->UniformFloat("aspectRatio", Window::GetAspectRatio());
}

SpriteRenderer::SpriteRenderer(Sprite* sprite)
{
	SpriteRenderer();
	AttachSprite(sprite);
}

SpriteRenderer::~SpriteRenderer()
{
	if (vbo)
	{
		delete vbo;
	}
}

void SpriteRenderer::AttachSprite(Sprite* sprite)
{
	this->sprite = sprite;
	vao->Bind();
	vbo = new VertexBuffer(sprite);
}

void SpriteRenderer::Render(Transform* transform)
{
	glm::mat4 t = glm::mat4(1.0f);
	t = glm::scale(t, transform->scale);
	t = glm::rotate(t, glm::degrees(transform->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	t = glm::rotate(t, glm::degrees(transform->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	t = glm::rotate(t, glm::degrees(transform->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	t = glm::translate(t, transform->position);

	shader->UniformMat4f("transform", t);
	vao->Bind();
	vbo->Bind();
	shader->Use();
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
