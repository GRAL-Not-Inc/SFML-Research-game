#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
enum class eState
{
	menu,
	game
};

struct Assets
{

};

struct Vars
{
	bool is_running;
	float framerate;
	bool fullscreen;

	eState prev_state;
	eState current_state;
	eState next_state;

	Assets assets;

};

