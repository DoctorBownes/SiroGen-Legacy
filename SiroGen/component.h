#ifndef COMPONENT_H_
#define COMPONENT_H_
class Entity;

class Component
{
public:
	Entity* _Owner = nullptr;
	Component();
	virtual ~Component();
	Component(Entity* owner);
	virtual void DoIt(unsigned int _shader) = 0;
};
#endif