#include "GameObject.h"

void GameObject::Render()
{
	if (!transform || !spriteRenderer)
	{
		return;
	}
	spriteRenderer->Render(transform);
}

Transform* GameObject::AddTransformComponent(Transform* transform)
{
	if (!this->transform)
	{
		transform == nullptr ? this->transform = new Transform() : this->transform = transform;
	}
	return this->transform;

}

Transform* GameObject::GetTransformComponent()
{
	return transform;
}

SpriteRenderer* GameObject::AddSpriteRendererComponent(SpriteRenderer* spriteRenderer)
{
	if (!this->spriteRenderer)
	{
		spriteRenderer == nullptr ? this->spriteRenderer = new SpriteRenderer() : this->spriteRenderer = spriteRenderer;
	}
	return this->spriteRenderer;
}

SpriteRenderer* GameObject::GetSpriteRendererComponent()
{
	return spriteRenderer;
}
