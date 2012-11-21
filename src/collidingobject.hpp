#ifndef COLLIDINGOBJECT_HPP
#define COLLIDINGOBJECT_HPP

/**
 * @file collidingobject.hpp
 * @brief Gestion des collisions.
 */

#include "visibleobject.hpp"

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @brief Super-classe des objets pouvant réaliser des collisions.
 **/
class CollidingObject : public VisibleObject
{
    public:
        /**
         * @brief Constructeur par défaut.
         *
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 0.)
         **/
        CollidingObject(int z=0) : VisibleObject(z) { }
        /**
         * @brief Constructeur permettant de charger une image (devrait être utilisé).
         *
         * @param filename Chemin de l'image à charger.
         * @param z "Hauteur" de l'objet. (Valeur par défaut associée à 0.)
         **/
        CollidingObject(const std::string& filename, int z=0) : VisibleObject(filename, z) { }
        /**
         * @brief Destructeur (virtuel pour autoriser un héritage correct).
         **/
        virtual ~CollidingObject() {  }
        
        /**
         * @brief Récupère la "hitbox" d'un objet, en vue de tester les collisions.
         *
         * @return sf::FloatRect la "hitbox" de l'objet.
         **/
        virtual sf::FloatRect get_rect() const
        {
            sf::Vector2f size = _sprite.GetSize();
            sf::Vector2f pos = _sprite.GetPosition();
            return sf::FloatRect(pos.x, pos.y, pos.x + size.x, pos.y + size.y);
        }
        /**
         * @brief Vérifie si deux objets collisionnent.
         *
         * @param o L'autre objet.
         * @return bool
         **/
        bool collides_with(const CollidingObject& o) { return this->get_rect().Intersects(o.get_rect()); }
        /**
         * @brief Action à réaliser lors d'une collision.
         * 
         * Le comportement est à implémenter dans les sous-classes.
         *
         * @param o L'objet avec lequel il y a collision.
         * @return void
         **/
        virtual void* collision(CollidingObject * o) = 0;
        
        // Pour dessiner la hitbox, je le laisse là, ça peut aider pour le debug...
        //~ void draw(sf::RenderWindow& fen) const {
            //~ VisibleObject::draw(fen);
            //~ fen.Draw(sf::Shape::Rectangle(get_rect().Left, get_rect().Top, get_rect().Right, get_rect().Bottom, sf::Color::Yellow));
        //~ }
};

#endif /* COLLIDINGOBJECT_HPP */ 
