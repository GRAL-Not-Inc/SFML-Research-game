#include "ComponentStamina.h"

void ComponentStamina::_Update()
{
	if (current > max) current = max;
	if (current < 0) current = 0;
}

void ComponentStamina::SetCurrent(float amount)
{
	current = amount;
	_Update();
}

void ComponentStamina::Drain(float amount)
{
	current -= amount;
}

void ComponentStamina::Regenerate(float amount)
{
	current += amount;
}

void ComponentStamina::SetMax(float amount)
{
	max = amount;
	if (max < 0) max = 0;
}
