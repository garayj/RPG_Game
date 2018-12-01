#ifndef PHOENIX_DOWN_HPP 
#define PHOENIX_DOWN_HPP 
#include "Potion.hpp"
#include "Character.hpp"
class PhoenixDown : public Potion 
{
public:
	PhoenixDown();
	~PhoenixDown();
	virtual void usePotion(Character * hero);
	
};
#endif