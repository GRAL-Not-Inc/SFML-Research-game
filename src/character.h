#pragma once
#include "SFML/Graphics.hpp"
class Character
{
private:
	sf::Texture texture;
	int timer = 0, kl = 32;
	bool pong = false;
public:
	sf::Sprite sprite;
	Character(std::string texture_)
	{
		texture.loadFromFile(texture_);
		sprite.setTexture(texture);
		sprite.setTextureRect({ 32, 0, 32, 32 });
	}

	void change_pos(int,float);
	void anim(float);
};

