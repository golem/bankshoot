#include "fpscounter.hpp"

void FPSCounter::draw(sf::RenderWindow& fen) const
{
    fen.Draw(_texte);
}

//~ void FPSCounter::update(const sf::RenderWindow& fen)
//~ {
    //~ // Un entier suffit, pas besoin de plus de précision...
    //~ int freq = 1.0f/fen.GetFrameTime();
    //~ std::ostringstream os;
    //~ os.width(3);
    //~ os << freq;
    //~ _texte.SetText(os.str());
//~ }
void* FPSCounter::update(const sf::RenderWindow& fen)
{
    _elapsed_time += fen.GetFrameTime();
    // Moyennage : toutes les secondes, on affiche le nombre de frames calculées
    if (_elapsed_time >= 1.0f) {
        std::ostringstream os;
        os.width(3);
        os << _nb_images;
        _texte.SetText(os.str());
        _elapsed_time = 0.0f;
        _nb_images = 0;
    }
    else ++_nb_images;
    
    return NULL;
}
