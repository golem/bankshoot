#include "playstate.hpp"

void PlayState::init()
{
    //~ _bg.LoadFromFile("./media/icone.bmp");
    //~ _bg_sprite.SetImage(_bg);
    _objects += new Banquier("./media/sprite_banquier.png");
    _objects += new Voleur("./media/icone.bmp");
    _objects += new Background("./media/background_test.png", 100);
    _objects += new Background("./media/mur.png", 50, -1, left);
    _objects += new Background("./media/mur2.png", 50, -1, right);
    
    _objects += new FPSCounter("./media/BOWSHADW.ttf");
}

void PlayState::cleanup()
{
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
        //~ // Appui sur Espace : on passe à l'état jeu
        //~ if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Space)) {
            //~ game->change_state(game->get_state("play"));
        //~ }
    }
}

void PlayState::update(Engine * game)
{
    if (_factory.get_last_enemy_time() > NEXT_ENEMY_TIME) {
        _objects += _factory.generate();
        _factory.restart();
    }

    _objects.update_all(game->get_screen());
}

void PlayState::draw(Engine * game) const
{
    //~ game->get_screen().Draw(_bg_sprite);
    _objects.draw_all(game->get_screen());
}
