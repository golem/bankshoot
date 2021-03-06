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
    
    // Gestion de l'invincibilité
    _handle_invincible(_sprite, dt);
    
    // Création éventuelle d'un projectile
    if ((_last_shot > _shot_delay) && (input.IsKeyDown(sf::Key::Space))) {
        --_score; // Baisser le score
        _last_shot = 0.0f;
        // Les projectiles allant vers le "bas" sont deux fois plus rapides, pour 
        // compenser la vitesse des ennemis.
        if (_facing_up)
            return new Projectile("media/gold.png", pos.x + size.x / 2, pos.y, Projectile::banker);
        else
            return new Projectile("media/gold.png", pos.x + size.x / 2, pos.y, Projectile::banker, 2*BANKER_SHOT_SPEED);
    }
    
    return NULL;
}

void* Banquier::collision(CollidingObject * o)
{
    if (is_invincible()) return NULL;
    
    Enemy * autre = dynamic_cast<Enemy*>(o);
    if (autre != NULL) {
        _get_hit(_sprite);
    }
    Projectile* p = dynamic_cast<Projectile*>(o);
    if ((p != NULL) && (p->get_shot_id() == Projectile::enemy)){
        _get_hit(_sprite);
    }

    return NULL;
}
