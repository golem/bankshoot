#include "endingstate.hpp"

void EndingState::init()
{
    _background = new Background("media/gameover.png", 0);
}

void EndingState::cleanup()
{
    if (_background != NULL) {
        delete _background;
        _background = NULL;
    }
    if (_score != NULL) {
        delete _score;
        _score = NULL;
    }
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
        else if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Escape)) {
            game->quit();
        }
        else if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Space)) {
            game->change_state("Intro");
        }
        // Appui sur F12 : on prend une capture d'écran
        else if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::F12)) {
            sf::Image screen = game->get_screen().Capture();
            screen.SaveToFile("screenshot_end.png");
        }
    }    
}

void EndingState::update(Engine * game)
{
    _background->update(game->get_screen());
}

void EndingState::draw(Engine * game) const
{
    _background->draw(game->get_screen());
    if (_score != NULL)
        _score->draw(game->get_screen());
}

void EndingState::set_score(int capital, int niveau, float temps)
{
    std::ostringstream os;
    os << "Capital : " << capital << "$" << std::endl;
    os << "Niveau : " << niveau << std::endl;
    os << "Temps de jeu : " << temps << " s";
    _score = new TextObject("media/Fontin-Regular.ttf", os.str(), true, false, true);
    _score->set_color(sf::Color::Black);
}
