#include "pausestate.hpp"

void PauseState::draw(Engine* game) const
{
    _background->draw(game->get_screen());
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
        // Appui sur entrée : on retourne au jeu
        else if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Return)) {
            game->pop_state();
        }
        // Appui sur F12 : on prend une capture d'écran
        else if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::F12)) {
            sf::Image screen = game->get_screen().Capture();
            screen.SaveToFile("screenshot_pause.png");
        }
    }
}

void PauseState::cleanup()
{
    if (_background != NULL) {
        delete _background;
        _background = NULL;
    }
}

void PauseState::init()
{

}
