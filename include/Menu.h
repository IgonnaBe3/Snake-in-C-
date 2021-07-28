#pragma once
#include "Playfield.h"
#include <iostream>
class Menu
{
public:
	bool IsDone = true;

	eShape selectedType=eShape::circle; //= eShape::square;
	int n, size;
	void Run()
	{

		std::cout << "MAP:" << std::endl;
		std::cout << "1.Square." << std::endl;
		std::cout << "2.Circle." << std::endl;
		std::cout << "3.Triangle." << std::endl;
		std::cin >> n;

		switch (n)
		{
		case 1:
		{

			 selectedType = eShape::square;
		}
		break;
		case 2:
		{
			 selectedType = eShape::circle;
		}
		break;
		case 3:
		{
			 selectedType = eShape::triangle;

		}
		break;
		default:

		break;
		}

		std::cout << "Map Size:";
		std::cin >> size;

		IsDone = false;

	}
};
