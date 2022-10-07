#include "Window.h"

#include "Events.h"

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        Events::keys[key] = true;
        Events::frames[key] = Events::currentFrame;
    }
    else
    {
        Events::keys[key] = false;
        Events::frames[key] = Events::currentFrame;
    }
}

void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos)
{

}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{

}

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

    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_pos_callback);
    glfwSetKeyCallback(window, key_callback);

    if (glewInit() != GLEW_OK)
    {
        return -1;
    }

    return 0;
}

bool Window::Opened() const
{
	return !glfwWindowShouldClose(window);
}

void Window::OnUpdate()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::Clear() const
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

