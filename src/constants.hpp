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
const float NEXT_ENEMY_TIME = 2.0f;

const float TIME_TO_LIVE = 1.0f;

#endif
