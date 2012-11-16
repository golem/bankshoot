#ifndef BANQUIER_HPP
#define BANQUIER_HPP


/**
 * @file banquier.hpp
 * @brief Contient la classe contrôlée par le joueur.
 */

#include "constants.hpp"
#include "collidingobject.hpp"
#include "enemy.hpp"
#include "projectile.hpp"

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
        Banquier(const std::string& filename, int z=10) : CollidingObject(filename, z), _vx(BANKER_SPEED), _vy(BANKER_SPEED),
                                                          _masque_face(0, 0, 31, 43), _masque_dos(32, 0, 63, 43),
                                                          _facing_up(true), _last_shot(0.0f), _shot_delay(BANKER_SHOT_DELAY),
                                                          _score(INITIAL_SCORE)
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
        void * update(const sf::RenderWindow& fen);
        
        void* collision(CollidingObject * o);
        
        int get_score() const { return _score; }
        void add_score(unsigned int montant) { _score += montant; }

    private:
        float _vx;
        float _vy;
        const sf::IntRect _masque_face; ///< Masque pour extraire le bon sprite de la sprite sheet.
        const sf::IntRect _masque_dos; ///< Masque pour extraire le bon sprite de la sprite sheet.
        bool _facing_up;
        float _last_shot;
        const float _shot_delay; // Ou peut être qu'on pourra faire évoluer ce délai en fonction de powerups...
        int _score;
};

#endif /* BANQUIER_HPP */ 
