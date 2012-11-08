#include "banquier.hpp"

void Banquier::update(const sf::RenderWindow& fen)
{
    const sf::Input& input = fen.GetInput();
    float dt = fen.GetFrameTime();
    sf::Vector2f size = _sprite.GetSize();
    sf::Vector2f pos;
    
    // Mise à jour des coordonnées du joueur, en fonction des touches enfoncées
    if (input.IsKeyDown(sf::Key::Left)) _sprite.Move(-dt*_vx, 0);
    if (input.IsKeyDown(sf::Key::Right)) _sprite.Move(dt*_vx, 0);
    if (input.IsKeyDown(sf::Key::Up)) {
        _sprite.Move(0, -dt*_vy);
        _sprite.SetSubRect(sf::IntRect(32, 43, 63, 0));
    }
    if (input.IsKeyDown(sf::Key::Down)) {
        _sprite.Move(0, dt*_vy);
        _sprite.SetSubRect(sf::IntRect(0, 43, 31, 0));
    }
    
    // Gestion des bords
    pos = _sprite.GetPosition();
    if (pos.x <= 0.0f) pos.x = 0.0f;
    //~ if (pos.y <= 0.0f) pos.y = 0.0f;
    if (pos.y <= -size.y) pos.y = -size.y; // size.y est négatif !??
    if (pos.x >= fen.GetWidth() - size.x) pos.x = fen.GetWidth() - size.x;
    //~ if (pos.y >= fen.GetHeight() - size.y) pos.y = fen.GetHeight() - size.y;
    if (pos.y >= fen.GetHeight()) pos.y = fen.GetHeight();
    _sprite.SetPosition(pos);
}
