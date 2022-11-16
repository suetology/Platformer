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

BoxCollider2D* GameObject::AddBoxCollider2DComponent(BoxCollider2D* boxCollider2D)
{
	if (!this->transform)
	{
		return nullptr;
	}
	if (!this->boxCollider2D)
	{
		boxCollider2D == nullptr ? this->boxCollider2D = new BoxCollider2D(this->transform) : this->boxCollider2D = boxCollider2D;
	}
	return this->boxCollider2D;
}

BoxCollider2D* GameObject::GetBoxCollider2DComponent()
{
	return boxCollider2D;
}
