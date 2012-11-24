#include "scoredisplay.hpp"
#include "enemyfactory.hpp"

void ScoreDisplay::draw(sf::RenderWindow& fen) const
{
    fen.Draw(_text);
}

void* ScoreDisplay::update(const sf::RenderWindow& fen)
{
    fen.GetFrameTime();
    if (_banquier != NULL) {
        std::ostringstream stream;
        stream << "Capital : " << _banquier->get_score() << "$" << std::endl;
        stream << "Vie : " << _banquier->get_life() << std::endl;
        stream << "Niveau : " << EnemyFactory::level(); 
        _text.SetText(stream.str());
    }
    return NULL;
}
