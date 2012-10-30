#include "visibleobject.hpp"

void VisibleObject::draw(sf::RenderWindow& fen) const
{
    fen.Draw(_sprite);
}

void VisibleObject::update(const sf::RenderWindow& fen)
{
    
}
