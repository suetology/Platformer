#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Window.h"
#include "../Game.h"

int main()
{
    Window *window = new Window("Mario", 640, 480, glm::vec3(0.5f, 0.5f, 0.5f));

    Game *game = new Game();
    game->Start();
    
    while (window->Opened())
    {
        window->Clear();
        
        game->Update();
            
        glfwSwapBuffers(window->Get());
        glfwPollEvents();
    }

    delete window;
    return 0;
}