#include "background.hpp"

void* Background::update(const sf::RenderWindow& fen)
{
    float dt = fen.GetFrameTime();
    _position[0] += dt*_vitesse;
    _position[1] += dt*_vitesse;


    if (_position[0] >= 0) _position[0] = - (float) SCREEN_HEIGHT;
    if (_position[1] >= SCREEN_HEIGHT) _position[1] = 0.0f;

    if (_side == center) {
        _sprite.SetPosition(0, _position[0]);
        _sprite_bis.SetPosition(0, _position[1]);
    }

    else if (_side == left) {
        _sprite.SetPosition(-_position[0]-0.8f*SCREEN_WIDTH, 2*_position[0]);
        _sprite_bis.SetPosition(-_position[1]-0.8f*SCREEN_WIDTH, 2*_position[1]);
    }

    else if (_side == right) {
        _sprite.SetPosition(_position[0]+0.7f*SCREEN_WIDTH, 2*_position[0]);
        _sprite_bis.SetPosition(_position[1]+0.7f*SCREEN_WIDTH, 2*_position[1]);        
    }
    
    return NULL;
}

void Background::draw(sf::RenderWindow& fen) const
{
    if (is_visible()) {
        fen.Draw(_sprite);
        fen.Draw(_sprite_bis);
    }
}

void Background::rotation(float angle)
{
    _sprite.Rotate(angle);
    _sprite_bis.Rotate(angle);
}

void Background::set_center(float x, float y)
{
    _sprite.SetCenter(_img->GetWidth() / 2, _img->GetHeight() / 2);
    _sprite.SetPosition(x, y);
    _sprite_bis.SetCenter(_img->GetWidth() / 2, _img->GetHeight() / 2);
    _sprite_bis.SetPosition(x, y);
}
