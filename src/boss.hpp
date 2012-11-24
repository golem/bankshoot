#ifndef BOSS_HPP
#define BOSS_HPP

/**
 * @file boss.hpp
 * @brief Boss du jeu
 */

#include "enemy.hpp"
#include "banquier.hpp"
#include "constants.hpp"

#include <cmath>
/**
 * @class Boss
 * @brief Ennemi plus difficile à tuer
 */
class Boss: public Enemy, public DamageableObject
{
    public:

        /**
         * @brief Constructeur
         * @param filename
         * @param banquier
         * @param level
         */
        Boss(const std::string& filename, Banquier *banquier, int level):
            Enemy(filename),
            DamageableObject(BOSS_LIFE + level, BOSS_INVINCIBLE_DURATION, BOSS_BLINK_PERIOD, BOSS_KNOCKBACK),
            _banquier(banquier),
            _shot_delay(BOSS_SHOT_DELAY / log((float) level + 1.0f)),
            _shot_speed(BOSS_SHOT_SPEED / log((float) level + 1.0f)),
            _last_shot(0.0f)
        {
            _vx = BOSS_SPEED + level / 10.0f;
            //~ _sprite.SetCenter(_sprite.GetSize().x / 2, 0.0f);
        }

        ~Boss() {}
        
        void* update(const sf::RenderWindow& fen);

        void* collision(CollidingObject * o);

    private:
        Banquier *_banquier; ///< Pointeur sur banquier, pour connaître la direction des tirs
        float _shot_delay; ///< Délai entre deux tirs
        float _shot_speed;
        float _last_shot; ///< Temps
};

#endif
