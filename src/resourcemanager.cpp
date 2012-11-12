#include "resourcemanager.hpp"

// Initialisation des attributs static
ImgMap ResourceManager::_imgs;
FontMap ResourceManager::_fonts;

// ... Je verrais bien des templates par ici... (ou pas)

sf::Image * ResourceManager::get_img(const std::string& filename)
{
    ImgMap::iterator it = _imgs.find(filename);
    // Si l'image n'existe pas dans la map, on la charge et la renvoie
    if (it == _imgs.end()) {
        sf::Image * img = new sf::Image;
        assert(img->LoadFromFile(filename));
        img->CreateMaskFromColor(sf::Color(0x00, 0xff, 0x00), 0); // Placer un masque de couleur, fond verts
        img->SetSmooth(false); // Pour éviter le filtrage
        _imgs.insert(std::make_pair(filename, img));
        return img;
    }
    // Sinon on la renvoie tout simplement
    else
        return it->second;
}

sf::Font * ResourceManager::get_font(const std::string& filename)
{
    FontMap::iterator it = _fonts.find(filename);
    // Si la fonte n'existe pas dans la map, on la charge et la renvoie
    if (it == _fonts.end()) {
        sf::Font * font = new sf::Font;
        assert(font->LoadFromFile(filename));
        _fonts.insert(std::make_pair(filename, font));
        return font;
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
    for (FontMap::iterator it = _fonts.begin(); it != _fonts.end(); ++it) {
        delete it->second;
    }
}
