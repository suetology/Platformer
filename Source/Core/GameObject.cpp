#include "GameObject.h"

Transform* GameObject::AddTransformComponent()
{
	if (!transform)
	{
		transform = new Transform();
	}
	return transform;
}

Transform* GameObject::GetTransformComponent()
{
	return transform;
}
