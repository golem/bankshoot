#include "mafia.hpp"

void* Mafia::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    // Mouvement linéaire uniforme, on peut difficilement faire plus simple
    _sprite.Move(_vx * dt, _vy * dt);
    _elapsed_time += dt;
    
    // Comportement de la super-classe : mourir si on est en dehors de l'écran
    Enemy::update(fen);
    
    if (_elapsed_time > _shot_delay) {
        _elapsed_time = 0.0f;
        return new Projectile("media/munition.png",
                              _sprite.GetPosition().x, _sprite.GetPosition().y,
                              Projectile::enemy, MAFIA_SHOT_SPEED,
                              sf::Randomizer::Random(- (int) MAFIA_SHOT_SPEED, (int) MAFIA_SHOT_SPEED));
    }
    return NULL;
}
