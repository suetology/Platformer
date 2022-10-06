#pragma once

#include "Core/OpenGL.h"

class Game
{	
public:
	VertexArray *vao;
	VertexBuffer *vbo;
	Shader *shader;

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
	}

	void Update()
	{
		vbo->Bind();
		shader->Use();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
};