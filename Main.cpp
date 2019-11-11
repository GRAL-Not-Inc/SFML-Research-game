#include <SFML\Window.hpp>
// Narazie zostawiam tak, na czysto. Mozliwe, ze czeka nas update SFML
// lub zmiany workflowu. Do tej pory uporzadkowuje tylko Git-flow.


int main()
{
	sf::Window window(sf::VideoMode(1280, 720), "GRAL Game Test v0.1");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)//komentarz
				window.close();
		}
	}
	return 0;
}