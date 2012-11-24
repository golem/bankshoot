#include "scoredisplay.hpp"
#include "enemyfactory.hpp"

void* ScoreDisplay::update(const sf::RenderWindow& fen)
{
    fen.GetFrameTime();
    if (_banquier != NULL) {
        std::ostringstream stream;
        stream << "Capital : " << _banquier->get_score() << "$" << std::endl;
        stream << "Vie : " << _banquier->get_life() << std::endl;
        stream << "Niveau : " << EnemyFactory::level(); 
        _texte.SetText(stream.str());
    }
    return NULL;
}
