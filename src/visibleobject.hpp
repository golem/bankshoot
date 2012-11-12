#ifndef VISIBLEOBJECT_HPP
#define VISIBLEOBJECT_HPP

/**
 * @file visibleobject.hpp
 * @brief Base pour tous les objets graphiques du jeu.
 */

#include "object.hpp"
#include "resourcemanager.hpp"

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @brief Classe dont tous les objets graphiques héritent.
 **/
class VisibleObject : public Object
{
    public:
        /**
         * @brief Constructeur par défaut.
         *
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 0.)
         **/
        VisibleObject(int z=0) : Object(z) { }
        /**
         * @brief Constructeur permettant de charger une image (devrait être utilisé).
         *
         * @param filename Chemin de l'image à charger.
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 0.)
         **/
        VisibleObject(const std::string& filename, int z=0) : Object(z),
            _img(ResourceManager::get_img(filename)), _sprite()
        {
            _sprite.SetImage(*_img);
        }
        /**
         * @brief Destructeur (virtuel pour autoriser un héritage correct).
         *
         **/
        virtual ~VisibleObject() {  }
        
        /**
         * @brief Dessine l'objet sur l'écran.
         *
         * @param fen La fenêtre de rendu sur laquelle dessiner l'objet.
         * @return void
         **/
        virtual void draw(sf::RenderWindow& fen) const;
    
    protected:
        /**
         * @brief Image représentant l'objet.
         * 
         * C'est un pointeur vers un objet géré par le ResourceManager,
         * pour éviter de charger plusieurs fois la même image inutilement.
         **/
        sf::Image * _img;
        sf::Sprite _sprite; ///< "Vue" sur l'image, spécifique à chaque VisibleObject.
};

#endif /* VISIBLEOBJECT_HPP */ 
