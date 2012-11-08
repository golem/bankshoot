#ifndef BANQUIER_HPP
#define BANQUIER_HPP


/**
 * @file banquier.hpp
 * @brief Contient la classe contrôlée par le joueur.
 */

#include "constants.hpp"
#include "collidingobject.hpp"
#include "enemy.hpp"

/**
 * @brief Le personnage principal : un banquier qui défend la banque.
 **/
class Banquier: public CollidingObject
{
    public:
        /**
         * @brief Constructeur.
         *
         * @param filename Le chemin de l'image à utiliser.
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 10.)
         **/
        Banquier(const std::string& filename, int z=10) : CollidingObject(filename, z), _vx(400.0f), _vy(400.0f),
                                                          _masque_face(0, 0, 31, 43), _masque_dos(32, 0, 63, 43)
        {
           //TODO: Vitesses et position arbitraires, sûrement à changer, plus tard
           _sprite.SetSubRect(_masque_dos);
           _sprite.SetPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT);
        }
        
        /**
         * @brief Déplace le banquier en fonction des touches appuyées.
         *
         * @param fen La fenêtre de rendu.
         * @return void
         **/
        void update(const sf::RenderWindow& fen);
        
        void collision(CollidingObject * o);
        
    private:
        float _vx;
        float _vy;
        const sf::IntRect _masque_face, _masque_dos; ///< Masques pour extraire le bon sprite de la sprite sheet
};

#endif /* BANQUIER_HPP */ 
