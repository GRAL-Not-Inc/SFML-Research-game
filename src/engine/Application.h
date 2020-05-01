#pragma once
#include "StateMachine.h"
#include "SFML/Graphics.hpp"
#include "../prefabs/Character.h"
class Application
{
	StateMachine state_machine;

	sf::RenderWindow window;
	sf::View view;
	sf::Cursor cursor;

	float framerate;
	bool is_running;

	unsigned int window_width;
	unsigned int window_height;

public:
	Application(unsigned int window_height = 500, unsigned int window_width = 500, float framerate_ = 60.0f , bool fullscreen_ = false);
	void Run();
};

