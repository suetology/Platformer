#include "Window.h"

Window::Window(const char *title, int width, int height, glm::vec3 backgroundColor)
    : title(title), width(width), height(height), backgroundColor(backgroundColor)
{
    Init();
}

int Window::Init()
{
    if (!glfwInit())
    {
        return -1;
    }

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

    if (glewInit() != GLEW_OK)
    {
        return -1;
    }

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
