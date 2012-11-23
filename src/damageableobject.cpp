#include "damageableobject.hpp"

void DamageableObject::_get_hit(sf::Sprite& sprite)
{
    // Lorsqu'on se fait toucher, on perd de la vie, on devient momentanément
    // invincible, et on recule un peu.
    --_life;
    _invincible = true;
    sprite.Move(0.0f, _knockback);
    _toggle_color(sprite);
}

void DamageableObject::_toggle_color(sf::Sprite& sprite)
{
    if (sprite.GetColor() == _couleur_normale)
        sprite.SetColor(_transparent);
    else
        sprite.SetColor(_couleur_normale);
}

void DamageableObject::_handle_invincible(sf::Sprite& sprite, float dt)
{
    if (_invincible) {
        _last_hit += dt;
        _last_blink += dt;
        if (_last_blink > _blink_period) {
            _toggle_color(sprite);
            _last_blink = 0.0f;
        }
        if (_last_hit > _invincible_duration) {
            _invincible = false;
            _last_hit = 0.0f;
            sprite.SetColor(_couleur_normale);
        }
    }
}
