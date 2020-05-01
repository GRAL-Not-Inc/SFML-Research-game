#include "Character.h"

void Character::anim(float dt)
{
	if (timer >= 200)
	{
		if (kl >= 64)
		{
			pong = true;
		}
		if (kl <= 0)
		{
			pong = false;
		}
		if (pong == false)
		{
			kl += 32;
		}
		if (pong == true)
		{
			kl -= 32;
		}
		timer = 0;
	}
	timer += dt;
}

void Character::change_pos(int pos, float dt)
{
	anim(dt);
	switch (pos)
	{
	case 1:
		sprite.setTextureRect({ kl,0,32,32 });
		sprite.move({ 0,1 * dt });
		break;
	case 2:
		sprite.setTextureRect({ kl,32,32,32 });
		sprite.move({ -1*dt,0 });
		break;
	case 3:
		sprite.setTextureRect({ kl,64,32,32 });
		sprite.move({ 1 * dt,0 });
		break;
	case 4:
		sprite.setTextureRect({ kl,96,32,32 });
		sprite.move({ 0,-1*dt });
		break;
	}
}
