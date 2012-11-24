#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include "gamestate.hpp"
#include "background.hpp"


class PauseState : public GameState
{

    public:
        virtual void draw(Engine* game) const;
        virtual void update(Engine* game);
        virtual void handle_events(Engine* game);
        virtual void cleanup();
        virtual void init();
        PauseState(): _background(NULL) { }
        ~PauseState() { delete _background; }
        
        /**
         * @brief Fonction permettant de créer un fond pour l'état de pause.
         * 
         * Utile surtout en passant un screenshot en argument.
         *
         * @param img L'image à copier dans le fond d'écran.
         * @return void
         **/
        void set_background(const sf::Image& img) { _background = new Background(img); }
        
    private:
        Background * _background;
};

#endif // PAUSESTATE_HPP
