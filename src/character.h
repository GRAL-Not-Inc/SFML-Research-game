#pragma once
#include "SFML/Graphics.hpp"
class character
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;
	character(std::string texture_)
	{
		texture.loadFromFile(texture_);
		sprite.setTexture(texture);
		sprite.setTextureRect({ 32, 0, 32, 32 });
	}

	void change_pos(int,float);
};

