#include "scoredisplay.hpp"

void ScoreDisplay::draw(sf::RenderWindow& fen) const
{
    fen.Draw(_text);
}

void* ScoreDisplay::update(const sf::RenderWindow& fen)
{
    fen.GetFrameTime();
    if (_banquier != NULL) {
        std::ostringstream stream;
        stream << "Score : " << _banquier->get_score() << std::endl;
        stream << "Vie :" << _banquier->get_life();
        _text.SetText(stream.str());
    }
    return NULL;
}
