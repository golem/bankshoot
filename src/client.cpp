#include "client.hpp"

void* Client::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    sf::Vector2f pos = _sprite.GetPosition();
    sf::Vector2f size = _sprite.GetSize();
    
    pos.y += _vy*dt;
    pos.x += _vx*dt*sin(pos.y*3.14159f/180.0f);
    _sprite.SetPosition(pos);
    
    // Contrairement aux autres ennemis, on ne meurt pas en sortant
    //sur les côtés de l'écran, ça serait un peu dommage je pense.
    if ((pos.y <  -size.y) || (pos.y > fen.GetHeight())) {
        _die();
    }
    return NULL;
}