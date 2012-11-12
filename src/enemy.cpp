#include "enemy.hpp"

void* Enemy::update(const sf::RenderWindow& fen)
{
    sf::Vector2f size = _sprite.GetSize();
    sf::Vector2f pos = _sprite.GetPosition();
    
    // On meurt si on sort de l'écran (comportement commun à tous les ennemis, a priori)
    //~ if ((pos.x < 0.0f) || (pos.y < 0.0f) ||
        //~ (pos.x > fen.GetWidth() - size.x) || (pos.y > fen.GetHeight() - size.y)) {
    if ((pos.x <  -size.x) || (pos.y <  -size.y) ||
        (pos.x > fen.GetWidth()) || (pos.y > fen.GetHeight())) {
        _die();
    }
    
    return NULL;
}

void Enemy::collision(CollidingObject * o)
{
    Banquier * autre = dynamic_cast<Banquier*>(o);
    if (autre != NULL) {
        _die();
    }
}
