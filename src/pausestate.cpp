#include "pausestate.hpp"

void PauseState::draw(Engine* game) const
{
    if (_background != NULL)
        _background->draw(game->get_screen());
    _info->draw(game->get_screen());
}

void PauseState::update(Engine* game)
{
    _info->update(game->get_screen());
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
    if (_info != NULL) {
        delete _info;
        _info = NULL;
    }
}

void PauseState::init()
{
    _info = new PauseText();
}

void* PauseState::PauseText::update(const sf::RenderWindow& fen)
{
    _elapsed_time += fen.GetFrameTime();
    if (_elapsed_time > _transition_time) {
        _elapsed_time = 0.0f;
        _alpha_croissant = !_alpha_croissant;
    }
    _alpha = (_alpha_croissant) ? 255*_elapsed_time/_transition_time : 255*(1-_elapsed_time/_transition_time);
    _texte.SetColor(sf::Color(255, 255, 255, _alpha));
    
    return TextObject::update(fen);
}