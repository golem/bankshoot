#include "client.hpp"

void* Client::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    sf::Vector2f pos = _sprite.GetPosition();
    sf::Vector2f size = _sprite.GetSize();

    pos.y += _vy*dt;
    pos.x += _vx*dt*sin(pos.y*3.14159f/180.0f);
    _sprite.SetPosition(pos);

    // petite animation, pour voir de la fumée qui sort par les oreilles
    if ((_elapsed_time += dt) > 0.2f) {
        _mood = !_mood;
        if (_mood == true) _sprite.SetSubRect(_masque_normal);
        else _sprite.SetSubRect(_masque_angry);
        //~ _sprite.SetCenter(_sprite.GetSize().x / 2, _sprite.GetSize().y / 2);
        _elapsed_time = 0.0f;
    }

    // Contrairement aux autres ennemis, on ne meurt pas en sortant
    //sur les côtés de l'écran, ça serait un peu dommage je pense.
    if ((pos.y <  -size.y) || (pos.y > fen.GetHeight())) {
        _die();
    }
    return NULL;
}
