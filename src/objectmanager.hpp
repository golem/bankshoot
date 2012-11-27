#ifndef OBJECTMANAGER_HPP
#define OBJECTMANAGER_HPP

/**
 * @file objectmanager.hpp
 * @brief Gestion des objets du jeu.
 */

#include <set>
#include <vector>
#include <SFML/Graphics.hpp>

#include "visibleobject.hpp"
#include "collidingobject.hpp"

/**
 * @struct ltObj
 * @brief Foncteur comparant deux objets.
 **/
struct ltObj
{
    /**
     * @brief Comparer la profondeur de deux \a VisibleObject
     */
    bool operator()(VisibleObject * a, VisibleObject * b) const
    {
        return *a < *b;
    }
};


/**
 * @brief Ensemble d'objets.
 * 
 * Vu que c'est un ensemble de pointeurs, il faut préciser, grâce à un
 * foncteur, qu'on l'ordonne en fonction des valeurs et non des adresses.
 * 
 * Ce set est là pour dessiner les objets en fonction de leur "profondeur".
 * 
 * C'est un multiset parce que plusieurs éléments avec la même profondeur
 * pourront exister (plusieurs ennemis par exemple).
 **/
typedef std::multiset<VisibleObject *, ltObj> ObjList;

/**
 * @brief Classe gérant un ensemble d'objets du jeu.
 **/
class ObjectManager
{
    public:

        /**
         * @brief Constructeur par défaut.
         **/
        ObjectManager() : _objects() { }

        /**
         * @brief Destructeur : détruit tous les objets gérés.
         **/
        ~ObjectManager()
        {
            delete_all();
        }
        
        /**
         * @brief Destruction de tous les objets gérés.
         *
         * @return void
         **/
        void delete_all();

        /**
         * @brief Dessine tous les objets gérés.
         *
         * @param fen La fenêtre de rendu sur laquelle dessiner.
         * @return void
         **/
        void draw_all(sf::RenderWindow& fen) const;

        /**
         * @brief Met à jour tous les objets gérés.
         *
         * @param fen La fenêtre de rendu ciblée par les objets.
         * @return void
         **/
        void update_all(const sf::RenderWindow& fen);
        
        /**
         * @brief Ajout d'un objet à la liste des objets gérés.
         *
         * @param obj L'objet à ajouter.
         * @return void
         **/
        void operator+=(VisibleObject * obj);
    
    private:
        ObjList _objects; ///< Liste des objets.
        std::vector<VisibleObject *> _added_objs; ///< Liste temporaire des objets à ajouter dans \a _objects
};

#endif /* OBJECTMANAGER_HPP */ 
