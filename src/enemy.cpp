#include "enemy.hpp"

void Enemy::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    _sprite.Move(_vx*dt, _vy*dt);
    // TODO: Plutôt faire des sous classes qui auront un comportement particulier ici
    //, et garder cette fonction pour détruire l'ennemy si il sort de l'écran par exemple
}
