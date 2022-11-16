#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D(Transform* transform)
	: transform(transform)
{
}

bool BoxCollider2D::CheckCollision(glm::vec2 point) 
{
    int count = 0;
    glm::vec2 borders[] = { glm::vec2(transform->position.x - transform->scale.x / 2, transform->position.y - transform->scale.y / 2),
                            glm::vec2(transform->position.x - transform->scale.x / 2, transform->position.y + transform->scale.y / 2),
                            glm::vec2(transform->position.x + transform->scale.x / 2, transform->position.y + transform->scale.y / 2),
                            glm::vec2(transform->position.x + transform->scale.x / 2, transform->position.y - transform->scale.y / 2) };
    for (int i = 0; i < 4; i++)
    {
        if (RayIntersectLine(borders[i], borders[(i + 1) % 4], point))
        {
            count++;
        }
    }
    return count % 2 != 0;
}

bool BoxCollider2D::RayIntersectLine(glm::vec2 borderA, glm::vec2 borderB, glm::vec2 point)
{
    if (borderA.y > borderB.y)
    {
        return RayIntersectLine(borderB, borderA, point);
    }
    if (point.y > borderB.y || point.y < borderA.y)
    {
        return false;
    }
    if (point.y < borderB.y && point.y > borderA.y)
    {
        if (point.x > glm::max(borderA.x, borderB.x))
        {
            return false;
        }
        if (point.x < glm::min(borderA.x, borderB.x))
        {
            return true;
        }
    }
    float angleAB = (borderB.y - borderA.y) / (borderB.x - borderA.x);
    float angleAP = (point.y - borderA.y) / (point.x - borderA.x);
    if (angleAP > angleAB)
    {
        return true;
    }
    else
    {
        return false;
    }
}
