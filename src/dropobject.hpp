#ifndef DROPOBJECT_HPP
#define DROPOBJECT_HPP

/**
 * @file dropobject.hpp
 **/

#include "collidingobject.hpp"
#include "banquier.hpp"


/**
 * @class DropObject
 * @brief Objets laissés par l'ennemi après sa destruction
 **/
class DropObject: public CollidingObject
{
    public:
    
        /**
         * @brief Constructeur
         **/
        DropObject(const std::string& filename, int z=0, unsigned int montant=2):
                    CollidingObject(filename, z), _montant(montant) {}

        /**
         * @brief Constructeur
         * @param pos Position de l'ennemi
         * @param montant Initialise le montant
         **/
        DropObject(sf::Vector2f pos, unsigned int montant=2):
                    CollidingObject("./media/sac.png", 0), _montant(montant)
        {
            _vy = 50.0f;
            _clock.Reset();
            _sprite.SetPosition(pos);
        }

        /**
         * @brief Gestion de collision
         * @param o Le CollidingObject avec lequelle l'objet est entré en collision
         * @return void* 
         **/
        void * collision(CollidingObject * o);

        void * update(const sf::RenderWindow& fen);

    private:
        unsigned int _montant; ///< Montant
        sf::Clock _clock; ///< Pour régler la temporisation
        float _vy; ///< Vitesse de déplacement
};

#endif
