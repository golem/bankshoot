#ifndef PAUSESTATE_HPP
#define PAUSESTATE_HPP

#include "gamestate.hpp"


class PauseState : public GameState
{

public:
    virtual void draw(Engine* game) const;
    virtual void update(Engine* game);
    virtual void handle_events(Engine* game);
    virtual void cleanup();
    virtual void init();
    PauseState();
};

#endif // PAUSESTATE_HPP
