#include "ComponentSpriteAnimation.h"
#include <iostream>
ComponentSpriteAnimation::ComponentSpriteAnimation(sf::Sprite& sprite_, int tileSize, float framerate_, bool bounced)
	:sprite(sprite_),
	frametime(1000 / framerate_),
	tileSize(tileSize),
	bounced(bounced),
	selectedTile(0),
	currentFrametime(0),
	reverse(false)
{

}

void ComponentSpriteAnimation::Step(float dt)
{
	if (isPlaying)
	{
		if (currentFrametime > frametime)
		{
			spritesInAnim = sprite.getTexture()->getSize().x / tileSize;
			animsInFile = sprite.getTexture()->getSize().y / tileSize;

			if (!bounced)
			{
				selectedTile++;
				if (selectedTile >= spritesInAnim - 1)
					selectedTile = 0;
			}
			else
			{
				if (!reverse)
				{
					if (selectedTile == spritesInAnim - 1)
					{
						selectedTile--;
						reverse = true;
					}
					else
					{
						selectedTile++;
					}
				}
				else
				{
					if (selectedTile == 0)
					{
						selectedTile++;
						reverse = false;
					}
					else
					{
						selectedTile--;
					}
				}
			}
			currentFrametime = 0;

			if (selectedTile > spritesInAnim - 1)
				selectedTile = spritesInAnim - 1;
			else if (selectedTile < 0)
				selectedTile = 0;

			if (selectedAnim > animsInFile - 1)
				selectedAnim = animsInFile - 1;
			else if (selectedAnim < 0)
				selectedAnim = 0;
		}
		currentFrametime += dt;
	}
	sprite.setTextureRect(sf::IntRect(selectedTile * tileSize, selectedAnim * tileSize, tileSize, tileSize));
}

void ComponentSpriteAnimation::Play()
{
	isPlaying = true;
}

void ComponentSpriteAnimation::Pause()
{
	isPlaying = false;
}

void ComponentSpriteAnimation::Reset(int newTile)
{
	currentFrametime = 0;
	selectedTile = newTile;
}

void ComponentSpriteAnimation::SetTileSize(int size)
{
	if (size > 0)
	{
		tileSize = size;
	}
}

void ComponentSpriteAnimation::SetFramerate(float framerate_)
{
	if (framerate_ > 0)
	{
		frametime = 1000 / framerate_;
	}
}

void ComponentSpriteAnimation::SetBounced(bool bounced_)
{
	bounced = bounced_;
}

void ComponentSpriteAnimation::SetAnimRow(int row)
{
	selectedAnim = row;
}
