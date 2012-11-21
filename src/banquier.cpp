#include "banquier.hpp"

void* Banquier::update(const sf::RenderWindow& fen)
{
    const sf::Input& input = fen.GetInput();
    float dt = fen.GetFrameTime();
    _last_shot += dt;
    sf::Vector2f size = _sprite.GetSize();
    sf::Vector2f pos;
    
    // Mise à jour des coordonnées du joueur, en fonction des touches enfoncées
    if (input.IsKeyDown(sf::Key::Left)) _sprite.Move(-dt*_vx, 0);
    if (input.IsKeyDown(sf::Key::Right)) _sprite.Move(dt*_vx, 0);
    if (input.IsKeyDown(sf::Key::Up)) {
        _sprite.Move(0, -dt*_vy);
        _sprite.SetSubRect(_masque_dos);
        _facing_up = true;
    }
    if (input.IsKeyDown(sf::Key::Down)) {
        _sprite.Move(0, dt*_vy);
        _sprite.SetSubRect(_masque_face);
        _facing_up = false;
    }
    
    // Gestion des bords
    pos = _sprite.GetPosition();
    if (pos.x <= 0.0f) pos.x = 0.0f;
    if (pos.y <= 0.0f) pos.y = 0.0f;
    if (pos.x >= fen.GetWidth() - size.x) pos.x = fen.GetWidth() - size.x;
    if (pos.y >= fen.GetHeight() - size.y) pos.y = fen.GetHeight() - size.y;
    _sprite.SetPosition(pos);
    
    // Création éventuelle d'un projectile
    if ((_last_shot > _shot_delay) && (input.IsKeyDown(sf::Key::Space))) {
        --_score; // Baisser le score
        _last_shot = 0.0f;
        if (_facing_up)
            return new Projectile("media/gold.png", pos.x, pos.y, Projectile::banker);
        else
            return new Projectile("media/gold.png", pos.x, pos.y, Projectile::banker, BANKER_SHOT_SPEED);
    }
    
    // Gestion de l'invincibilité
    if (_invincible) {
        _last_hit += dt;
        _last_blink += dt;
        if (_last_blink > _blink_period) {
            _toggle_color();
            _last_blink = 0.0f;
        }
        if (_last_hit > _invincible_duration) {
            _invincible = false;
            _last_hit = 0.0f;
            _sprite.SetColor(_couleur_normale);
        }
    }
    
    return NULL;
}

void* Banquier::collision(CollidingObject * o)
{
    Enemy * autre = dynamic_cast<Enemy*>(o);
    if (autre != NULL) {
        _get_hit();
        std::cout << "Meurs !" << std::endl;
    }
    Projectile* p = dynamic_cast<Projectile*>(o);
    if ((p != NULL) && (p->get_shot_id() == Projectile::enemy)){
        _get_hit();
    }

    return NULL;
}

sf::FloatRect Banquier::get_rect() const
{
    if (_invincible)
        return sf::FloatRect(0, 0, 0, 0);
    else
        return CollidingObject::get_rect();
}

void Banquier::_get_hit()
{
    // Lorsqu'on se fait toucher, on perd de la vie, on devient momentanément
    // invincible, et on recule un peu.
    --_life;
    _invincible = true;
    _sprite.Move(0.0f, _knockback);
    _toggle_color();
}

void Banquier::_toggle_color()
{
    if (_sprite.GetColor() == _couleur_normale)
        _sprite.SetColor(_transparent);
    else
        _sprite.SetColor(_couleur_normale);
}
