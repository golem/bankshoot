#include <iostream>

#include "engine.hpp"
#include "introstate.hpp"
#include "playstate.hpp"
#include "pausestate.hpp"
#include "endingstate.hpp"
#include "resourcemanager.hpp"

int main(void)
{
    std::cout << "Hello world!" << std::endl;
    std::cout << "Chargement des images... ";
    // Attention à bien charger les images avec le même chemin (sans commencer par "./")
    ResourceManager::get_img("media/intro_background.png");
    ResourceManager::get_img("media/background_floor.png");
    ResourceManager::get_img("media/background_left.png");
    ResourceManager::get_img("media/background_right.png");
    ResourceManager::get_img("media/sprite_banquier.png");
    ResourceManager::get_img("media/voleur.png");
    ResourceManager::get_img("media/mafia.png");
    ResourceManager::get_img("media/boss.png");
    ResourceManager::get_img("media/client.png");
    ResourceManager::get_img("media/gold.png");
    ResourceManager::get_img("media/sac_dollar.png");
    std::cout << "OK !" << std::endl;
    
    Engine game("Bank Shooter");
    game.add_state("Intro", new IntroState());
    game.add_state("Play", new PlayState());
    game.add_state("Pause", new PauseState());
    game.change_state("Intro");
    // Boucle principale
    while(game.is_running()) {
        game.handle_events();
        game.update();
        game.draw();
    }
    
    ResourceManager::cleanup();
    return 0;
}
