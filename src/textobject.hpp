#ifndef TEXTOBJECT_HPP
#define TEXTOBJECT_HPP

/**
 * @file textobject.hpp
 * @brief Gestion des objets textuels
 */

#include <string>
#include <sstream>

#include "visibleobject.hpp"
#include "constants.hpp"

/**
 * @brief Classe de base des objets affichant un texte.
 **/
class TextObject : public VisibleObject
{
    public:

        /**
         * @brief Constructeur.
         * 
         * Ce constructeur place le niveau Z de l'objet à une valeur assez haute
         * pour être au dessus de tous les autres objets.
         *
         * @param filename Chemin de la police à utiliser.
         * @param initial_text Texte à afficher initialement, utile pour régler la position de l'objet.
         * @param center_h Vrai pour centrer horizontalement le texte initial.
         * @param center_v Vrai pour centrer verticalement le texte initial.
         * @param coller_en_bas Vrai pour placer le texte en bas de la fenêtre.
         * (ces 3 booleéns pourraient être mieux implémentés... Grâce à un enum par exemple)
         * @param z Z-level. Valeur par défaut associée à 50.
         **/
        TextObject(const std::string& filename, const sf::Unicode::Text& initial_text,
                   bool center_h=false, bool center_v=false, bool coller_en_bas=false, int z = 50) : VisibleObject(z),
                                              _font(ResourceManager::get_font(filename))
        {
            _texte.SetFont(*_font);
            _texte.SetText(initial_text);
            _center(center_h, center_v);
            if (coller_en_bas)
                _texte.SetY(SCREEN_HEIGHT-_texte.GetRect().GetHeight());;
        }
        
        /**
         * @brief Destructeur (virtuel pour pouvoir hériter).
         *
         **/
        virtual ~TextObject() { }

        virtual void* update(const sf::RenderWindow& fen) { fen.GetFrameTime(); return NULL; }
        void draw(sf::RenderWindow& fen) const { fen.Draw(_texte); }

        /**
         * @brief Changer la couleur
         * @param col Référence sur une couleur
         */
        void set_color(const sf::Color& col) { _texte.SetColor(col); }

    protected:

        /**
         * @brief Police utilisée pour afficher le texte.
         * 
         * C'est un pointeur vers un objet géré par le ResourceManager.
         **/
        sf::Font * _font;
        sf::String _texte; ///< Texte à afficher.

        /**
         * @brief Fonction permettant de centrer un texte.
         *
         * @param h Vrai pour centrer horizontalement le texte.
         * @param v Vrai pour centrer verticalement le texte.
         * @return void
         **/
        void _center(bool h, bool v)
        {
            if (h)
                _texte.SetX(SCREEN_WIDTH/2 - _texte.GetRect().GetWidth()/2);
            if (v)
                _texte.SetY(SCREEN_HEIGHT/2 - _texte.GetRect().GetHeight()/2);
        }
};

#endif // TEXTOBJECT_HPP
