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
    // Une autre boucle pour gérer les collisions
    // Pourrait peut-être être amélioré
    for (ObjList::iterator it = _objects.begin(); it != _objects.end(); ++it) {
        CollidingObject * obj = dynamic_cast<CollidingObject*>(*it);
        if (obj != NULL) {
            for (ObjList::iterator it2 = _objects.begin(); it2 != _objects.end(); ++it2) {
                CollidingObject * autre = dynamic_cast<CollidingObject*>(*it2);
                if ((autre != NULL) && (obj != autre) && (obj->collides_with(*autre))) obj->collision(autre);
            }
        }
    }
    // Deuxième boucle pour supprimer les objets qui ont été détruits.
    // Je pense que c'est plus sûr, mais je me trompe peut être
    for (ObjList::iterator it = _objects.begin(); it != _objects.end(); ) {
        if ((*it)->is_dead()) {
            delete (*it);
            _objects.erase(it++); // cf. http://stackoverflow.com/a/263958
        }
        else ++it;
    }
}

void ObjectManager::delete_all()
{
    for (ObjList::iterator it = _objects.begin(); it != _objects.end(); ++it) {
        delete (*it);
    }
    _objects.clear();
}
