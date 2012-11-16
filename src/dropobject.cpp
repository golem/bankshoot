#include "dropobject.hpp"

void * DropObject::collision(CollidingObject *o)
{
    if (dynamic_cast<Banquier*>(o) != NULL) {
        Banquier *autre = dynamic_cast<Banquier*>(o);
        autre->add_score(_montant);
        _die();
    }

    if (dynamic_cast<Enemy*>(o) != NULL) {
        _die();
    }

    return NULL;
}

void * DropObject::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    sf::Vector2f size = _sprite.GetSize();
    sf::Vector2f pos = _sprite.GetPosition();

    _time -= dt;

    if (_time < 0.0f) _sprite.Move(0.0f, _vy*dt);

    // Si l'objet sort de l'écran, il meurt
    if ((pos.x <  -size.x) || (pos.y <  -size.y) ||
        (pos.x > fen.GetWidth()) || (pos.y > fen.GetHeight())) {
        _die();
    }
    
    return NULL;
}
