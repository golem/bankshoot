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
    return NULL;
}
