#include "Character.h"

void Character::Step(float dt)
{
	// This is utterly fucking retarded. (But temporary).
	animation.SetAnimRow(0);
	animation.Play();
	bool isMoving = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		animation.SetAnimRow(1);
		isMoving = true;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		animation.SetAnimRow(2);
		isMoving = true;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		animation.SetAnimRow(0);
		isMoving = true;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		animation.SetAnimRow(3);
		isMoving = true;
	}
	if (!isMoving)
	{
		animation.Pause();
		animation.Reset(1);
	}
	animation.Step(dt);
}

void Character::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
