#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Components/Transform.h"

class Camera2D
{
private:
	static Transform* transform;
	static float zoom;

public:
	static void Init(Transform* transform = new Transform(), float zoom = 1.0f);
	static void Destroy();
	static Transform* GetTransform();
	static glm::mat4 GetCameraMat();
};

