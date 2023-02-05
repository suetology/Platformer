#pragma once

#include "Core/Log.h"
#include "Core/OpenGL.h"
#include "Core/Sprite.h"
#include "Core/Events.h"
#include "Core/Window.h"
#include "Core/Camera2D.h"
#include "Core/GameObject.h"
#include "Core/Components/Transform.h"
#include "Core/Components/BoxCollider2D.h"
#include "Core/Components/CircleCollider.h"

#include "GLFW/glfw3.h"

class Game
{	
public:
	Texture* texture;
	Sprite* sprite;

	std::vector<GameObject*> objects;
	GameObject* object1;
	GameObject* object2;

	void Start()
	{
		Camera2D::Init();

		texture = new Texture("Resources/circle.png");
		sprite = new Sprite(texture, texture->GetWidth(), texture->GetHeight(), glm::vec2(0.0f));

		object1 = new GameObject(objects);
		object1->AddComponent<Transform>();
		object1->AddComponent<SpriteRenderer>()->AttachSprite(sprite);
		object1->AddComponent<CircleCollider>();

		object2 = new GameObject(objects);
		object2->AddComponent<Transform>();
		object2->AddComponent<SpriteRenderer>()->AttachSprite(sprite);
		object2->AddComponent<CircleCollider>();

		object2->GetComponent<Transform>()->position.x += 0.5f;
	}

	void Update()
	{
		glm::vec2 pos = Window::ScreenToWorldPosition(Events::GetMousePosition());
	}
};