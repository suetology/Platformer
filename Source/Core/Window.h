#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Window
{
public:
	Window(const char *title, int width = 0, int height = 0, glm::vec3 backgroundColor = glm::vec3(1.0f));
	~Window();

	int Init();
	bool Opened();
	void Clear();
	void Close();

	inline GLFWwindow *Get() { return window; }
	inline int GetWidth() { return width; }
	inline int GetHeight() { return height; }

private:
	GLFWwindow *window;
	int width, height;
	const char *title;
	glm::vec3 backgroundColor;
};

