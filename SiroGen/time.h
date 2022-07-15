#ifndef TIME_H_
#define TIME_H_
#include <SiroGen/entity.h>
#include <vector>

class Time
{
public:
	Time(const Time&) = delete;

	static Time* GetInstance()
	{
		if (!_instance)
		{
			_instance = new Time();
		}
		return _instance;
	}

	std::vector<Entity*> UpdateableEntites;
	void CalculateDeltaTime();

	float deltaTime = 0.0f;

private:
	Time();
	static Time* _instance;
};

#endif
