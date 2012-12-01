#include "boss.hpp"
#include "enemyfactory.hpp"

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
    
    // Gestion de l'invincibilité
    _handle_invincible(_sprite, dt);

    _last_shot += dt;
    // Lancer des pièces dans la direction du banquier
    if (_last_shot > _shot_delay) {
        _last_shot = 0.0f;
        sf::Vector2f target = _banquier->get_position();
        return new Projectile(
            "media/gold.png",
            pos.x + sf::Randomizer::Random(0, (int) size.x),
            size.y,
            Projectile::enemy,
            (target.y-pos.y) / (_shot_speed * dt),
            (target.x-pos.x) / (_shot_speed * dt)
        );
    }
    return NULL;
}

void* Boss::collision(CollidingObject * o)
{
    if (is_invincible()) return NULL;
    
    Projectile* autre = dynamic_cast<Projectile*>(o);
    if ((autre != NULL) && (autre->get_shot_id() == Projectile::banker)){
        _get_hit(_sprite);
    }

    // Meure si ses points de vie tombent à 0
    if (_life <= 0) {
        EnemyFactory::reset_boss();
        EnemyFactory::next_level();
        _die();
        return new DropObject(_sprite.GetPosition(), CASH + sf::Randomizer::Random(1, EnemyFactory::level()));
    }
    return NULL;
}
