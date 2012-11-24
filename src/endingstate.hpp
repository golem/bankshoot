#ifndef ENDINGSTATE_HPP
#define ENDINGSTATE_HPP

/**
 * @file endingstate.hpp
 * @brief Ecran pour afficher les résultats
 */

#include "gamestate.hpp"
#include "background.hpp"

/**
 * @class EndingState
 * @brief Gestion de fin de la partie
 */
class EndingState: public GameState
{
    public:
    
        EndingState() {}
        
        ~EndingState()
        {
            delete _background;
        }
        
        void init();
        void cleanup();
        
        void handle_events(Engine * game);
        void update(Engine * game);
        void draw(Engine * game) const;
    
    private:
        Background *_background;
};

#endif
