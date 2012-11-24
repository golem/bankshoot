#include "endingstate.hpp"

void EndingState::init()
{
    _background = new Background("media/gameover.png", 0);
    _background->set_center(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
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
        if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Space)) {
            game->change_state("Intro");
        }

    }    
}

void EndingState::update(Engine * game)
{
    
}

void EndingState::draw(Engine * game) const
{
    _background->draw(game->get_screen());
}
