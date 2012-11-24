#ifndef DAMAGEABLEOBJECT_HPP
#define DAMAGEABLEOBJECT_HPP

/**
 * @file damageableobject.hpp
 * @brief Gestion des objets pouvant subir des dégâts.
 */

#include <SFML/Graphics.hpp>

/**
 * @brief Classe de base pour un objet pouvant subir des dégâts.
 **/
class DamageableObject
{
    public:
        /**
         * @brief Destructeur.
         *
         **/
        virtual ~DamageableObject() { }
        
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
    
    protected:
        /**
         * @brief Constructeur (protégé pour éviter l'instantiation).
         *
         * @param life Points de vie initiaux de l'objet.
         * @param inv_dur Durée de l'invincibilité post-dégâts.
         * @param blink_per Période de clignotement post-dégâts.
         * @param knockback Recul post-dégâts.
         **/
        DamageableObject(int life, float inv_dur, float blink_per, float knockback) :
            _life(life), _invincible(false), _invincible_duration(inv_dur), _blink_period(blink_per),
            _knockback(knockback), _last_hit(0.0f), _last_blink(0.0f),
            _transparent(255,255,255,0), _couleur_normale(sf::Color::White) { }
        
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
         * @brief Méthode appelée lorsque l'objet se fait toucher par un ennemi ou projectile.
         * 
         * @param sprite Le sprite représentant l'objet.
         * @return void
         */
        void _get_hit(sf::Sprite& sprite);
        
        /**
         * @brief Si l'objet est visible, le rend invisible. Et vice et versa.
         *
         * @param sprite Le sprite représentant l'objet.
         * @return void
         **/
        void _toggle_color(sf::Sprite& sprite);
        
        /**
         * @brief Fait clignoter un sprite si l'objet est invincible.
         *
         * @param sprite Le sprite à faire clignoter.
         * @param dt Le temps écoulé depuis la dernière mise à jour.
         * @return void
         **/
        void _handle_invincible(sf::Sprite& sprite, float dt);
};

#endif // DAMAGEABLEOBJECT_HPP
