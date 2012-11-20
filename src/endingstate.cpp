#include "endingstate.hpp"

void EndingState::init()
{

}

void EndingState::cleanup()
{
}

void EndingState::handle_events(Engine * game)
{
    sf::Event evenement;
    if(game->get_screen().GetEvent(evenement)) {
        // Click sur le bouton "fermer" : on quitte
        if (evenement.Type == sf::Event::Closed) {
            game->quit();
        }
        // Appui sur Esc : on quitte
        if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Escape)) {
            game->quit();
        }
    }    
}

void EndingState::update(Engine * game)
{
}

void EndingState::draw(Engine * game) const
{
}
