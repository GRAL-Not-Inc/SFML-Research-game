#pragma once
#include "../State.h"

class StateGame : public State
{
	sf::View camera;
public:
	StateGame(Vars& vars_, sf::RenderWindow& window_);
	virtual void Step(float dt);
	virtual void Draw();
};

