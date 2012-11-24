#include "projectile.hpp"

void* Projectile::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    // Tirer en ligne droite... trop simpliste ??
    _sprite.Move(_vx*dt, _vy*dt);
    
//     sf::Vector2f size = _sprite.GetSize();
    sf::Vector2f pos = _sprite.GetPosition();
    
    if ((pos.y > fen.GetHeight()) || (pos.y + _sprite.GetSize().y < 0) ) {
        _die(); // le projectile est détruit
    }
    
    return NULL;
}

void* Projectile::collision(CollidingObject * o)
{
    /* Les projectiles ne se détruisent que s'ils touchent l'adversaire */
    //~ Enemy * target = dynamic_cast<Enemy*>(o);
    if ((dynamic_cast<Enemy*>(o) != NULL) && (_id == banker)) {
        _die();
    }
    //~ Banquier * autre = dynamic_cast<Banquier*>(o);
    if ((dynamic_cast<Banquier*>(o) != NULL) && (_id == enemy)) {
        _die();
    }
    return NULL;
}
