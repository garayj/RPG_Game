#ifndef POTION_HPP
#define POTION_HPP 
#include "Item.hpp"
#include "Character.hpp"
class Potion : public Item
{
public:
	Potion();
	~Potion();

	virtual void usePotion(Character *)=0;
	
};
#endif