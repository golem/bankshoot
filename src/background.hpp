#ifndef REPEATINGOBJECT_HPP
#define REPEATINGOBJECT_HPP

/**
 * @file background.hpp
 * @brief Gestion des images de fond.
 */

#include "visibleobject.hpp"
#include "constants.hpp"

enum background_side {center, right, left};

/**
 * @brief Classe permettant d'avoir une image de fond défilante (ou non).
 **/
class Background: public VisibleObject
{
    public:
        /**
         * @brief Constructeur permettant de définir la vitesse de défilement du fond.
         *
         * @param filename Chemin de l'image devant servir de fond.
         * @param vitesse Vitesse de défilement du fond.
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à -1,
         * pour être sûr que le fond est bien dessiné avant les autres objets.)
         **/
        Background(const std::string& filename, int vitesse, int z=-2, background_side side=center):
            VisibleObject(filename, z), _vitesse(vitesse), _side(side)
        {
            _sprite_bis.SetImage(*_img);

            //~ _position[0] = -(float) _img->GetHeight();
            //~ _position[1] = 0.0f;

            _position[0] = -(float) SCREEN_HEIGHT/2;
            _position[1] = 0.0f;

        }

        virtual void update(const sf::RenderWindow& fen);
        void draw(sf::RenderWindow& fen) const;

    protected:
        int _vitesse; ///< Vitesse à laquelle le fond défile.
        sf::Sprite _sprite_bis; ///< Deuxième vue sur l'image.
        float _position[2]; ///< Tableau retenant la position des deux sprites.
        background_side _side;
};

#endif /* REPEATINGOBJECT_HPP */ 
