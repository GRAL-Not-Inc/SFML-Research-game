#pragma once
class ComponentStamina
{
protected:
	void _Update();
public:
	float current;
	float max;

	ComponentStamina(float max = 100, float current = 100)
		:current(current),
		max(max)
	{
	}

	void SetCurrent(float amount);
	void Drain(float amount);
	void Regenerate(float amount);
	void SetMax(float amount);
};

