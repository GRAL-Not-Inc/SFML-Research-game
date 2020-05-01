#pragma once
#include "State.h"


class StateMachine
{
	std::map<eState, std::shared_ptr<State>> states;

public:

	template <class TStateType>
	void AddState(Vars& vars, sf::RenderWindow& window, eState state)
	{
		bool is_already = false;

		if (states.count(state) != 0)
			is_already = true;

		if (!is_already)
		{
			states[state] = std::make_shared<TStateType>(vars, window);
		}
	}

	void Step(float dt, eState state)
	{
		if (states.count(state) != 0)
			states.find(state)->second->Step(dt);
	}

	void Draw(eState state)
	{
		if (states.count(state) != 0)
			states.find(state)->second->Draw();
	}
};

