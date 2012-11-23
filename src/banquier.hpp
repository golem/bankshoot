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
                                                          _score(INITIAL_SCORE), _life(BANKER_LIFE), _invincible(false),
                                                          _invincible_duration(BANKER_INVINCIBLE_DURATION), _blink_period(BANKER_BLINK_PERIOD),
                                                          _knockback(BANKER_KNOCKBACK), _last_hit(0.0f), _last_blink(0.0f),
                                                          _transparent(255,255,255,0), _couleur_normale(sf::Color::White)
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
         * @brief Connaître le nombre de point de vie restant
         * @return Nombre de point de vie restant
         */
        int get_life() const { return _life; }
        
        /**
         * @brief Retourne vrai si l'objet doit être considéré comme invincible.
         *
         * @return bool
         **/
        inline bool is_invincible() const { return _invincible; }

    private:
        float _vx; ///< Vitesse en x
        float _vy; ///< Vitesse en y
        
        const sf::IntRect _masque_face; ///< Masque pour extraire le bon sprite de la sprite sheet.
        const sf::IntRect _masque_dos; ///< Masque pour extraire le bon sprite de la sprite sheet.
        bool _facing_up; ///< Détermine le bon sprite à afficher.
        
        float _last_shot; ///< Temps du dernier tir.
        const float _shot_delay; ///< Délai entre chaque tir.
        
        int _score; ///< Score actuel.
        int _life; ///< Point de vie.
        
        bool _invincible; ///< Si vrai, le banquier clignotera et ne subira pas de collision.
        const float _invincible_duration; ///< Temps durant lequel le banquier est invincible après un coup.
        const float _blink_period; ///< Période du clignotement du banquier après qu'il ait été touché.
        const float _knockback; ///< Recul lors d'un choc.
        float _last_hit; ///< Temps depuis le dernier coup subi par le banquier.
        float _last_blink; ///< Temps depuis le dernier clignotement du banquier.
        const sf::Color _transparent; ///< Couleur transparente, utilisée pour faire clignoter le sprite.
        const sf::Color _couleur_normale; ///< Couleur normale, utilisée pour faire clignoter le sprite.
        
        /**
         * @brief Méthode appelée lorsque le banquier se fait toucher par un ennemi ou projectile.
         * 
         * @return void
         */
        void _get_hit();
        
        /**
         * @brief Si le banquier est visible, le rend invisible. Et vice et versa.
         * 
         * @return void
         */
        void _toggle_color();
};

#endif /* BANQUIER_HPP */ 
