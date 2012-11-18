#ifndef REPEATINGOBJECT_HPP
#define REPEATINGOBJECT_HPP

/**
 * @file background.hpp
 * @brief Gestion des images de fond.
 */

#include "visibleobject.hpp"
#include "constants.hpp"

/**
 * @brief Classe permettant d'avoir une image de fond défilante (ou non).
 **/
class Background: public VisibleObject
{
    public:

        /**
         * @enum background_side
         * @brief Définir la position de l'image à afficher
         */
        enum background_side {
            center, /**< Image au centre */
            right,  /**< Image à droite */
            left    /**< Image à gauche */
        };

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

            _position[0] = -(float) SCREEN_HEIGHT;
            _position[1] = 0.0f;

        }
        
        void * update(const sf::RenderWindow& fen);

        void draw(sf::RenderWindow& fen) const;

        /**
         * @brief Tourner l'image
         * @param angle Angle de rotation
         */
        void rotation(float angle);

        /**
         * @brief Faire correspondre le centre de l'image au point (\a x, \a y)
         * de la fenêtre d'affichage
         * @param x Abscisse de la fenêtre d'affichage
         * @param y Ordonnée de la fenêtre d'affichage
         */
        void set_center(float x, float y);

    protected:
        int _vitesse; ///< Vitesse à laquelle le fond défile.
        sf::Sprite _sprite_bis; ///< Deuxième vue sur l'image.
        float _position[2]; ///< Tableau retenant la position des deux sprites.
        background_side _side; ///< Position du \a Background
};

#endif /* REPEATINGOBJECT_HPP */ 
