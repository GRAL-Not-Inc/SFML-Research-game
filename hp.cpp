#include "hp.h"

void ComponentHealth::GetHit(float hit)
{
	hp_current -= hit;
	if (hp_current <= 0)
	{
		//ded();
	}
}

void ComponentHealth::GetHealed(float heal)
{
	hp_current += heal;
	if (hp_current > hp_max)
	{
		hp_current = hp_max;
	}
}
