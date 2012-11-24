#ifndef BANQUIER_HPP
#define BANQUIER_HPP


/**
 * @file banquier.hpp
 * @brief Contient la classe contrôlée par le joueur.
 */

#include "constants.hpp"
#include "collidingobject.hpp"
#include "damageableobject.hpp"
#include "enemy.hpp"
#include "projectile.hpp"

/**
 * @brief Le personnage principal : un banquier qui défend la banque.
 **/
class Banquier: public CollidingObject, public DamageableObject
{
    public:
        /**
         * @brief Constructeur.
         *
         * @param filename Le chemin de l'image à utiliser.
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 10.)
         **/
        Banquier(const std::string& filename, int z=10) : CollidingObject(filename, z),
                                            DamageableObject(BANKER_LIFE, BANKER_INVINCIBLE_DURATION, BANKER_BLINK_PERIOD, BANKER_KNOCKBACK),
                                                          _vx(BANKER_SPEED), _vy(BANKER_SPEED),
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
        
        /**
         * @brief Connaître le score
         */
        int get_score() const { return _score; }
        
        /**
         * @brief Augmenter le score
         */
        void add_score(unsigned int montant) { _score += montant; }
        
        /**
         * @brief Vérifier si le banquier a perdu le jeu.
         *
         * @return bool : Vrai si le banquier n'a plus de vie.
         **/
        bool a_perdu() const { return (_life <= 0); }

    private:
        float _vx; ///< Vitesse en x
        float _vy; ///< Vitesse en y
        
        const sf::IntRect _masque_face; ///< Masque pour extraire le bon sprite de la sprite sheet.
        const sf::IntRect _masque_dos; ///< Masque pour extraire le bon sprite de la sprite sheet.
        bool _facing_up; ///< Détermine le bon sprite à afficher.
        
        float _last_shot; ///< Temps du dernier tir.
        const float _shot_delay; ///< Délai entre chaque tir.
        
        int _score; ///< Score actuel.
};

#endif /* BANQUIER_HPP */ 
