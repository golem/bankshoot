#include "projectile.hpp"

void* Projectile::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    // Tirer en ligne droite... trop simpliste ??
    _sprite.Move(0.0f, _vy*dt);
    
//     sf::Vector2f size = _sprite.GetSize();
    sf::Vector2f pos = _sprite.GetPosition();
    
    if ((pos.y > fen.GetHeight()) || (pos.y < 0) ) {
        _die(); // le projectile est détruit
    }
    
    return NULL;
}

void Projectile::collision(CollidingObject * o)
{
    Enemy * autre = dynamic_cast<Enemy*>(o);
    if (autre != NULL) {
        _die();
    }
}