#ifndef VISIBLEOBJECT_HPP
#define VISIBLEOBJECT_HPP

/**
 * @file visibleobject.hpp
 * @brief Base pour tous les objets graphiques du jeu.
 */

#include "resourcemanager.hpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

/**
 * @brief Classe dont tous les objets graphiques héritent.
 **/
class VisibleObject
{
    public:
        /**
         * @brief Constructeur par défaut.
         *
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 0.)
         **/
        VisibleObject(int z=0) : _z(z), _dead(false), _visible(true) { std::cout << "Création d'un objet" << std::endl; }
        
        /**
         * @brief Constructeur permettant de charger une image (devrait être utilisé).
         *
         * @param filename Chemin de l'image à charger.
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 0.)
         **/
        VisibleObject(const std::string& filename, int z=0) : _img(ResourceManager::get_img(filename)),
                                                            _sprite(), _z(z), _dead(false), _visible(true)
        {
            std::cout << "Création d'un objet" << std::endl;
            _sprite.SetImage(*_img);
        }
        
        /**
         * @brief Destructeur (virtuel pour autoriser un héritage correct).
         *
         **/
        virtual ~VisibleObject() { std::cout << "Destruction d'un objet" << std::endl; }

        /**
         * @brief Met à jour l'objet.
         * 
         * Son implémentation dépend de la sous classe (par exemple un ennemi mettra
         * à jour sa position en fonction du temps écoulé depuis la dernière fois).
         *
         * @param fen Fenêtre de rendu à laquelle appartient l'objet.
         * @return void* : Pointeur vers un nouvel élément à éventuellement ajouter à la
         * liste des objets (comme un projectile...)
         **/
        virtual void * update(const sf::RenderWindow& fen) = 0;
        
        /**
         * @brief Dessine l'objet sur l'écran.
         *
         * @param fen La fenêtre de rendu sur laquelle dessiner l'objet.
         * @return void
         **/
        virtual void draw(sf::RenderWindow& fen) const
        {
            if (is_visible())
                fen.Draw(_sprite);
        }
        
        /**
         * @brief Compare deux objets en fonction de leur hauteur.
         *
         * @param that Objet à comparer
         * @return bool : true si this < that, false sinon.
         **/
        bool operator<(const VisibleObject& that) const
        {
            if (_z < that._z) return true;
            return false;
        }

        /**
         * @brief Détermine si l'objet doit être supprimé.
         *
         * @return bool
         **/
        inline bool is_dead() const { return _dead; }
        
        /**
         * @brief Fixer la position de l'objet au départ
         * @param x Coordonnée x
         * @param y Coordonnée y
         */
        void set_position(float x, float y) { _sprite.SetPosition(x, y); }
        
        /**
         * @brief Connaitre la position actuelle
         * @return Position actuelle
         */
        const sf::Vector2f& get_position() const { return _sprite.GetPosition(); }
        
        /**
         * @brief Connaitre la taille du sprite
         * @return Taille du sprite
         */
        sf::Vector2f get_size() const { return _sprite.GetSize(); }
        
        /**
         * @brief Détermine si l'objet doit être dessiné.
         *
         * @return bool
         **/
        bool is_visible() const { return _visible; }
        
        /**
         * @brief Règle la visibilité de l'objet.
         *
         * @param vis Vrai si l'objet doit être dessiné, faux sinon.
         * @return void
         **/
        void set_visible(bool vis) { _visible = vis; }
    
    protected:
        /**
         * @brief Image représentant l'objet.
         * 
         * C'est un pointeur vers un objet géré par le ResourceManager,
         * pour éviter de charger plusieurs fois la même image inutilement.
         **/
        sf::Image * _img;
        sf::Sprite _sprite; ///< "Vue" sur l'image, spécifique à chaque VisibleObject.
        
        /**
         * @brief Fonction pour signaler que l'objet doit être supprimé de la liste.
         * 
         * On fera sûrement autre chose si l'objet est tué par le joueur par exemple
         * (pour augmenter le score...)
         *
         * @return void
         **/
        void _die() { std::cout << "Argh!" << std::endl; _dead = true; }
        
    private:
        /**
         * @brief "Hauteur"/z-level de l'objet
         * 
         * N'a pas forcément de sens pour un objet non visible,
         * mais est quand même utilisé lors de l'insertion dans la liste des
         * objets
         **/
        int _z;
        bool _dead; ///< Variable déterminant si il faut supprimer l'objet.
        bool _visible; ///< Variable déterminant si il faut supprimer l'objet.
};

#endif /* VISIBLEOBJECT_HPP */ 
