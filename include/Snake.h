#pragma once
#include "SFML/Graphics.hpp"
#include <queue>
enum class eDir // direction
{
	up,
	down,
	left,
	right
};

class Snake
{
	eDir direction = eDir::right;
	eDir last_direction = eDir::right;
	bool alive = true;

public:
	bool isGettingLongBoi = false;
	Snake(sf::Vector2i pos_)
	{
		sf::Vector2i spawn_point = pos_;
		pos.push_back(spawn_point);
		for (int i = 0; i < 3; i++)
		{
			spawn_point.x++;
			pos.push_back(spawn_point);
		}
	}

	std::vector<sf::Vector2i> pos;
	sf::Color color = { 255, 0, 0, 255 };

	bool isThere(int x, int y)
	{
		for (int i = 0; i < pos.size(); i++)
		{
			if (x == pos[i].x && y == pos[i].y)
				return true;
		}
		return false;
	}


	void CheckKeyPress()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (last_direction != eDir::down)
			{
				direction = eDir::up;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (last_direction != eDir::up)
			{
				direction = eDir::down;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (last_direction != eDir::right)
			{
				direction = eDir::left;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (last_direction != eDir::left)
			{
				direction = eDir::right;
			}
		}
	}

	sf::Vector2i GetHeadPos()
	{
		return pos[pos.size() - 1];
	}

	void Kill()
	{
		alive = false;
	}

	bool isDead()
	{
		if (!alive)
			return true;

		for (int i = 0; i < pos.size() - 1; i++)
		{
			if (pos[i] == pos[pos.size() - 1])
				return true;
		}
		return false;
	}

	void Move()
	{
		sf::Vector2i spawn_pos = pos[pos.size()-1];
		if (direction == eDir::up)
			spawn_pos.y--;
		else if (direction == eDir::down)
			spawn_pos.y++;
		else if (direction == eDir::left)
			spawn_pos.x--;
		else if (direction == eDir::right)
			spawn_pos.x++;

		last_direction = direction;
		pos.push_back(spawn_pos);


		if (!isGettingLongBoi)
			pos.erase(pos.begin());
		else
			isGettingLongBoi = false;
	}
};

