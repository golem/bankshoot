#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

/**
 * @file playstate.hpp
 * @brief État principal du jeu.
 */

#include "gamestate.hpp"
#include "background.hpp"
#include "objectmanager.hpp"
#include "banquier.hpp"
#include "voleur.hpp"
#include "boss.hpp"
#include "dropobject.hpp"
#include "fpscounter.hpp"
#include "scoredisplay.hpp"
#include "enemyfactory.hpp"
#include <SFML/Graphics.hpp>

/**
 * @class PlayState
 * @brief Phase Gameplay du jeu
 */
class PlayState: public GameState
{
    public:

        /**
         * @brief Constructeur par défaut
         */
        PlayState() { }
        
        /**
         * @brief Destructeur
         */
        ~PlayState() { }
        
        void init();
        void cleanup();
        
        void handle_events(Engine * game);
        void update(Engine * game);
        void draw(Engine * game) const;
    
    private:
        ObjectManager _objects; ///< Gestion des objets du jeu
        EnemyFactory _factory;  ///< Gestion des ennemis à apparaître
        Banquier *_banquier;    ///< Pointeur sur le banquier
};

#endif /* INTROSTATE_HPP */ 
