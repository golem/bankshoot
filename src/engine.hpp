#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

//~ #include "gamestate.hpp"
// Forward declaration
class GameState;

class Engine
{
    public:
        Engine(const std::string& titre, int largeur=800, int hauteur=600) :
                     _running(true),
                     _fenetre(sf::VideoMode(largeur, hauteur, 32), titre,
                              sf::Style::Close, sf::WindowSettings()),
                     _states(0), _map_states() { _fenetre.UseVerticalSync(false); }
        ~Engine();
        
        void change_state(GameState * state);
        
        void handle_events();
        void update();
        void draw();
        
        sf::RenderWindow& get_screen() { return _fenetre; }
        
        bool is_running() const { return _running; }
        void quit()
        {
            _running = false;
            _fenetre.Close();
        }
        
        void add_state(const std::string& name, GameState * state);
        GameState* get_state(const std::string& name) const;
        
    private:
        bool _running;
        // La fenêtre de rendu
        sf::RenderWindow _fenetre;
        // La pile des états actuellements utilisés
        std::vector<GameState *> _states;
        // Une map de tous les états possibles
        std::map<std::string, GameState *> _map_states;
};

#endif /* ENGINE_HPP */ 
