#include "resourcemanager.hpp"

// Initialisation des attributs static
ImgMap ResourceManager::_imgs;

sf::Image * ResourceManager::get_img(const std::string& filename)
{
    ImgMap::iterator it = _imgs.find(filename);
    // Si l'image n'existe pas dans la map, on la charge et la renvoie
    if (it == _imgs.end()) {
        sf::Image * img = new sf::Image;
        assert(img->LoadFromFile(filename));
        img->SetSmooth(false); // Pour éviter le filtrage
        _imgs.insert(std::make_pair(filename, img));
        return img;
    }
    // Sinon on la renvoie tout simplement
    else
        return it->second;
}

void ResourceManager::cleanup()
{
    for (ImgMap::iterator it = _imgs.begin(); it != _imgs.end(); ++it) {
        delete it->second;
    }
}
