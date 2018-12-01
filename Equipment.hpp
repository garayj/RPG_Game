#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP 
#include "Item.hpp"
#include "characterClass.hpp"

enum equipmentType{ARMOR, WEAPON};
class Equipment : public Item
{
protected:
	characterClass classType;
	equipmentType type;	
public:
	Equipment();
	virtual ~Equipment()=0;

	//Getter Methods for the data members of the Equipment Class
	equipmentType getType(){return type;};
	characterClass getClassType(){return classType;};


	//Setter Methods for the data members of the Equipment Class
	void setType(equipmentType type){this->type = type;};
	void setClassType(characterClass classType){this->classType = classType;};
	
};
#endif