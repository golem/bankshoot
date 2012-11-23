#include "introstate.hpp"

void IntroState::init()
{
    //~ _bg.LoadFromFile("./media/background.bmp");
    //~ _bg_sprite.SetImage(_bg);
    _background = new Background("./media/intro_background.png", 0);

    /* faire en sorte que le centre de rotation est en bas au milieu */
    _background->set_center(SCREEN_WIDTH / 2, SCREEN_HEIGHT);
    //~ _objects += new Background("./media/icone.bmp", 0);
}

void IntroState::cleanup()
{
    //~ _objects.delete_all();
    if (_background != NULL) {
        delete _background;
        _background = NULL;
    }
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
            game->change_state("Play");
        }
    }
}

void IntroState::update(Engine * game)
{
    //~ _objects.update_all(game->get_screen());
    float dt = game->get_screen().GetFrameTime();

    float angle = _vr * dt;
    _background->rotation(angle);
}

void IntroState::draw(Engine * game) const
{
    //~ game->get_screen().Draw(_bg_sprite);
    //~ _objects.draw_all(game->get_screen());
    _background->draw(game->get_screen());
}
