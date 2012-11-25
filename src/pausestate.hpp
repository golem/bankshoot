#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

/**
 * @file pausestate.hpp
 * @brief Gestion de l'écran de pause.
 */

#include "gamestate.hpp"
#include "background.hpp"
#include "textobject.hpp"


/**
 * @brief Écran de pause du jeu.
 **/
class PauseState : public GameState
{

    public:
        /**
         * @brief Constructeur.
         *
         **/
        PauseState(): _background(NULL), _info(NULL) { }
        
        /**
         * @brief Destructeur.
         *
         **/
        ~PauseState() { cleanup(); }
        
        virtual void draw(Engine* game) const;
        virtual void update(Engine* game);
        virtual void handle_events(Engine* game);
        virtual void cleanup();
        virtual void init();
        
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
        /**
         * @brief Texte clignotant indiquant qu'on est en pause.
         **/
        class PauseText : public TextObject
        {
            public:
                /**
                 * @brief Constructeur.
                 **/
                PauseText() : 
                        TextObject("media/Fontin-Regular.ttf", PAUSE_TEXT, true, true),
                        _alpha(255),
                        _transition_time(2.0f),
                        _elapsed_time(0.0f),
                        _alpha_croissant(false) { };
                
                /**
                 * @brief Met à jour l'objet.
                 *
                 * @param fen Utilise les attributs de l'objet pour le faire clignoter.
                 * @return void*
                 **/
                virtual void* update(const sf::RenderWindow& fen);
            private:
                unsigned char _alpha; ///< Transparence du texte.
                const float _transition_time; ///< Temps entre l'état transparent et l'état normal.
                float _elapsed_time; ///< Temps depuis la dernière frame capturée.
                bool _alpha_croissant; ///< Vrai si on passe de l'état transparent à l'état normal.
        };
        
        Background * _background; ///< Fond d'écran (idéalement une capture d'écran de l'état de jeu).
        PauseText * _info; ///< Texte indiquant qu'on est en pause.
};

#endif // PAUSESTATE_HPP
