#ifndef ENEMY_FACTORY_HPP
#define ENEMY_FACTORY_HPP

#include "enemy.hpp"

#include <cstdlib>
#include <ctime>

class EnemyFactory
{
    public:
        enum Enemy_type { thief };

        EnemyFactory(): _has_enemy(false) { srand(time(NULL)); }
        ~EnemyFactory() {}
        
        Enemy* generate(Enemy_type type);

        static const int PROBABILITY = 100;

        void check();
        bool has_enemy()
        {
            check();
            return _has_enemy;
        }
        Enemy_type get_type() const { return _type; }

    private:
        bool _has_enemy;
        Enemy_type _type;
};

#endif
