#pragma once

#include <glm/glm.hpp>

#include "ICollider.h"

class BoxCollider2D : public ICollider
{
public:
	BoxCollider2D(Transform* transform)
		: ICollider(transform) {}

	inline glm::vec2 GetPosition() { return transform->position; }
	inline glm::vec2 GetScale() { return transform->scale; }

	bool CheckCollision(glm::vec2 point) override;
	bool CheckCollision(BoxCollider2D* other) override;
	bool CheckCollision(CircleCollider* other) override;

private:
	bool RayIntersectLine(glm::vec2 borderA, glm::vec2 borderB, glm::vec2 point);
};

