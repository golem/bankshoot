#ifndef CLIENT_HPP
#define CLIENT_HPP

/**
 * @file client.hpp
 * @brief Un autre type d'ennemi.
 */

#include "enemy.hpp"

/**
 * @brief Un client en colère.
 **/
class Client : public Enemy
{
    public:
        /**
         * @brief Constructeur.
         *
         * @param filename Le chemin de l'image à afficher.
         **/
        Client(const std::string& filename) : Enemy(filename),
                                              _masque_normal(0, 0, 31, 31),
                                              _masque_angry(32, 0, 81, 31),
                                              _elapsed_time(0.0f),
                                              _mood(false)
        {
            _vx = CLIENT_AMPLITUDE;
            _vy = CLIENT_SPEED;
           _sprite.SetSubRect(_masque_normal);
        }
        
        /**
        * @brief Met à jour la position du client en suivant une sinusoïde.
        * 
        * Le client est si énervé qu'il court partout.
        *
        * @param fen Fenêtre de rendu.
        * @return void*
        **/
        void * update(const sf::RenderWindow& fen);

    private:
        const sf::IntRect _masque_normal; ///< Masque pour extraire le bon sprite de la sprite sheet.
        const sf::IntRect _masque_angry; ///< Masque pour extraire le bon sprite de la sprite sheet.
        float _elapsed_time;
        bool _mood;
};

#endif // CLIENT_HPP
