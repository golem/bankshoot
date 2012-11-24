#include "enemyfactory.hpp"

int EnemyFactory::_level = 1;
bool EnemyFactory::_boss_added = false;
int EnemyFactory::_enemi_count = 0;

Enemy* EnemyFactory::generate(Banquier *banquier)
{
    if ((_clock.GetElapsedTime() < NEXT_ENEMY_TIME) || (_boss_added == true))
        return NULL;

    Enemy *enemy = NULL;
    Enemy_type type = _random_type();

    _clock.Reset();
    if (type == mafia)
        enemy = new Mafia("media/mafia.png");

    else if (type == client)
        enemy = new Client("media/client.png");

    else if (type == boss) {
        _boss_added = true;
        enemy = new Boss("media/boss.png", banquier, _level);
    }

    else if (type == thief)
        enemy = new Voleur("media/voleur.png");

    enemy->set_position(sf::Randomizer::Random(0, (int) (SCREEN_WIDTH - enemy->get_size().x)), 0);
    return enemy;
}

EnemyFactory::Enemy_type EnemyFactory::_random_type()
{
    // TODO: Je ne sais pas si je fais ça bien, il faudrait que tu vérifies, Chengwu !
    if (_enemi_count >= NUM_ENEMY_PER_LEVEL + _level) {
        //~ _boss_added = true;
        _enemi_count =  0;
        return boss;
    }
    ++_enemi_count;

    if (sf::Randomizer::Random(0, 100) < PROPA_CLIENT) return client;
    else if (sf::Randomizer::Random(0, 100) < PROPA_MAFIA) return mafia;
    else return thief;
}

//~ float EnemyFactory::get_last_enemy_time()
//~ {
    //~ if (_boss_added == false)
        //~ return _clock.GetElapsedTime();
    //~ return 0.0f;
//~ }
