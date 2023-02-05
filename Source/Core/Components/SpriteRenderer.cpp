#include "SpriteRenderer.h"

#include "../Window.h"
#include "../Camera2D.h"

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
	t = glm::scale(t, glm::vec3(transform->scale.x / Window::GetAspectRatio(), transform->scale.y, 0));
	t = glm::rotate(t, glm::radians(transform->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	t = glm::rotate(t, glm::radians(transform->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	t = glm::rotate(t, glm::radians(transform->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	t = glm::translate(t, transform->position);

	shader->UniformMat4f("transform", t);
	shader->UniformMat4f("cameraTransform", Camera2D::GetCameraMat());
	vao->Bind();
	vbo->Bind();
	shader->Use();
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
