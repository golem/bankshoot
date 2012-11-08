#ifndef ENGINE_HPP
#define ENGINE_HPP

/**
 * @file engine.hpp
 * @brief Moteur du jeu.
 */

#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "constants.hpp"

// Forward declaration
class GameState;

/**
 * @brief Moteur du jeu.
 **/
class Engine
{
    public:
        /**
         * @brief Constructeur.
         *
         * @param titre Titre de la fenêtre.
         * @param largeur Largeur de la fenêtre. (Valeur par défaut associée à SCREEN_WIDTH.)
         * @param hauteur Hauteur de la fenêtre. (Valeur par défaut associée à SCREEN_HEIGHT.)
         **/
        Engine(const std::string& titre, int largeur=SCREEN_WIDTH, int hauteur=SCREEN_HEIGHT) :
                     _running(true),
                     _fenetre(sf::VideoMode(largeur, hauteur, 32), titre,
                              sf::Style::Close, sf::WindowSettings()),
                     _states(0), _map_states() { _fenetre.UseVerticalSync(false); }
        
        /**
         * @brief Destructeur.
         *
         **/
        ~Engine();
        
        /**
         * @brief Change l'état du jeu.
         *
         * @param name Le nom de l'état (doit exister dans la map des états).
         * @return void
         **/
        void change_state(const std::string& name);
        
        /**
         * @brief Laisse l'état courant gérer les évènements.
         *
         * @return void
         **/
        void handle_events();
        /**
         * @brief Laisse l'état courant se mettre à jour.
         *
         * @return void
         **/
        void update();
        /**
         * @brief Laisse l'état courant dessiner.
         *
         * @return void
         **/
        void draw();
        
        /**
         * @brief Récupère une référence vers la fenêtre de rendu.
         *
         * @return sf::RenderWindow&
         **/
        sf::RenderWindow& get_screen() { return _fenetre; }
        
        /**
         * @brief Détermine si le jeu tourne.
         *
         * @return bool
         **/
        bool is_running() const { return _running; }
        /**
         * @brief Quitte le jeu.
         *
         * @return void
         **/
        void quit()
        {
            _running = false;
            _fenetre.Close();
        }
        
        /**
         * @brief Ajoute un nouvel état, indexé par son nom.
         *
         * @param name Le nom de l'état.
         * @param state Un pointeur vers l'état à ajouter.
         * @return void
         **/
        void add_state(const std::string& name, GameState * state);
        
    private:
        bool _running; ///< Détermine si le jeu tourne.
        sf::RenderWindow _fenetre; ///< La fenêtre de rendu.
        std::vector<GameState *> _states; ///< La pile des états actuellements utilisés.
        std::map<std::string, GameState *> _map_states; ///< Une map de tous les états possibles.
        
        /**
         * @brief Récupère un état en utilisant son nom.
         *
         * @param name Le nom de l'état à récupérer.
         * @return GameState*
         **/
        GameState* _get_state(const std::string& name) const;
};

#endif /* ENGINE_HPP */ 

