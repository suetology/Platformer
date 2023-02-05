#include "CircleCollider.h"

#include "BoxCollider2D.h"

bool CircleCollider::CheckCollision(glm::vec2 point)
{
	return glm::distance(this->GetPosition(), point) <= this->GetRadius();
}

bool CircleCollider::CheckCollision(CircleCollider* other)
{
	return glm::distance(this->GetPosition(), other->GetPosition()) < this->GetRadius() + other->GetRadius();
}

bool CircleCollider::CheckCollision(BoxCollider2D* other)
{
	glm::vec2 radiusVector = other->GetPosition() - this->GetPosition();
	glm::vec2 radiusDirection = this->GetRadius() * glm::normalize(radiusVector);
	glm::vec2 pointOnCircle = this->GetPosition() + radiusDirection;

	return glm::length(radiusVector) <= this->GetRadius() || other->CheckCollision(pointOnCircle);
}

