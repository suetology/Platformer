#include <glm/glm.hpp>

#include "../Game.h"
#include "Window.h"

//delete later
#include <GLFW/glfw3.h>

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