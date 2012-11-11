#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

/**
 * @file gamestate.hpp
 * @brief Gestion des "états" du jeu.
 * 
 * Un état peut être "pause", "introduction", "jeu"...
 */

#include "engine.hpp"

/**
 * @brief Classe représentant un état du jeu.
 **/
class GameState
{
    public:
        GameState() { }
        virtual ~GameState() { }
        
        /**
         * @brief Fonction permettant d'initialiser l'état.
         *
         * @return void
         **/
        virtual void init() = 0;
        /**
         * @brief Fonction permettant de nettoyer l'état.
         * 
         * On n'utilise pas le destructeur car une seule instance
         * de chaque état sera utilisée par le moteur.
         *
         * @return void
         **/
        virtual void cleanup() = 0;
        
        /**
         * @brief Gère les évènements (clavier et souris).
         *
         * @param game Le moteur de jeu.
         * @return void
         **/
        virtual void handle_events(Engine * game) = 0;
        /**
         * @brief Se met à jour.
         *
         * @param game Le moteur de jeu.
         * @return void
         **/
        virtual void update(Engine * game) = 0;
        /**
         * @brief Dessine l'état.
         *
         * @param game Le moteur de jeu.
         * @return void
         **/
        virtual void draw(Engine * game) const = 0;
        
        //~ virtual void pause() = 0;
        //~ virtual void resume() = 0;
};

#endif /* GAMESTATE_HPP */ 
