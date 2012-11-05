#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <cassert>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

typedef std::map<std::string, sf::Image *> ImgMap;

class ResourceManager
{
    public:
        static sf::Image * get_img(const std::string& filename);
        static void cleanup();
        
    private:
        static ImgMap _imgs;
};

#endif /* RESOURCEMANAGER_HPP */ 
