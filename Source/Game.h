#pragma once

#include "Core/Log.h"
#include "Core/OpenGL.h"
#include "Core/Sprite.h"
#include "Core/Events.h"
#include "Core/Window.h"
#include "Core/GameObject.h"
#include "Core/Components/Transform.h"

#include "GLFW/glfw3.h"

class Game
{	
public:
	Texture* texture;
	Sprite* sprite;

	std::vector<GameObject*> objects;

	void Start()
	{
		texture = new Texture("Resources/8046.png");
		sprite = new Sprite(texture, texture->GetWidth(), texture->GetHeight(), glm::vec2(0.0f));

		objects.push_back(new GameObject());
		objects[0]->AddComponent<Transform>();
		objects[0]->AddComponent<SpriteRenderer>()->AttachSprite(sprite);
	}

	void Update()
	{
		glm::vec2 pos = Window::ScreenToWorldPosition(Events::GetMousePosition());
		objects[0]->GetComponent<Transform>()->position = glm::vec3(pos, 0.0f);
	}
};