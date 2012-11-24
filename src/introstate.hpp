#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

/**
* @file introstate.hpp
* @brief Introduction du jeu.
*/

#include "gamestate.hpp"
#include "background.hpp"
#include "objectmanager.hpp"
#include "constants.hpp"

/**
* @class IntroState
* @brief Gestion de l'introduction du jeu
*/
class IntroState: public GameState
{
    public:
    
        /**
* @brief Constructeur
*
* Initialise la vitesse de rotation
*/
        IntroState(): _background(NULL), _background_bis(NULL), _vr(10.f) { }

        /**
* @brief Destructeur
*/
        ~IntroState() { }
        
        void init();
        void cleanup();
        
        void handle_events(Engine * game);
        void update(Engine * game);
        void draw(Engine * game) const;
    
    private:
        //~ sf::Image _bg;
        //~ sf::Sprite _bg_sprite;
        //~ ObjectManager _objects;

/* On n'a pas forcement besoin de ObjectManager, puisqu'il n'y a qu'une image */
        Background *_background; ///< Arrier plan
        Background *_background_bis; ///< Arrier plan
        float _vr; ///< Vitesse angulaire
};

#endif /* INTROSTATE_HPP */ 
