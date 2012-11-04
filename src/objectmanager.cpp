#include "objectmanager.hpp"

void ObjectManager::operator+=(Object * obj)
{
    _objects.insert(obj);
}

void ObjectManager::draw_all(sf::RenderWindow& fen) const
{
    for (ObjList::const_iterator it = _objects.begin(); it != _objects.end(); ++it) {
        VisibleObject * obj = dynamic_cast<VisibleObject*>(*it);
        if (obj != NULL) obj->draw(fen);
        //~ (*it)->draw(fen);
    }
}

void ObjectManager::update_all(const sf::RenderWindow& fen)
{
    for (ObjList::iterator it = _objects.begin(); it != _objects.end(); ++it) {
        (*it)->update(fen);
    }
}

void ObjectManager::delete_all()
{
    for (ObjList::iterator it = _objects.begin(); it != _objects.end(); ++it) {
        delete (*it);
    }
    _objects.clear();
}
