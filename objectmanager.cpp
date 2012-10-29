#include "objectmanager.hpp"

void ObjectManager::operator+=(VisibleObject * obj)
{
    _objects.push_back(obj);
}

void ObjectManager::draw_all(sf::RenderWindow& fen) const
{
    for (size_t i = 0; i < _objects.size(); ++i) {
        _objects[i]->draw(fen);
    }
}
#include <iostream>
void ObjectManager::delete_all()
{
    for (size_t i = 0; i < _objects.size(); ++i) {
        std::cout << "delete" << std::endl;
        delete _objects[i];
        //~ std::cout << "pop" << _objects.size() << std::endl;
        //~ _objects.pop_back();
    }
    _objects.clear();
    //~ for (std::vector<VisibleObject *>::iterator it = _objects.begin(); it != _objects.end(); ++it) {
        //~ if (_objects.size() != 0) {
            //~ std::cout << "delete" << std::endl;
            //~ delete *it;
            //~ std::cout << "pop" << _objects.size() << std::endl;
            //~ _objects.erase(it);
            //~ std::cout << "popé" << _objects.size() << std::endl;
        //~ }
    //~ }
}
