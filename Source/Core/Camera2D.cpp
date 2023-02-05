#include "Camera2D.h"

#include "Window.h"

Transform* Camera2D::transform;
float Camera2D::zoom;

void Camera2D::Init(Transform* _transform, float _zoom)
{
	transform = _transform;
	zoom = _zoom;
}

void Camera2D::Destroy()
{
	delete transform;
}

Transform* Camera2D::GetTransform()
{
	return transform;
}

glm::mat4 Camera2D::GetCameraMat()
{
	glm::mat4 cameraTransform = glm::mat4(1.0f);

	glm::vec3 rotation = transform->rotation;
	rotation.x = -rotation.x;
	rotation.y = -rotation.y;
	rotation.z = -rotation.z;
	cameraTransform = glm::rotate(cameraTransform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	cameraTransform = glm::rotate(cameraTransform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	cameraTransform = glm::rotate(cameraTransform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	glm::vec3 position = transform->position;
	position.x = -position.x;
	position.y = -position.y;
	position.z = -position.z;
	cameraTransform = glm::translate(cameraTransform, position);

	return cameraTransform;
}
