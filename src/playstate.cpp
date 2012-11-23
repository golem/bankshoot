#include "playstate.hpp"

void PlayState::init()
{
    //~ _bg.LoadFromFile("./media/icone.bmp");
    //~ _bg_sprite.SetImage(_bg);
    //~ _objects += new Banquier("./media/sprite_banquier.png");
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
        if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Escape)) {
            game->change_state("Intro");
        }
        // Appui sur Entrée : on met le jeu en pause
        if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Return)) {
            game->push_state("Pause");
        }
    }
}

void PlayState::update(Engine * game)
{
    if (_factory.has_boss() == false) {
        if (_factory.get_last_enemy_time() > NEXT_ENEMY_TIME) {
            _objects += _factory.generate(_banquier);
            _factory.restart();
        }
    }

    _objects.update_all(game->get_screen());
}

void PlayState::draw(Engine * game) const
{
    //~ game->get_screen().Draw(_bg_sprite);
    _objects.draw_all(game->get_screen());
}
