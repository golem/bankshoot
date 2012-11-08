#include "enemyfactory.hpp"
#include "voleur.hpp"
#include "constants.hpp"

Enemy* EnemyFactory::generate() const
{
    Enemy *enemy;

    Enemy_type type = random_type();

    if (type == thief) {
        enemy = new Voleur("./media/voleur.png");
        enemy->set_position(rand() % (int) (SCREEN_WIDTH - enemy->get_size().x / 2), 0);
    }
    else if (type == mafia) {
        enemy = new Voleur("./media/mafia.png");
        enemy->set_position(rand() % (int) (SCREEN_WIDTH - enemy->get_size().x / 2), 0);
    }

    return enemy;
}

EnemyFactory::Enemy_type EnemyFactory::random_type() const
{
    if ((rand() % PROPA_MAFIA) == 0) return mafia;
    else return thief;
}
