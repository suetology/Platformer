#include <glm/glm.hpp>

#include "../Game.h"
#include "Events.h"
#include "Window.h"

int main()
{
    Events::Init();
    Window *window = new Window("Mario", 0, 0, glm::vec3(0.5f, 0.5f, 0.5f));

    Game *game = new Game();
    game->Start();
    
    while (window->Opened())
    {
        window->Clear();
        
        game->Update();
            
        Events::OnUpdate();
        window->OnUpdate();
    }

    delete game;
    delete window;
    Events::Shutdown();
    return 0;
}