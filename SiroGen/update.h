#ifndef UPDATE_H_
#define UPDATE_H_
#include <SiroGen/component.h>
#include <SiroGen/entity.h>

class Update :
	public Component
{
public:
	Update(Entity* owner);
	virtual void DoIt(unsigned int _shader);
};

#endif
