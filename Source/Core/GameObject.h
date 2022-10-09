#pragma once

#include <string>
#include <vector>

#include "Components/Transform.h"
#include "Components/Component.h"

class GameObject
{
private:
	int id;
	std::string name;
	
	Transform* transform;

public:
	template<typename T>
	T* AddComponent()
	{
		if (strcmp(typeid(T).name(), "class Transform") == 0)
		{
			return AddTransformComponent();
		}
		return nullptr;
	}

	template<typename T>
	T* GetComponent() const
	{
		if (transform)
		{
			return transform;
		}
		return nullptr;
	}

private:
	Transform* AddTransformComponent();
	Transform* GetTransformComponent();
};
