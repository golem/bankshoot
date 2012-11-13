#ifndef DROPOBJECT_HPP
#define DROPOBJECT_HPP

/**
 * @file dropobject.hpp
 **/

#include "collidingobject.hpp"
#include "banquier.hpp"

class DropObject: public CollidingObject
{
    public:
        DropObject(const std::string& filename, int z=0, unsigned int montant=2):
                    CollidingObject(filename, z), _montant(montant) {}

        DropObject(sf::Vector2f pos, unsigned int montant=2):
                    CollidingObject("./media/sac.png", 0), _montant(montant)
        {
            _sprite.SetPosition(pos);
        }

        void * collision(CollidingObject * o);

        void * update(const sf::RenderWindow& fen);

    private:
        unsigned int _montant;
};

#endif
