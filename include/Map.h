#ifndef MAP_H
#define MAP_H
#include <vector>
#include "Square.h"
class Map
{
    public:
        std::vector <std::vector<Square>> playfield;
        Map(int x,int y);
        void Draw(sf::RenderWindow &window_);
};

#endif // MAP_H
