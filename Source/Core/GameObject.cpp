#include "GameObject.h"

GameObject::GameObject(std::vector<GameObject*>& container)
{
	this->gameObjects = &container;
	this->id = this->gameObjects->size();
	this->gameObjects->push_back(this);
}

GameObject::~GameObject()
{
	gameObjects->erase(gameObjects->begin() + this->id);
}

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
	if (!this->boxCollider2D && !this->circleCollider)
	{
		boxCollider2D == nullptr ? this->boxCollider2D = new BoxCollider2D(this->transform) : this->boxCollider2D = boxCollider2D;
	}
	return this->boxCollider2D;
}

BoxCollider2D* GameObject::GetBoxCollider2DComponent()
{
	return boxCollider2D;
}

CircleCollider* GameObject::AddCircleColliderComponent(CircleCollider* circleCollider)
{
	if (!this->transform)
	{
		return nullptr;
	}
	if (!this->circleCollider && !this->boxCollider2D)
	{
		circleCollider == nullptr ? this->circleCollider = new CircleCollider(this->transform) : this->circleCollider = circleCollider;
	}
	return this->circleCollider;
}

CircleCollider* GameObject::GetCircleColliderComponent()
{
	return circleCollider;
}
