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
         * @param z Z-level. Valeur par défaut associée à 50.
         **/
        TextObject(const std::string& filename, const sf::Unicode::Text& initial_text, int z = 50) : VisibleObject(z),
                                              _font(ResourceManager::get_font(filename))
        {
            _texte.SetFont(*_font);
            _texte.SetText(initial_text);
        }
        
        /**
         * @brief Destructeur (virtuel pour pouvoir hériter).
         *
         **/
        virtual ~TextObject() { }
        
        virtual void* update(const sf::RenderWindow& fen) = 0;
        void draw(sf::RenderWindow& fen) const { fen.Draw(_texte); }
        
    protected:
        /**
         * @brief Police utilisée pour afficher le texte.
         * 
         * C'est un pointeur vers un objet géré par le ResourceManager.
         **/
        sf::Font * _font;
        sf::String _texte; ///< Texte à afficher.
};

#endif // TEXTOBJECT_HPP
