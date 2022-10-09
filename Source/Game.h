#pragma once

#include "Core/Log.h"
#include "Core/OpenGL.h"
#include "Core/Events.h"
#include "Core/GameObject.h"
#include "Core/Components/Transform.h"

#include "GLFW/glfw3.h"

class Game
{	
public:
	VertexArray *vao;
	VertexBuffer *vbo;
	Shader *shader;

	GameObject *obj;

	void Start()
	{
		float vertices[] = {
			-0.5, -0.5,
			 0.0,  0.5,
			 0.5, -0.5
		};

		vao = new VertexArray();
		vao->Bind();
		vbo = new VertexBuffer(vertices, sizeof(vertices));
		shader = load_shader("Resources/basic.vertex", "Resources/basic.fragment");
	
		obj = new GameObject();
		obj->AddComponent<Transform>();
		glm::vec3 v = obj->GetComponent<Transform>()->position;
		PRINT3(v.x, v.y, v.z);
	}

	void Update()
	{
		vbo->Bind();
		shader->Use();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
};