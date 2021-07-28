#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Playfield.h"
#include "Menu.h"
#include <iostream>

int main()
{
	srand(time(NULL));
	sf::RenderWindow w(sf::VideoMode(1000, 1000), "Default Window!", sf::Style::Close | sf::Style::Titlebar);
	sf::Event e;
	std::cout << "Hello SFML!" << std::endl;
	Menu m;
	while (m.IsDone)
	{
		m.Run();

	}
	Playfield p(m.selectedType, m.size);
	while (true)
	{
		w.pollEvent(e);
		p.Run(w);
		sf::sleep(sf::milliseconds(16));
		w.display();
	}
	std::cin.get();
	return 0;
}
