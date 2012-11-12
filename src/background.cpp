#include "background.hpp"
#include <iostream>


void* Background::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    _position[0] += dt*_vitesse;
    _position[1] += dt*_vitesse;


    //~ if (_position[0] >= 0) _position[0] = - (float) _img->GetHeight();
    //~ if (_position[1] >= (int) _img->GetHeight()) _position[1] = 0.0f;
    //~ _sprite.SetPosition(0, _position[0]);
    //~ _sprite_bis.SetPosition(0, _position[1]);

    if (_position[0] >= 0) _position[0] = - (float) SCREEN_HEIGHT/2;
    if (_position[1] >= SCREEN_HEIGHT / 2) _position[1] = 0.0f;

    if (_side == center) {
        _sprite.SetPosition(0, _position[0]);
        _sprite_bis.SetPosition(0, _position[1]);
    }

    else if (_side == left) {
        _sprite.SetPosition(-_position[0]-2*SCREEN_WIDTH/3, 2*_position[0]);
        _sprite_bis.SetPosition(-_position[1]-2*SCREEN_WIDTH/3, 2*_position[1]);
    }

    else if (_side == right) {
        _sprite.SetPosition(_position[0]+2*SCREEN_WIDTH/3, 2*_position[0]);
        _sprite_bis.SetPosition(_position[1]+2*SCREEN_WIDTH/3, 2*_position[1]);        
    }
    
    return NULL;
}

void Background::draw(sf::RenderWindow& fen) const
{
    fen.Draw(_sprite);
    fen.Draw(_sprite_bis);
}



