#include "enemyfactory.hpp"

Enemy* EnemyFactory::generate(Banquier *banquier)
{
    Enemy *enemy = NULL;

    Enemy_type type = random_type();

    if (type == mafia)
        enemy = new Mafia("media/mafia.png");

    else if (type == client)
        enemy = new Client("media/client.png");

    else if (type == boss)
        enemy = new Boss("./media/boss.png", banquier);

    else
        enemy = new Voleur("media/voleur.png");

    enemy->set_position(sf::Randomizer::Random(0, (int) (SCREEN_WIDTH - enemy->get_size().x)), 0);
    return enemy;
}

EnemyFactory::Enemy_type EnemyFactory::random_type()
{
    // TODO: Je ne sais pas si je fais ça bien, il faudrait que tu vérifies, Chengwu !
    if (_enemi_count >= NUM_ENEMY_PER_LEVEL) {
        _boss_added = true;
        _enemi_count =  0;
        return boss;
    }
    ++_enemi_count;

    if (sf::Randomizer::Random(0, 100) < PROPA_CLIENT) return client;
    else if (sf::Randomizer::Random(0, 100) < PROPA_MAFIA) return mafia;
    else return thief;
}

float EnemyFactory::get_last_enemy_time()
{
    if (_boss_added == false)
        return _clock.GetElapsedTime();
    return 0.0f;
}
