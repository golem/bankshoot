#include "enemy.hpp"
#include "enemyfactory.hpp"

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

void* Enemy::collision(CollidingObject * o)
{
    Banquier * banquier = dynamic_cast<Banquier*>(o);
    if ((banquier != NULL) && (!banquier->is_invincible())) {
        _die();
        return NULL;
    }
    Projectile * proj = dynamic_cast<Projectile*>(o);
    if ((proj != NULL) && (proj->get_shot_id() == Projectile::banker)) {
        _die();
        return new DropObject(_sprite.GetPosition(), CASH + sf::Randomizer::Random(1, EnemyFactory::level()));
    }
    return NULL;
}
