#include "enemyfactory.hpp"
#include "voleur.hpp"
#include "mafia.hpp"
#include "client.hpp"
#include "constants.hpp"

Enemy* EnemyFactory::generate() const
{
    Enemy *enemy = NULL;

    Enemy_type type = random_type();

    if (type == thief) {
        enemy = new Voleur("media/voleur.png");
        //~ enemy->set_position(rand() % (int) (SCREEN_WIDTH - enemy->get_size().x), 0);
    }
    else if (type == mafia) {
        enemy = new Mafia("media/mafia.png");
        //~ enemy->set_position(rand() % (int) (SCREEN_WIDTH - enemy->get_size().x), 0);
    }
    else if (type == client) {
        // TODO: Changer l'image
        enemy = new Client("media/icone.bmp");
    }

    enemy->set_position(sf::Randomizer::Random(0, (int) (SCREEN_WIDTH - enemy->get_size().x)), 0);
    return enemy;
}

EnemyFactory::Enemy_type EnemyFactory::random_type() const
{
    // TODO: Je ne sais pas si je fais ça bien, il faudrait que tu vérifies, Chengwu !
    if (sf::Randomizer::Random(0, 100) < PROPA_CLIENT) return client;
    else if (sf::Randomizer::Random(0, 100) < PROPA_MAFIA) return mafia;
    else return thief;
}
