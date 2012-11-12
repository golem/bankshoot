#ifndef FPSCOUNTER_HPP
#define FPSCOUNTER_HPP

/**
 * @file fpscounter.hpp
 * @brief Affichage de la fréquence de rafraichissement.
 */

#include <string>
#include <sstream>

#include "visibleobject.hpp"
#include "constants.hpp"

/**
 * @brief Objet permettant d'afficher le nombre d'images par seconde de l'application.
 **/
class FPSCounter: public VisibleObject
{
    public:
        /**
         * @brief Constructeur.
         *
         * @param filename Chemin vers la police à utiliser.
         * 
         * Ce constructeur place le niveau Z de l'objet à une valeur assez haute
         * pour être au dessus de tous les autres objets.
         **/
        FPSCounter(const std::string& filename) : VisibleObject(50),
                            _font(ResourceManager::get_font(filename)),
                            _elapsed_time(0.0f), _nb_images(0)
        {
            _texte.SetFont(*_font);
            _texte.SetText("000");
            _texte.SetPosition(SCREEN_WIDTH-_texte.GetRect().GetWidth(), 0*SCREEN_HEIGHT);
        }
        
        void draw(sf::RenderWindow& fen) const;
        void * update(const sf::RenderWindow& fen);
            
    private:
        /**
         * @brief Police utilisée pour afficher la fréquence de rafraichissement.
         * 
         * C'est un pointeur vers un objet géré par le ResourceManager.
         **/
        sf::Font * _font;
        sf::String _texte; ///< Texte à afficher.
        float _elapsed_time; ///< Le temps écoulé depuis la dernière mise à jour de l'affichage du compteur.
        int _nb_images; ///< Le nombre d'images dessinées depuis la dernière mise à jour de l'affichage du compteur.
};

#endif /* FPSCOUNTER_HPP */ 
