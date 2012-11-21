#include "boss.hpp"

void* Boss::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    sf::Vector2f pos = _sprite.GetPosition();
    sf::Vector2f size = _sprite.GetSize();

    pos.y = 0.0f;
    pos.x += _vx*dt;

    // Déplace horizontalement
    if ((pos.x >= SCREEN_WIDTH - size.x) || (pos.x <= 0))
        _vx = -_vx;
    
    _sprite.SetPosition(pos);

    _last_shot += dt;
    // Lancer des pièces dans la direction du banquier
    if (_last_shot > BOSS_SHOT_DELAY) {
        _last_shot = 0.0f;
        sf::Vector2f target = _banquier->get_position();
        return new Projectile(
            "media/gold.png",
            pos.x,
            pos.y,
            Projectile::enemy,
            (target.y-pos.y) / (200 * dt),
            (target.x-pos.x) / (200 * dt)
        );
    }
    return NULL;
}

void* Boss::collision(CollidingObject * o)
{
    Projectile* autre = dynamic_cast<Projectile*>(o);
    if ((autre != NULL) && (autre->get_shot_id() == Projectile::banker)){
        --_life;
    }

    // Meure si ses points de vie tombent à 0
    if (_life <= 0)
        _die();

    return NULL;
}
