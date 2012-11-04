#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Object
{
    public:
        Object(int z=0) : _z(z) {std::cout << "Création d'un objet" << std::endl; }
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
    
    private:
        int _z;
};

#endif /* OBJECT_HPP */ 
