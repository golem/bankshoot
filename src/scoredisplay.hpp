#ifndef SCORE_DISPLAY_HPP
#define SCORE_DISPLAY_HPP

/**
 * @file scoredisplay.hpp
 **/

#include "textobject.hpp"
#include "banquier.hpp"

/**
 * @class ScoreDisplay
 * @brief Gestion des données à afficher
 */
class ScoreDisplay: public TextObject
{
    public:
    
        /**
         * @brief Constructeur
         * @param filename
         * @param banquier
         */
        ScoreDisplay(const std::string& filename, Banquier *banquier):
                    TextObject(filename, "Capital :"),
                    _banquier(banquier)
        {
            _texte.SetFont(*_font);
            _texte.SetText("Capital :");
            _texte.SetPosition(0, 0);
        }

        /**
         * @brief Destructeur
         */
        ~ScoreDisplay() {}

        void * update(const sf::RenderWindow& fen);

    private:
        Banquier *_banquier; ///< Pointeur sur le banquier
};

#endif
