#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "engine.hpp"
// Forward declaration
//~ class Engine;

class GameState
{
    public:
        GameState() { }
        virtual ~GameState() { }
        
        virtual void init() = 0;
        virtual void cleanup() = 0;
        
        virtual void handle_events(Engine * game) = 0;
        virtual void update(Engine * game) = 0;
        virtual void draw(Engine * game) const = 0;
        
        //~ virtual void pause() = 0;
        //~ virtual void resume() = 0;
        
        void change_state(Engine * game, GameState * state) const
        {
            game->change_state(state);
        }
};

#endif /* GAMESTATE_HPP */ 
