#include "Application.h"

Application::Application(unsigned int window_height_, unsigned int window_width_, float framerate_, bool fullscreen_)
	:window(sf::VideoMode(window_height_, window_width_),
		"CHuj",
		sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize | (fullscreen_ & sf::Style::Fullscreen)),
	window_height(window_height_),
	window_width(window_width_),
	framerate(framerate_),
	is_running(true),
	mc("assets/m.png")
{
}

void Application::Run()
{
	sf::Event events;

	float dtDesired = (1.0f / framerate) * 1000.0f; // In milliseconds.
	float dt = 0;

	sf::Clock dtClock;
	dtClock.restart();

	while (is_running)
	{
		// Timing
		dt = dtClock.getElapsedTime().asMilliseconds();
		if (dt < dtDesired)
		{
			sf::sleep(sf::milliseconds(dtDesired) - sf::milliseconds(dt));
			dt = dtClock.getElapsedTime().asMilliseconds();
		}
		else if (dt > dtDesired * 5)
			dt = dtDesired * 5;

		dtClock.restart();

		if (window.pollEvent(events))
		{
			if (events.type == sf::Event::Closed)
			{
				is_running = false;
			}
		}

		//
		// Game state update
		//
		window.clear({ 0, 0, 0, 255 });
		view.setSize(window.getSize().x, window.getSize().y);
		view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
		window.setView(view);

		// VVV GAME LOGIC HERE VVV

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			mc.change_pos(1,dt);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			mc.change_pos(2,dt);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			mc.change_pos(3,dt);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			mc.change_pos(4,dt);
		}

		window.draw(mc.sprite);







		// END OF GAME LOGIC

		window.display();

		//
		//
		//
	}
}
