#include "fpscounter.hpp"

void FPSCounter::draw(sf::RenderWindow& fen) const
{
    fen.Draw(_texte);
}

void FPSCounter::update(const sf::RenderWindow& fen)
{
    // Un entier suffit, pas besoin de plus de précision...
    int freq = 1.0f/fen.GetFrameTime();
    std::ostringstream os;
    os << freq;
    _texte.SetText(os.str());
}
