#include "introstate.hpp"

void IntroState::init()
{
    //~ _bg.LoadFromFile("./media/background.bmp");
    //~ _bg_sprite.SetImage(_bg);
    _objects += new VisibleObject("./media/background.bmp");
    _objects += new VisibleObject("./media/icone.bmp");
}

void IntroState::cleanup()
{
    _objects.delete_all();
}

void IntroState::handle_events(Engine * game)
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
        // Appui sur Espace : on passe à l'état jeu
        if ((evenement.Type == sf::Event::KeyPressed) && (evenement.Key.Code == sf::Key::Space)) {
            game->change_state(game->get_state("Play"));
        }
    }
}

void IntroState::update(Engine * game)
{
    
}

void IntroState::draw(Engine * game) const
{
    //~ game->get_screen().Draw(_bg_sprite);
    _objects.draw_all(game->get_screen());
}
