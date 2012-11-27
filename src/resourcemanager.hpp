#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

/**
 * @file resourcemanager.hpp
 * @brief Gestion des ressources.
 */ 

#include <cassert>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

typedef std::map<std::string, sf::Image *> ImgMap; ///< Liste de pointeurs sur sf::Image, indexés par leur chemin.
typedef std::map<std::string, sf::Font *> FontMap; ///< Liste de pointeurs sur sf::Font, indexés par leur chemin.

/**
 * @brief Classe permettant de gérer les ressources du jeu.
 * 
 * Elle contient uniquement des méthodes et attributs statiques. C'est
 * donc une sorte de Singleton. On pourrait passer une référence vers 
 * cette classe à tous les objets qui en ont besoin, mais bon...
 **/
class ResourceManager
{
    public:

        /**
         * @brief Récupère une image grâce à son nom.
         * 
         * La première fois que cette méthode est appelée avec un certain chemin,
         * elle charge effectivement cette image en mémoire, mais les fois d'après,
         * elle retourne un pointeur vers cette même image.
         *
         * @param filename Le chemin de l'image à charger.
         * @return sf::Image*
         **/
        static sf::Image * get_img(const std::string& filename);

        /**
         * @brief Récupère une police grâce à son nom.
         * 
         * @see get_img
         *
         * @param filename Le chemin de la police à charger.
         * @return sf::Font*
         **/
        static sf::Font * get_font(const std::string& filename);

        /**
         * @brief Delete toutes les ressources gérées par la classe.
         * 
         * Doit être appelée manuellement, car la classe étant static,
         * il n'y a pas de destructeur.
         *
         * @return void
         **/
        static void cleanup();
        
    private:
        static ImgMap _imgs;    ///< Liste des images.
        static FontMap _fonts;  ///< Liste des polices.
};

#endif /* RESOURCEMANAGER_HPP */ 
