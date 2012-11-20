#ifndef BOSS_HPP
#define BOSS_HPP

/**
 * @file boss.hpp
 * @brief Boss du jeu
 */

#include "enemy.hpp"
#include "banquier.hpp"
#include "constants.hpp"

/**
 * @class Boss
 * @brief Ennemi plus difficile à tuer
 */
class Boss: public Enemy
{
    public:
        Boss(const std::string& filename, Banquier *banquier):
            Enemy(filename),
            _life(BOSS_LIFE),
            _banquier(banquier),
            _shot_delay(BOSS_SHOT_DELAY),
            _last_shot(0.0f)
        {
            _vx = BOSS_SPEED;
            //~ _sprite.SetCenter(_sprite.GetSize().x / 2, 0.0f);
        }

        ~Boss() {}
        
        void* update(const sf::RenderWindow& fen);

        void* collision(CollidingObject * o);

    private:
        int _life; ///< Point de vie du boss
        Banquier *_banquier; ///< Pointeur sur banquier, pour connaître la direction des tirs
        float _shot_delay; ///< Délai entre deux tirs
        float _last_shot; ///< Temps
};

#endif
