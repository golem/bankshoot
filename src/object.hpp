#ifndef OBJECT_HPP
#define OBJECT_HPP

/**
 * @file object.hpp
 * @brief Base pour tous les objets du jeu.
 */

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief Classe dont tous les objets du jeu héritent.
 **/
class Object
{
    public:
        /**
         * @brief Constructeur par défaut.
         *
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 0)
         **/
        Object(int z=0) : _z(z), _dead(false) {std::cout << "Création d'un objet" << std::endl; }
        /**
         * @brief Destructeur (virtuel pour autoriser un héritage correct).
         *
         **/
        virtual ~Object() { std::cout << "Destruction d'un objet" << std::endl; }

        /**
         * @brief Met à jour l'objet.
         * 
         * Son implémentation dépend de la sous classe (par exemple un ennemi mettra
         * à jour sa position en fonction du temps écoulé depuis la dernière fois).
         *
         * @param fen Fenêtre de rendu à laquelle appartient l'objet.
         * @return void
         **/
        virtual void update(const sf::RenderWindow& fen) = 0;

        /**
         * @brief Compare deux objets en fonction de leur hauteur.
         *
         * @param that Objet à comparer
         * @return bool : true si this < that, false sinon.
         **/
        bool operator<(const Object& that) const
        {
            if (_z < that._z) return true;
            return false;
        }

        /**
         * @brief Détermine si l'objet doit être supprimé.
         *
         * @return bool
         **/
        bool is_dead() const { return _dead; }

    protected:
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
         * @brief "Hauteur" de l'objet
         * 
         * N'a pas forcément de sens pour un objet non visible,
         * mais est quand même utilisé lors de l'insertion dans la liste des
         * objets
         **/
        int _z;
        bool _dead; ///< Variable déterminant si il faut supprimer l'objet.
};

#endif /* OBJECT_HPP */ 
