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
        Client(const std::string& filename) : Enemy(filename)
        {
            _vx = CLIENT_AMPLITUDE;
            _vy = CLIENT_SPEED;
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
};

#endif // CLIENT_HPP
