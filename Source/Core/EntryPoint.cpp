#include <glm/glm.hpp>

#include "../Game.h"
#include "Events.h"
#include "Window.h"

int main()
{
    Events::Init();
    Window::Init("Mario", 640, 480, glm::vec3(0.5f, 0.5f, 0.5f));

    Game *game = new Game();
    game->Start();
    
    while (Window::Opened())
    {
        Window::Clear();
        
        game->Update();
            
        Events::OnUpdate();
        Window::OnUpdate();
    }

    delete game;
    Window::Close();
    Events::Shutdown();
    return 0;
}