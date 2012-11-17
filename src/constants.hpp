#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/**
 * @file constants.hpp
 * @brief Définition des constantes
 */

const int FRAMERATE_LIMIT = 0; /**< Nombre maximum d'images par seconde (+1... ?). 0 pour désactiver la limite, 61 pour activer la VSYNC */

const int SCREEN_WIDTH = 800; /**< Largeur de la fenêtre */
const int SCREEN_HEIGHT = 600; /**< Hauteur de la fenêtre */

const int INITIAL_SCORE = 100;

const int PROPA_MAFIA = 40;
const int PROPA_CLIENT = 50;
const float NEXT_ENEMY_TIME = 2.0f;

// Paramètres des objets (TODO: Ces constantes peuvent être une base, à modifier de manière aléatoire par exemple)
const float BANKER_SPEED = 400.0f; ///< Vitesse de déplacement du banquier.
const float BANKER_SHOT_DELAY = 0.5f; ///< Durée entre deux tirs du banquier.
const float BANKER_SHOT_SPEED = 200.0f; ///< Vitesse des projectiles du banquier.

const float BAG_TIME_TO_LIVE = 1.0f; ///< Temps avant que les sacs commencent à tomber.
const float BAG_SPEED = 50.0f; ///< Vitesse de chute des sacs d'argent.

const float ENEMY_SPEED = 200.0f; ///< Vitesse de base des ennemis.
const float THIEF_SPEED = 1*ENEMY_SPEED; ///< Vitesse des voleurs.
const float MAFIA_SPEED = 1.2*ENEMY_SPEED; ///< Vitesse de la mafia.
const float CLIENT_SPEED = 1*ENEMY_SPEED; ///< Vitesse des clients en colère.
const float CLIENT_AMPLITUDE = ENEMY_SPEED; ///< Amplitude du mouvement sinusoidal des clients.

#endif
