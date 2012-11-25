#ifndef ENDINGSTATE_HPP
#define ENDINGSTATE_HPP

/**
 * @file endingstate.hpp
 * @brief Ecran pour afficher les résultats
 */

#include "gamestate.hpp"
#include "background.hpp"
#include "textobject.hpp"

/**
 * @class EndingState
 * @brief Gestion de fin de la partie
 */
class EndingState: public GameState
{
    public:
    
        EndingState() : _background(NULL), _score(NULL) {}
        
        ~EndingState() { cleanup(); }
        
        void init();
        void cleanup();
        
        void handle_events(Engine * game);
        void update(Engine * game);
        void draw(Engine * game) const;
        
        /**
         * @brief Crée le texte représentant le score.
         *
         * @param capital Le capital du banquier.
         * @param niveau Le niveau atteint par le banquier.
         * @param temps Le temps total de jeu.
         * @return void
         **/
        void set_score(int capital, int niveau, float temps);
    
    private:
        Background *_background; ///< Fond d'écran.
        TextObject * _score; ///< Texte affichant le score.
};

#endif
