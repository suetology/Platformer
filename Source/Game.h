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
	VertexArray* vao;
	VertexBuffer* vbo;
	Shader* shader;
	Texture* texture;
	Sprite* sprite;

	GameObject *obj;

	void Start()
	{
		float vertices[] = {
			-0.5, -0.5,
			 0.0,  0.5,
			 0.5, -0.5
		};
		texture = new Texture("Resources/8046.png");
		sprite = new Sprite(texture, texture->GetWidth(), texture->GetHeight(), glm::vec2(0.0f));

		vao = new VertexArray();
		vao->Bind();
		vbo = new VertexBuffer(sprite);
		shader = load_shader("Resources/basic.vertex", "Resources/basic.fragment");
		shader->Use();
		shader->UniformFloat("aspectRatio", Window::GetAspectRatio());

		obj = new GameObject();
		obj->AddComponent<Transform>();
		
	}

	void Update()
	{
		glm::vec2 pos = Window::ScreenToWorldPosition(Events::GetMousePosition());
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(pos, 0.0f));
		shader->UniformMat4f("transform", transform);

		vbo->Bind();
		shader->Use();
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
};