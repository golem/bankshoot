#ifndef FPSCOUNTER_HPP
#define FPSCOUNTER_HPP

/**
 * @file fpscounter.hpp
 * @brief Affichage de la fréquence de rafraichissement.
 */

#include "textobject.hpp"

/**
 * @brief Objet permettant d'afficher le nombre d'images par seconde de l'application.
 **/
class FPSCounter: public TextObject
{
    public:
        /**
         * @brief Constructeur.
         *
         * @param filename Chemin vers la police à utiliser.
         **/
        FPSCounter(const std::string& filename) : TextObject(filename, "000"),
                                                  _elapsed_time(0.0f), _nb_images(0)
        {
            _texte.SetPosition(SCREEN_WIDTH-_texte.GetRect().GetWidth(), 0*SCREEN_HEIGHT);
        }
        
        /**
         * @brief Met à jour le texte avec le nombre d'images par secondes.
         *
         * @param fen La fenêtre de rendu.
         * @return void*
         **/
        void * update(const sf::RenderWindow& fen);
            
    private:
        float _elapsed_time; ///< Le temps écoulé depuis la dernière mise à jour de l'affichage du compteur.
        int _nb_images; ///< Le nombre d'images dessinées depuis la dernière mise à jour de l'affichage du compteur.
};

#endif /* FPSCOUNTER_HPP */ 
