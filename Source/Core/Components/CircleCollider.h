#pragma once

#include <glm/glm.hpp>

#include "ICollider.h"

class BoxCollider2D;

class CircleCollider : public ICollider
{
public:
	CircleCollider(Transform* transform)
		: ICollider(transform) {}

	inline glm::vec2 GetPosition() { return transform->position; }
	inline float GetRadius() { return transform->scale.x / 2; }

	bool CheckCollision(glm::vec2 point) override;
	bool CheckCollision(CircleCollider* other) override;
	bool CheckCollision(BoxCollider2D* other) override;
};

