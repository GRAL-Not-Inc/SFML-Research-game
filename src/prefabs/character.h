#pragma once
#include "SFML/Graphics.hpp"
#include "../components/ComponentStamina.h"
#include "../components/ComponentHealth.h"
#include "../components/ComponentSpriteAnimation.h"
class Character
{
public:
	ComponentStamina stamina;
	ComponentHealth health;
	ComponentSpriteAnimation animation;

	sf::Sprite sprite;
	Character(sf::Texture& tex):
		health(100),
		stamina(100),
		sprite(tex),
		animation(sprite, 32, 4, true)
	{
	}
	void Step(float dt);
	void Draw(sf::RenderWindow& window);
};

