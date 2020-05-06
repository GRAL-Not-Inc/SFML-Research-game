#pragma once
#include "SFML/Graphics.hpp"

class ComponentSpriteAnimation
{
	int spritesInAnim;
	int animsInFile;

	int tileSize;

	int selectedAnim;
	int selectedTile;

	float frametime;
	float currentFrametime;

	bool bounced;
	bool reverse;

	bool isPlaying;

	sf::Sprite& sprite;
public:
	ComponentSpriteAnimation(sf::Sprite& sprite, int tileSize = 32, float framerate_ = 4.0f, bool bounced = false);
	void Step(float dt);

	void Play();
	void Pause();
	void Reset(int newTile = 0);

	void SetTileSize(int size);
	void SetFramerate(float framerate_);
	void SetBounced(bool bounced_);
	// With this option set to true it plays anim like:  0, 1, 2, 3, 2, 1, 0, 1...
	// With this option set to false it plays anim like: 0, 1, 2, 3, 0, 1, 2, 3...
	// False by default
	void SetAnimRow(int row);
	// By default, first row of sprites is used to animate. Change this value to use
	// lower rows of your spritesheets.
};

