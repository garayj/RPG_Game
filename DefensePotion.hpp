#ifndef DEFENSE_POTION_HPP
#define DEFENSE_POTION_HPP 
#include "Potion.hpp"
#include "Character.hpp"
class DefensePotion : public Potion 
{
public:
	DefensePotion();
	~DefensePotion();
	virtual void usePotion(Character * hero);
	
};
#endif