#include "voleur.hpp"

void Voleur::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    // Mouvement linéaire uniforme, on peut difficilement faire plus simple
    _sprite.Move(_vx*dt, _vy*dt);
    
    // Comportement de la super-classe : mourir si on est en dehors de l'écran
    Enemy::update(fen);
}
