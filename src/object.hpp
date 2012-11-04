#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Object
{
    public:
        Object(int z=0) : _z(z), _dead(false) {std::cout << "Création d'un objet" << std::endl; }
        virtual ~Object() { std::cout << "Destruction d'un objet" << std::endl; }
        
        virtual void update(const sf::RenderWindow& fen) = 0;
        
        // Le niveau z n'a pas forcément de sens pour un objet non visible,
        //mais est quand même utilisé lors de l'insertion dans la liste des
        //objets
        bool operator<(const Object& that) const
        {
            if (_z < that._z) return true;
            return false;
        }
        
        bool is_dead() const { return _dead; }
    
    protected:
        // Fonction pour signaler que l'objet doit être supprimé de la liste
        //on fera sûrement autre chose si l'objet est tué par le joueur par exemple
        //(pour augmenter le score...)
        void _die() { std::cout << "Argh!" << std::endl; _dead = true; }
    
    private:
        int _z;
        // Variable déterminant si il faut supprimer l'objet
        bool _dead;
};

#endif /* OBJECT_HPP */ 
