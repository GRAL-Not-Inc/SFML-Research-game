#pragma once
class ComponentHealth
{
public:
	float hp_max, hp_current;

	ComponentHealth(float hp_max_)
	{
		hp_max = hp_max_;
		hp_current = hp_max_;
	}

	void GetHit(float);
	void GetHealed(float);
};

