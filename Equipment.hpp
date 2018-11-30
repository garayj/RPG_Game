#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP 
#include "Item.hpp"

enum equipmentType{ARMOR, WEAPON};
class Equipment : public Item
{
protected:
	equipmentType type;	
public:
	Equipment();
	virtual ~Equipment()=0;

	//Getter Methods for the data members of the Equipment Class
	equipmentType getType(){return type;};


	//Setter Methods for the data members of the Equipment Class
	void setType(equipmentType type){this->type = type;};
	
};
#endif