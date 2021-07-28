#ifndef SNAKE_HEAD_H
#define SNAKE_HEAD_H
#include "SFML/Graphics.hpp"

class Snake_Head
{
    public:
        int x=0,y=20;
        sf::RectangleShape snake;
        Snake_Head();
        void Move();
};
#endif // SNAKE_HEAD_H
