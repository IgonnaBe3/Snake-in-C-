#ifndef SNAKE_BODY_H
#define SNAKE_BODY_H
#include <vector>
#include "Snake_Head.h"

class Snake_Body
{
    public:
        int num=3;
        std::vector<Snake_Head> Body;
        Snake_Body();
        void Assign_Position(sf::Vector2f position_);
        void Draw(sf::RenderWindow &window_);
};

#endif // SNAKE_BODY_H
