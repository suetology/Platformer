#pragma once

#include <string>
#include <vector>

#include "Components/Transform.h"
#include "Components/SpriteRenderer.h"
#include "Components/BoxCollider2D.h"
#include "Components/CircleCollider.h"

class GameObject
{
private:
	int id;
	std::string name;
	std::vector<GameObject*>* gameObjects;
	
	Transform* transform = nullptr;
	SpriteRenderer* spriteRenderer = nullptr;
	BoxCollider2D* boxCollider2D = nullptr;
	CircleCollider* circleCollider = nullptr;

public:
	GameObject(std::vector<GameObject*>& container);
	~GameObject();

	void Render();

	template<typename T>
	T* AddComponent(T* component = nullptr)
	{
		if (strcmp(typeid(T).name(), "class Transform") == 0)
		{
			return (T*)AddTransformComponent();
			//return component == nullptr ? (T*)AddTransformComponent() : (T*)AddTransformComponent((Transform*)component);
		}
		if (strcmp(typeid(T).name(), "class SpriteRenderer") == 0)
		{
			return (T*)AddSpriteRendererComponent();
			//return component == nullptr ? (T*)AddSpriteRendererComponent() : (T*)AddSpriteRendererComponent((SpriteRenderer*)component);
		}
		if (strcmp(typeid(T).name(), "class BoxCollider2D") == 0)
		{
			return (T*)AddBoxCollider2DComponent();
		}
		if (strcmp(typeid(T).name(), "class CircleCollider") == 0)
		{
			return (T*)AddCircleColliderComponent();
		}
		return nullptr;
	}

	template<typename T>
	T* GetComponent() const
	{
		if (strcmp(typeid(T).name(), "class Transform") == 0 && transform)
		{
			return (T*)transform;
		}
		if (strcmp(typeid(T).name(), "class SpriteRenderer") == 0 && spriteRenderer)
		{
			return (T*)spriteRenderer;
		}
		if (strcmp(typeid(T).name(), "class BoxCollider2D") == 0 && boxCollider2D)
		{
			return (T*)boxCollider2D;
		}
		if (strcmp(typeid(T).name(), "class CircleCollider") == 0 && circleCollider)
		{
			return (T*)circleCollider;
		}
		return nullptr;
	}

private:
	Transform* AddTransformComponent(Transform* transform = nullptr);
	Transform* GetTransformComponent();
	SpriteRenderer* AddSpriteRendererComponent(SpriteRenderer* spriteRenderer = nullptr);
	SpriteRenderer* GetSpriteRendererComponent();
	BoxCollider2D* AddBoxCollider2DComponent(BoxCollider2D* boxCollider2D = nullptr);
	BoxCollider2D* GetBoxCollider2DComponent();
	CircleCollider* AddCircleColliderComponent(CircleCollider* circleCollider = nullptr);
	CircleCollider* GetCircleColliderComponent();
};
