#ifndef ITEM_HPP
#define ITEM_HPP 
#include <string>
enum itemType{EQUIPMENT, POTION};
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