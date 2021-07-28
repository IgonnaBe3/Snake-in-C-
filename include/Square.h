#ifndef SQUARE_H
#define SQUARE_H
#include "SFML/Graphics.hpp"

enum class e_type{empty,head,body,food};


class Square
{
    public:
    e_type content;
    sf::RectangleShape shape;
    Square(sf::Vector2u position,e_type content_=e_type::empty,int size=20);
};

#endif // SQUARE_H
