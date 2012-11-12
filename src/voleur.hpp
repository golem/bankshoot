#ifndef VOLEUR_HPP
#define VOLEUR_HPP

/**
 * @file voleur.hpp
 * @brief Ennemi basique.
 */

#include "enemy.hpp"

/**
 * @brief Classe représentant un ennemi basique.
 **/
class Voleur: public Enemy
{
    public:
        /**
         * @brief Constructeur.
         *
         * @param filename Chemin de l'image à utiliser.
         **/
        Voleur(const std::string& filename) : Enemy(filename)
        {
            // TODO : mieux gérer ces paramètres, peut être que ça devrait pas être
            //défini dans la superclasse, ou alors fournir un constructeur correct
            _vx = 0.0f;
            _vy = 200.0f;
        }
        
        /**
         * @brief Met à jour la position de l'ennemi suivant un mouvement linéaire uniforme. Très simple.
         *
         * @param fen Fenêtre de rendu.
         * @return void
         **/
        void * update(const sf::RenderWindow& fen);
};

#endif /* VOLEUR_HPP */ 
