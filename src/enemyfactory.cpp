#include "enemyfactory.hpp"
#include "voleur.hpp"

Enemy* EnemyFactory::generate(Enemy_type type)
{
    if (type == thief) {
        _has_enemy = false;
        return new Voleur("./media/icone.bmp");
    }
    else
        return NULL;
}

void EnemyFactory::check()
{
    if (rand() % PROBABILITY == 0) {
        _has_enemy = true;
        _type = thief;
    }
}
