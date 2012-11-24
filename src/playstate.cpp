#include "playstate.hpp"
#include "pausestate.hpp"

void PlayState::init()
{
    _banquier = new Banquier("media/sprite_banquier.png");
    _objects += _banquier;
    _objects += new Background("media/background_floor.png", 100);
    _objects += new Background("media/background_left.png", 50, -1, Background::left);
    _objects += new Background("media/background_right.png", 50, -1, Background::right);

    _objects += new FPSCounter("media/BOWSHADW.ttf");
    _objects += new ScoreDisplay("media/Vera.ttf", _banquier);
}

void PlayState::cleanup()
{
    _factory.reset_boss();
    _factory.reset_level();
    _objects.delete_all();
}

void PlayState::handle_events(Engine * game)
{
    sf::Event evenement;
    if(game->get_screen().GetEvent(evenement)) {
        // Click sur le bouton "fermer" : on quitte
        if (evenement.Type == sf::Event::Closed) {
            game->quit();
        }
        // Appui sur Esc : on retourne à l'intro
        else if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Escape)) {
            game->change_state("Intro");
        }
        // Appui sur Entrée : on met le jeu en pause
        else if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Return)) {
            ((PauseState*) game->get_state("Pause"))->set_background(game->get_screen().Capture());
            game->push_state("Pause");
        }
        // Appui sur F12 : on prend une capture d'écran
        else if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::F12)) {
            sf::Image screen = game->get_screen().Capture();
            screen.SaveToFile("screenshot.png");
        }
    }
}

void PlayState::update(Engine * game)
{
    Enemy * enemy = _factory.generate(_banquier);
    if (enemy != NULL) {
        _objects += enemy;
    }

    _objects.update_all(game->get_screen());
}

void PlayState::draw(Engine * game) const
{
    _objects.draw_all(game->get_screen());
    
    if (_banquier->a_perdu()) {
        game->change_state("Fin");
    }
}
