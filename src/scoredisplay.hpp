#ifndef SCORE_DISPLAY_HPP
#define SCORE_DISPLAY_HPP

/**
 * @file scoredisplay.hpp
 **/

#include <sstream>

#include "banquier.hpp"


/**
 * @class ScoreDisplay
 */
class ScoreDisplay: public VisibleObject {
    public:
        ScoreDisplay(const std::string& filename, Banquier *banquier):
                    VisibleObject(50),
                    _banquier(banquier),
                    _font(ResourceManager::get_font(filename))
        {
            _text.SetFont(*_font);
            _text.SetText("Score :");
            _text.SetPosition(0, 0);
        }

        ~ScoreDisplay() {}

        void draw(sf::RenderWindow& fen) const;
        void * update(const sf::RenderWindow& fen);


    private:
        Banquier *_banquier; ///< Pointeur sur le banquier
        sf::Font *_font; ///< Font du texte
        sf::String _text; ///< Texte à afficher

};

#endif
