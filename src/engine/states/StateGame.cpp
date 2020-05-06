#include "StateGame.h"
#include <iostream>
StateGame::StateGame(Vars& vars_, sf::RenderWindow& window_)
	:State(vars_, window_),
	mainCharacter(vars.assets.mainCharTex)
{
	vars.assets.mainCharTex.loadFromFile("assets/w.png");
}

void StateGame::Step(float dt)
{
	window.clear({ 0, 0, 0, 255 });
	camera.setSize(window.getSize().x, window.getSize().y);
	camera.setCenter(window.getSize().x / 2, window.getSize().y / 2);
	window.setView(camera);
	// GAME LOGIC HERE VVV
	mainCharacter.Step(dt);
	mainCharacter.Draw(window);
}

void StateGame::Draw()
{
	// DRAWING HERE
	window.draw(mainCharacter.sprite);
}
