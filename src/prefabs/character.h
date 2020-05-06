#pragma once
#include "SFML/Graphics.hpp"
#include "../components/ComponentStamina.h"
#include "../components/ComponentHealth.h"
#include "../components/ComponentSpriteAnimation.h"
class Character
{
private:
	sf::Texture texture;
	int timer = 0, kl = 32;
	bool pong = false;
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

