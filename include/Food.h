#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
enum class eType
{
	normal,
	fast,
	slow
};


class Food
{
	eType type = eType::normal;
	sf::Color color = { 255, 255, 0, 255 };
public:
	Food(sf::Vector2i pos_)
	{
		pos = pos_;
	}

	bool isThere(int x, int y)
	{
		if (pos == sf::Vector2i(x, y))
			return true;
		else
			return false;
	}

	void SetType(eType newType)
	{
		type = newType;
		switch (type)
		{
		case eType::normal:
			color = { 255, 255, 0, 255 };
			break;
		case eType::fast:
			color = { 0, 0, 255, 255 };
			break;
		case eType::slow:
			color = { 0, 255, 255, 255 };
			break;
		}
	}
	eType GetType()
	{
		return type;
	}

	sf::Color GetColor()
	{
		return color;
	}

	sf::Vector2i pos;

};

