#include "engine.hpp"
#include "gamestate.hpp" // Pour éviter les problèmes de dépendances cycliques (forward declare dans le .hpp et include dans le .cpp)

Engine::~Engine()
{
    for (std::map<std::string, GameState *>::iterator it = _map_states.begin(); it != _map_states.end(); ++it) {
        it->second->cleanup();
        delete it->second;
    }
}

void Engine::change_state(const std::string& name)
{
    // Quitte l'état en cours
    if (!_states.empty()) {
        _states.back()->cleanup();
        _states.pop_back();
    }
    
    // Stocke et initialise le nouvel état
    _states.push_back(get_state(name));
    _states.back()->init();
}

void Engine::add_state(const std::string& name, GameState * state)
{
    _map_states[name] = state;
    //~ _map_states.insert(std::make_pair(name, state));
}

GameState* Engine::get_state(const std::string& name) const
{
    return _map_states.find(name)->second;
}

void Engine::handle_events()
{
    // On laisse l'état gérer les évènements
    if (!_states.empty())
        _states.back()->handle_events(this);
}

void Engine::update()
{
    if (_running) {
        // On laisse l'état mettre à jour le jeu
        if (!_states.empty())
            _states.back()->update(this);
    }
}

void Engine::draw()
{
    if (_running) {
        _fenetre.Clear();
        // On laisse l'état dessiner l'écran
        if (!_states.empty())
            _states.back()->draw(this);
        _fenetre.Display();
    }
}

void Engine::push_state(const std::string& name)
{
    // Met en pause l'état actuel
    if (!_states.empty())
        _states.back()->pause();
    
    // Initialise le nouvel état
    _states.push_back(get_state(name));
    _states.back()->init();
}

void Engine::pop_state()
{
    // Nettoie l'état courant
    if (!_states.empty()) {
        _states.back()->cleanup();
        _states.pop_back();
    }
    
    // Reprend l'état précédent
    if (!_states.empty()) 
        _states.back()->resume();
}
