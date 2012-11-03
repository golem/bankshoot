#include "playstate.hpp"

void PlayState::init()
{
    //~ _bg.LoadFromFile("./media/icone.bmp");
    //~ _bg_sprite.SetImage(_bg);
    _objects += new Background("./media/background_test.png", 100);
    _objects += new Banquier("./media/icone.bmp");
    _objects += new Enemy("./media/icone.bmp");
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
            game->change_state(game->get_state("Intro"));
        }
        //~ // Appui sur Espace : on passe à l'état jeu
        //~ if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Space)) {
            //~ game->change_state(game->get_state("play"));
        //~ }
    }
}

void PlayState::update(Engine * game)
{
    _objects.update_all(game->get_screen());
}

void PlayState::draw(Engine * game) const
{
    //~ game->get_screen().Draw(_bg_sprite);
    _objects.draw_all(game->get_screen());
}
