#include "Character.h"

void Character::change_pos(int pos, float dt)
{
	switch (pos)
	{
	case 1:
		//test
		sprite.setTextureRect({ 32,0,32,32 });
		sprite.move({ 0,1 * dt });
		break;
	case 2:
		sprite.setTextureRect({ 32,32,32,32 });
		sprite.move({ -1*dt,0 });
		break;
	case 3:
		sprite.setTextureRect({ 32,64,32,32 });
		sprite.move({ 1 * dt,0 });
		break;
	case 4:
		sprite.setTextureRect({ 32,96,32,32 });
		sprite.move({ 0,-1*dt });
		break;
	}
}
