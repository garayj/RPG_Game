/**************************************************************************************************
** Author: Jose Garay
** Date: 11/27/2018
** Description: Interface file for the BlackMage Class. The BlackMage Class is a character within
the unknown Fantasy Game. Black Mage has an Armor rating of 0, Max Health of 10, attacks with 1d4 and
defends with 4d6. The Black Mage class as the special ability to attack with magic missle.
*************************************************************************************************/
#ifndef BLACK_MAGE_HPP 
#define BLACK_MAGE_HPP 
#include "Character.hpp"
class BlackMage: public Character
{
private:
	int maxMana;
	int mana;
	int magicPower;
public:

/**************************************************************************************************
** Description: Constructor for the Paladin Class.
*************************************************************************************************/
	BlackMage();
/**************************************************************************************************
** Description: Deconstructor for the Paladin Class.
*************************************************************************************************/
	~BlackMage();




/**************************************************************************************************
** Description: Getter Function. Returns an integer representing the max mana the Black Mage has.
*************************************************************************************************/
	int getMaxMana(){return maxMana;};

/**************************************************************************************************
** Description: Getter Function. Returns an integer representing how much mana the Black Mage has.
If the Black Mage has no mana, then the Black Mage cannot cast magicMissle.
*************************************************************************************************/
	int getMana(){return mana;};

/**************************************************************************************************
** Description: Getter Function. Returns an integer representing the magicPower of a Black Mage. 
*************************************************************************************************/
	int getMagicPower(){return magicPower;};






/**************************************************************************************************
** Description: Setter Function. Sets the max amount of mana the Black Mage has.
*************************************************************************************************/
	void setMaxMana(int maxMana){this->maxMana = maxMana;};
/**************************************************************************************************
** Description: Setter Function. Sets the amount of mana the Black Mage has.
*************************************************************************************************/
	void setMana(int mana){this->mana = mana;};

/**************************************************************************************************
** Description: Setter Function. Sets the amount of magicPower the Black Mage has.
*************************************************************************************************/
	void setMagicPower(int magicPower){this->magicPower = magicPower;};





/**************************************************************************************************
** Description: Public Function. The magicMissle method simulates a magic attack from the Black 
Mage. Signigicantly more powerful than regular attack. Monsters cannot dodge.
*************************************************************************************************/
	int magicMissle();
	
};
#endif