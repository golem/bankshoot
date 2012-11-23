#include "pausestate.hpp"

void PauseState::draw(Engine* game) const
{

}

void PauseState::update(Engine* game)
{

}

void PauseState::handle_events(Engine* game)
{
    sf::Event evenement;
    if(game->get_screen().GetEvent(evenement)) {
        // Click sur le bouton "fermer" : on quitte
        if (evenement.Type == sf::Event::Closed) {
            game->quit();
        }
        // Appui sur une touche : on retourne au jeu
        if (evenement.Type == sf::Event::KeyPressed) {
            game->pop_state();
        }
    }
}

void PauseState::cleanup()
{

}

void PauseState::init()
{

}

PauseState::PauseState()
{

}

