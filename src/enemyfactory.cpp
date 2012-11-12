#include "enemyfactory.hpp"
#include "voleur.hpp"
#include "mafia.hpp"
#include "constants.hpp"

Enemy* EnemyFactory::generate() const
{
    Enemy *enemy;

    Enemy_type type = random_type();

    if (type == thief) {
        enemy = new Voleur("./media/voleur.png");
        //~ enemy->set_position(rand() % (int) (SCREEN_WIDTH - enemy->get_size().x), 0);
    }
    else if (type == mafia) {
        enemy = new Mafia("./media/mafia.png");
        //~ enemy->set_position(rand() % (int) (SCREEN_WIDTH - enemy->get_size().x), 0);
    }

    enemy->set_position(sf::Randomizer::Random(0, (int) (SCREEN_WIDTH - enemy->get_size().x)), 0);
    return enemy;
}

EnemyFactory::Enemy_type EnemyFactory::random_type() const
{
    if (sf::Randomizer::Random(0, 100) < PROPA_MAFIA) return mafia;
    else return thief;
}
