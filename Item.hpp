/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: Interface for the Item Class. The Item class is an abstract class that has the 
basic components of all items. All items inherit from the Item class.
**************************************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP 
#include <string>
enum itemType{EQUIPMENT, POTION, KEY};
class Item
{
protected:
	itemType iType;
	int effect;
	std::string itemName;
	std::string description;
public:
	Item();
	virtual ~Item()=0;

	itemType getItemType(){return iType;};
	int getEffect(){return effect;};
	std::string getItemName(){return itemName;};
	std::string getDescription(){return description;};
 
 	void setItemType(itemType iType){this->iType = iType;};
	void setEffect(int effect){this->effect = effect;};
	void setItemName(std::string itemName){this->itemName = itemName;};
	void setDescription(std::string description){this->description = description;};
	
};
#endif