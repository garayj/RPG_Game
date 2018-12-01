#ifndef HEALTH_POTION_HPP
#define HEALTH_POTION_HPP 
#include "Potion.hpp"
#include "Character.hpp"
class HealthPotion : public Potion 
{
public:
	HealthPotion();
	~HealthPotion();
	virtual void usePotion(Character * hero);
	
};
#endif