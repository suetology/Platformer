#pragma once

#include <glm/glm.hpp>

#include "Transform.h"

class BoxCollider2D
{
private:
	Transform* transform;

public:
	BoxCollider2D(Transform* transform);

	bool CheckCollision(glm::vec2 point);
private:
	bool RayIntersectsLine(glm::vec2 borderA, glm::vec2 borderB, glm::vec2 point);
};

