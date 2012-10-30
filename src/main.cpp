#include <iostream>

#include "engine.hpp"
#include "introstate.hpp"
#include "playstate.hpp"

int main(void)
{
    std::cout << "Hello world!" << std::endl;
    
    Engine game("Kikoo");
    game.add_state("Intro", new IntroState());
    game.add_state("Play", new PlayState());
    game.change_state(game.get_state("Intro"));
    
    // Boucle principale
    while(game.is_running()) {
        game.handle_events();
        game.update();
        game.draw();
    }
    
    return 0;
}
