#include <iostream>

#include "engine.hpp"
#include "introstate.hpp"
#include "playstate.hpp"
#include "resourcemanager.hpp"

int main(void)
{
    std::cout << "Hello world!" << std::endl;
    std::cout << "Chargement des images... ";
    ResourceManager::get_img("media/background.bmp");
    ResourceManager::get_img("media/background_test.png");
    ResourceManager::get_img("media/icone.bmp");
    std::cout << "OK !" << std::endl;
    
    Engine game("Bank Shooter");
    game.add_state("Intro", new IntroState());
    game.add_state("Play", new PlayState());
    game.change_state("Play");
    // Boucle principale
    while(game.is_running()) {
        game.handle_events();
        game.update();
        game.draw();
    }
    
    ResourceManager::cleanup();
    return 0;
}
