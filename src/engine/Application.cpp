#include "Application.h"

Application::Application(unsigned int window_height_, unsigned int window_width_, float framerate_, bool fullscreen_)
	:window(sf::VideoMode(window_height_, window_width_),
		"Hug",
		sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize | (fullscreen_ & sf::Style::Fullscreen)),
	window_height(window_height_),
	window_width(window_width_),
	framerate(framerate_),
	is_running(true)
{
	state_machine.AddState<StateGame>(vars, window, eState::game);
	vars.current_state = eState::game;
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

		// State machine logic here

		state_machine.Step(dt, vars.current_state);
		state_machine.Draw(vars.current_state);

		// Displaying

		window.display();

		//
		//
		//
	}
}
