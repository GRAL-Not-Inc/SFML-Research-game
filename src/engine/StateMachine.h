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
	// Add a state to the game's state machine. Eg. "Menu", "Level1", "Level2"
	// vars - Reference to game instance's global variable set. Used for settings, assets, etc.
	// window - Reference to window this state will be linked to.
	// eState - enum class to identify what state is it. Used as a key for map of states
	// inside of state machine.

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

	void Delete(eState state)
	{
		if (states.count(state) != 0)
			states.erase(state);
	}
};

