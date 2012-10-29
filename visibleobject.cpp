#include "visibleobject.hpp"

void VisibleObject::draw(sf::RenderWindow& fen) const
{
    fen.Draw(_sprite);
}
