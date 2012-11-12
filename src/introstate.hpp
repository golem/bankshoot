#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

/**
 * @file introstate.hpp
 * @brief Introduction du jeu.
 */

#include "gamestate.hpp"
#include "background.hpp"
#include "objectmanager.hpp"

class IntroState: public GameState
{
    public:
        IntroState() { }
        ~IntroState() { }
        
        void init();
        void cleanup();
        
        void handle_events(Engine * game);
        void update(Engine * game);
        void draw(Engine * game) const;
    
    private:
        //~ sf::Image _bg;
        //~ sf::Sprite _bg_sprite;
        ObjectManager _objects;
};

#endif /* INTROSTATE_HPP */ 
