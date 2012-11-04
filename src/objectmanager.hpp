#ifndef OBJECTMANAGER_HPP
#define OBJECTMANAGER_HPP

#include <set>
#include <SFML/Graphics.hpp>

#include "visibleobject.hpp"

struct ltObj
{
    bool operator()(VisibleObject * a, VisibleObject * b) const
    {
        return *a < *b;
    }
};

// Vu que c'est un ensemble de pointeurs, il faut préciser, grâce à un
//foncteur, qu'on l'ordonne en fonction des valeurs et non des adresses.
//(ce set est là pour dessiner les objets en fonction de leur "profondeur")
//(c'est un multiset parce que plusieurs éléments avec la même profondeur
//pourront exister (plusieurs ennemis par exemple))
typedef std::multiset<VisibleObject *, ltObj> ObjList;

class ObjectManager
{
    public:
        ObjectManager() : _objects() { }
        ~ObjectManager()
        {
            delete_all();
        }
        
        void delete_all();
        void draw_all(sf::RenderWindow& fen) const;
        void update_all(const sf::RenderWindow& fen);
        
        void operator+=(VisibleObject * obj);
    
    private:
        ObjList _objects;
};

#endif /* OBJECTMANAGER_HPP */ 
