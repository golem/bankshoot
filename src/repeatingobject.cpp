#include "repeatingobject.hpp"

void RepeatingObject::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    std::cout << dt << std::endl;
    // Il faudrait, dans update, mettre à jour la position du défilement
    // Et dans draw, dessiner comme il faut, avec des setsubsect, etc.
    //~ _sprite.Move(0.0f, dt*100);
    //~ int toto = _sprite.GetSubRect().GetHeight()-dt*10;
    //~ std::cout << toto << std::endl;
    //~ _sprite.SetSubRect(sf::IntRect(0,0,50,toto));
}

void RepeatingObject::draw(sf::RenderWindow& fen) const
{
    fen.Draw(_sprite);
}
