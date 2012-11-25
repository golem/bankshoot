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
         * @param side Position de l'image, par défaut placer l'image au centre
         **/
        Background(const std::string& filename, int vitesse, int z=-1, background_side side=center):
            VisibleObject(filename, z), _vitesse(vitesse), _side(side), _suppr_img(false)
        {
            _sprite_bis.SetImage(*_img);

            //~ _position[0] = -(float) _img->GetHeight();
            //~ _position[1] = 0.0f;

            _position[0] = -(float) SCREEN_HEIGHT;
            _position[1] = 0.0f;

        }
        
        /**
         * @brief Constructeur permettant de copier un objet Image pour créer le background.
         *
         * @param img L'image à copier
         * @param z Z-level. Valeur par défaut associée à -1.
         **/
        Background(const sf::Image& img, int z=-1) :VisibleObject(z), _vitesse(0), _side(center), _suppr_img(true)
        {
             _img =new sf::Image(img);
            _sprite.SetImage(*_img);
            _sprite_bis.SetImage(*_img);

            _position[0] = -(float) SCREEN_HEIGHT;
            _position[1] = 0.0f;
        }
        
        /**
         * @brief Destructeur effaçant l'image si elle a été allouée dans le constructeur.
         *
         **/
        virtual ~Background()
        {
            if (_suppr_img)
                delete _img;
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
        
        /**
         * @brief Change la couleur du fond.
         *
         * @param col La nouvelle couleur.
         * @return void
         **/
        void set_color(sf::Color col) { _sprite.SetColor(col); _sprite_bis.SetColor(col); }

    protected:
        int _vitesse; ///< Vitesse à laquelle le fond défile.
        sf::Sprite _sprite_bis; ///< Deuxième vue sur l'image.
        float _position[2]; ///< Tableau retenant la position des deux sprites.
        background_side _side; ///< Position du \a Background
        bool _suppr_img; ///< Booléen indiquant si il faut delete l'image lors de la destruction du Background
};

#endif /* REPEATINGOBJECT_HPP */ 
