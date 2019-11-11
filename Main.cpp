#include <SFML\Window.hpp>
int main()
{
	sf::Window window(sf::VideoMode(1920, 1080), "GRAL nie umie into programowanie");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{

				case sf::Keyboard::Escape:
					window.close();
					break;

				default:
					break;
				}
			}
		
		}
	}

	return 0;
}
//dodam sobie komentarz