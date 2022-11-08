#pragma once

#include <string>
#include <vector>

#include "Components/Transform.h"
#include "Components/SpriteRenderer.h"
#include "Components/Component.h"

class GameObject
{
private:
	int id;
	std::string name;
	
	Transform* transform;
	SpriteRenderer* spriteRenderer;

public:
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
		return nullptr;
	}

private:
	Transform* AddTransformComponent(Transform* transform = nullptr);
	Transform* GetTransformComponent();
	SpriteRenderer* AddSpriteRendererComponent(SpriteRenderer* spriteRenderer = nullptr);
	SpriteRenderer* GetSpriteRendererComponent();
};
