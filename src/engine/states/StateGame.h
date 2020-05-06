#pragma once
#include "../State.h"
#include "../../prefabs/Character.h"

class StateGame : public State
{
	sf::View camera;

	Character mainCharacter;

public:
	StateGame(Vars& vars_, sf::RenderWindow& window_);
	virtual void Step(float dt);
	virtual void Draw();
};

