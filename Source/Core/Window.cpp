#include "Window.h"

Window::Window(const char *title, int width, int height, glm::vec3 backgroundColor)
{
    Init(title, width, height, backgroundColor);
}

int Window::Init(const char *title, int width, int height, glm::vec3 backgroundColor)
{
	this->width = width;
    this->height = height;
    this->title = title;
    this->backgroundColor = backgroundColor;

    if (!glfwInit())
        return -1;

    if (width != 0 && height != 0)
    {
        window = glfwCreateWindow(width, height, title, NULL, NULL);
    }
    else
    {
        window = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), NULL);
    }

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    return 0;
}

bool Window::Opened()
{
	return !glfwWindowShouldClose(window);
}

void Window::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f);
}

void Window::Close()
{
    if (!glfwWindowShouldClose(window))
    {
        glfwSetWindowShouldClose(window, 1);
    }
}

Window::~Window()
{
    Close();
    glfwTerminate();
}
