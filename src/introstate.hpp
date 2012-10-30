#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include "gamestate.hpp"
#include "visibleobject.hpp"
#include "objectmanager.hpp"
//~ #include <SFML/Graphics.hpp>

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
