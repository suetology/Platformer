#pragma once

#include "Transform.h"

class BoxCollider2D;
class CircleCollider;

class ICollider
{
protected:
	Transform* transform;

	ICollider(Transform* transform) 
		: transform(transform) 
	{}

public:
	virtual bool CheckCollision(glm::vec2 point) = 0;
	virtual bool CheckCollision(BoxCollider2D* other) = 0;
	virtual bool CheckCollision(CircleCollider* other) = 0;
};