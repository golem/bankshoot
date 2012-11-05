#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include "gamestate.hpp"
#include "background.hpp"
#include "objectmanager.hpp"
#include "banquier.hpp"
#include "voleur.hpp"
#include "enemyfactory.hpp"
#include <SFML/Graphics.hpp>

class PlayState: public GameState
{
    public:
        PlayState() { }
        ~PlayState() { }
        
        void init();
        void cleanup();
        
        void handle_events(Engine * game);
        void update(Engine * game);
        void draw(Engine * game) const;
    
    private:
        //~ sf::Image _bg;
        //~ sf::Sprite _bg_sprite;
        ObjectManager _objects;
        EnemyFactory _factory;
};

#endif /* INTROSTATE_HPP */ 
