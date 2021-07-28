#pragma once
#include "Food.h"
#include "Snake.h"
#include "SFML/Graphics.hpp"
#include <math.h>
enum class eShape
{
	square,
	circle,
	triangle,
};

class Playfield
{
	Snake snake;
	Food food;


	int size = 50;
	short delay = 0;
	short maxDelay = 10;

	eShape shape;// = eShape::square;
	std::vector<std::vector<bool>> activeTiles;
	sf::RectangleShape drawBuffer;
public:
	Playfield(eShape shape_, int size_)
		:snake({ 10, 10 }),
		food({ size_/2,size_/2  })
	{
		size = size_;
		shape = shape_;

		switch (shape_)
		{
		case eShape::square:
		{
			for (int x = 0; x < size; x++)
			{
				activeTiles.push_back(std::vector<bool>());
				for (int y = 0; y < size; y++)
				{
					activeTiles[x].push_back(true);
				}
			}
		}
		break;
		case eShape::circle:
		{

			sf::CircleShape default_circle;
			default_circle.setRadius(size);
			default_circle.setOrigin(10, 10);
			default_circle.setPosition(size * 20 / 2, size * 20 / 2);
			for (int x = 0; x < size; x++)
			{
				activeTiles.push_back(std::vector<bool>());
				for (int y = 0; y < size; y++)
				{

					float dist;
					dist = sqrt(pow((size  / 2) - x , 2) + pow((size  / 2) - y, 2));

					if (dist<size/2)
					{
						activeTiles[x].push_back(true);

					}
					else
					{
						activeTiles[x].push_back(false);
					}
				}
			}
		}
		break;
		case eShape::triangle:
		{
			for (int x = 0; x < size; x++)
			{
				activeTiles.push_back(std::vector<bool>());
				for (int y = 0; y < size; y++)
				{
					if (x <= size / 2 && y <= 2 * x + 1)
					{
						activeTiles[x].push_back(true);
					}
					else if (x > size / 2 && y <= 2 * (size - x) + 1)
					{
						activeTiles[x].push_back(true);
					}
					else
					{
						activeTiles[x].push_back(false);
					}

				}
			}
		}
		break;
		default:
			break;
		}


			drawBuffer.setSize({ 20, 20 });
			drawBuffer.setOutlineThickness(1);
			drawBuffer.setOutlineColor(sf::Color::Black);
	}

		void Run(sf::RenderWindow & w)
		{
			if (snake.isDead())
			{
				snake.color = { 0, 255, 0, 255 };
			}
			snake.CheckKeyPress();
			if (delay == maxDelay && !snake.isDead())
			{
				snake.Move();
				delay = 0;
			}
			delay++;

			if (snake.GetHeadPos() == food.pos)
			{
				if (food.GetType() == eType::fast)
					maxDelay -= 3;
				if (food.GetType() == eType::slow)
					maxDelay += 3;

				snake.isGettingLongBoi = true;
				food.pos.x = rand() % size;
				food.pos.y = rand() % size;
				food.SetType((eType)(rand() % 3));
				while (snake.isThere(food.pos.x, food.pos.y) || !activeTiles[food.pos.x][food.pos.y])
				{
					food.pos.x = rand() % size;
					food.pos.y = rand() % size;
					food.SetType((eType)(rand() % 3));
				}
			}


			if (snake.GetHeadPos().x >= 0 && snake.GetHeadPos().y >= 0 && snake.GetHeadPos().x < size && snake.GetHeadPos().y < size)
			{
				if (!activeTiles[snake.GetHeadPos().x][snake.GetHeadPos().y])
					snake.Kill();
			}
			else
			{
				snake.Kill();
			}


			for (int x = 0; x < size; x++)
			{
				for (int y = 0; y < size; y++)
				{
					drawBuffer.setPosition(x * 20, y * 20);

					if (!activeTiles[x][y])
						drawBuffer.setFillColor({ 20, 20, 20, 255 });
					else if (snake.isThere(x, y))
						drawBuffer.setFillColor(snake.color);
					else if (food.isThere(x, y))
						drawBuffer.setFillColor(food.GetColor());
					else
						drawBuffer.setFillColor(sf::Color::White);

					w.draw(drawBuffer);
				}
			}
		}
};

