#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/**
 * @file constants.hpp
 * @brief Définition des constantes
 */

/// Titre du jeu, affiché dans l'écran d'introduction.
const char * const TITLE = "Super\nBank\nShooter";
/// Texte affiché lorsque le jeu est en pause. (centré très salement)
const wchar_t * const PAUSE_TEXT =
    L"                   -- Pause --\n"
    "Appuyez sur 'Entrée' pour reprendre";

/// Nombre maximum d'images par seconde (+1... ?). 0 pour désactiver la limite, 61 pour activer la VSYNC
const int FRAMERATE_LIMIT = 61;

const unsigned int SCREEN_WIDTH = 800; ///< Largeur de la fenêtre
const unsigned int SCREEN_HEIGHT = 600; ///< Hauteur de la fenêtre

const int INITIAL_SCORE = 100; ///< Score initial

const int PROPA_MAFIA = 40; ///< Probabilité d'apparition d'un ennemi du type \a Mafia
const int PROPA_CLIENT = 50; ///< probabilité d'apparition d'un ennemi du type \a Client
const float NEXT_ENEMY_TIME = 2.0f; ///< Durée entre deux apparitions d'ennemi
const float NUM_ENEMY_PER_LEVEL = 1; ///< Nombre d'ennemis par niveau

// Paramètres des objets (TODO: Ces constantes peuvent être une base, à modifier de manière aléatoire par exemple)
const float SHOT_DELAY = 1.0f; ///< Délai entre deux tirs du boss
const float SHOT_SPEED = 200.0f; ///< Vitesse des projectiles

const float BANKER_SPEED = 400.0f; ///< Vitesse de déplacement du banquier.
const float BANKER_SHOT_DELAY = SHOT_DELAY / 2.0f; ///< Durée entre deux tirs du banquier.
const float BANKER_SHOT_SPEED = SHOT_SPEED; ///< Vitesse des projectiles du banquier.
const int BANKER_LIFE = 20; ///< Vie du banquier.
const float BANKER_INVINCIBLE_DURATION = 1.0f; ///< Temps durant lequel le banquier est invincible après un coup.
const float BANKER_BLINK_PERIOD = 0.1f; ///< Période du clignotement du banquier après qu'il ait été touché.
const float BANKER_KNOCKBACK = 10.0f; ///< Recul lors d'un choc.

const int CASH = 5; ///< Montant de base laissé par les ennemis
const float BAG_TIME_TO_LIVE = 1.0f; ///< Temps avant que les sacs commencent à tomber.
const float BAG_SPEED = 50.0f; ///< Vitesse de chute des sacs d'argent.

const float ENEMY_SPEED = 200.0f; ///< Vitesse de base des ennemis.
const float THIEF_SPEED = 1*ENEMY_SPEED; ///< Vitesse des voleurs.
const float MAFIA_SPEED = ENEMY_SPEED / 10.0f; ///< Vitesse de la mafia.
const float MAFIA_SHOT_SPEED = 1.5f * SHOT_SPEED; ///< Vitesse de la mafia.
const float MAFIA_SHOT_DELAY = SHOT_DELAY / 1.2f; ///< Vitesse de la mafia.
const float CLIENT_SPEED = 1*ENEMY_SPEED; ///< Vitesse des clients en colère.
const float CLIENT_AMPLITUDE = ENEMY_SPEED; ///< Amplitude du mouvement sinusoidal des clients.
const int BOSS_LIFE = 1; ///< Point de vie du boss
const float BOSS_SPEED = 1.5 * ENEMY_SPEED; ///< Vitesse du boss
const float BOSS_INVINCIBLE_DURATION = 1.0f; ///< Temps durant lequel le banquier est invincible après un coup.
const float BOSS_BLINK_PERIOD = 0.1f; ///< Période du clignotement du banquier après qu'il ait été touché.
const float BOSS_KNOCKBACK = 0.0f; ///< Recul lors d'un choc.
const float BOSS_SHOT_SPEED = SHOT_SPEED; ///< Vitesse de la mafia.
const float BOSS_SHOT_DELAY = SHOT_DELAY; ///< Vitesse de la mafia.


#endif
