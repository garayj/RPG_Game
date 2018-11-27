/**************************************************************************************************
** Author: Jose Garay
** Date: 11/2/2018
** Description: Interface file for the Character Class. The Character Class is an Abstract class
that simulates the base charcateristics of a character in a table top game. 
**************************************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP 
#include <cstdlib>
#include <string>
enum characterType {MONSTER, HERO};
enum characterClass{PALADIN, ROGUE, WHITE_MAGE, BLACK_MAGE, WARRIOR_GNOME, ARCHER};
class Character{
protected:

	int numberOfDefDie;
	int numberOfAttDie;
	int defDieSides;
	int attDieSides;

	int power;
	int speed;
	int armor;
	int maxHealth;
	int health;

	characterType type;
	characterClass cClass;
	std::string name;
	bool isAlive;


/**************************************************************************************************
** Description: Protected Function. Takes two integer arguments as input, the number of dice and 
the number of sides the die has, and returns an integer representing the sum of rolling those dice.
**************************************************************************************************/
	int roll(int,int);



public:
/**************************************************************************************************
** Description: Constructor for the Character Class.
**************************************************************************************************/
	Character();
/**************************************************************************************************
** Description: Deconstructor for the Character Class.
**************************************************************************************************/
	virtual ~Character()=0;





/**************************************************************************************************
** Description: Abstract Function. Defined in derived class. Calculates the attack the character
makes.
**************************************************************************************************/
	virtual int attack();

/**************************************************************************************************
** Description: Abstract Function. Defined in derived class. Calculates the defense the character
makes and sets the strength of the character.
**************************************************************************************************/
	virtual void defend(int);
/**************************************************************************************************
** Description: Public Function. Takes in an integer that represents the damage the Charcter has 
taken and recovers 50% of the damage taken.
**************************************************************************************************/
	void recover(int);





/**************************************************************************************************
** Description: Getter Funciton. Returns an integer representing the speed a character has.
**************************************************************************************************/
	int getSpeed(){ return speed;};

/**************************************************************************************************
** Description: Getter Funciton. Returns an integer representing the speed a character has.
**************************************************************************************************/
	int getPower(){ return power;};

/**************************************************************************************************
** Description: Getter Funciton. Returns an integer representing the armor a character has.
**************************************************************************************************/
	int getArmor(){ return armor;};

/**************************************************************************************************
** Description: Getter Function. Returns an integer representing the health a character has.
**************************************************************************************************/
	int getHealth(){ return health;};

/**************************************************************************************************
** Description: Getter Function. Returns an integer representing the max health a character has.
**************************************************************************************************/
	int getMaxHealth(){ return maxHealth;};

/**************************************************************************************************
** Description: Getter Function. Returns an integer that represents the number of defense die a
character has.
**************************************************************************************************/
	int getNumberOfDefDie(){return numberOfDefDie;};

/**************************************************************************************************
** Description: Getter Function. Returns an integer that represents the number of attack die a
character has.
**************************************************************************************************/
	int getNumberOfAttDie(){return numberOfAttDie;};

/**************************************************************************************************
** Description: Getter Function. Returns an integer that represents the number of sides a defense
die has.
**************************************************************************************************/
	int getDefDieSides(){return defDieSides;};

/**************************************************************************************************
** Description: Getter Function. Returns an integer that represents the number of sides an attack 
die has.
**************************************************************************************************/
	int getAttDieSides(){return attDieSides;};

/**************************************************************************************************
** Description: Getter Function. Returns a string that is the character type.
**************************************************************************************************/
	characterType getType(){return type;};

/**************************************************************************************************
** Description: Getter Function. Returns a characterClass that is the character's class.
**************************************************************************************************/
	characterClass getCharacterClass(){return cClass;};

/**************************************************************************************************
** Description: Getter Function. Returns a string that is the character name.
**************************************************************************************************/
	std::string getName(){return name;};

/**************************************************************************************************
** Description: Getter Function. Returns a boolean that represents if the character is alive or 
dead.
**************************************************************************************************/
	bool getIsAlive(){return isAlive;};

/**************************************************************************************************
** Description: Public Function. The getCharacterClassString returns a string of what the character
class is. Takes no arguments.
**************************************************************************************************/
	std::string getCharacterClassString();





/**************************************************************************************************
** Description: Setter Funciton. Takes an integer argument and sets the speed a character has.
**************************************************************************************************/
	void setSpeed(int speed){ this->speed = speed;};


/**************************************************************************************************
** Description: Setter Funciton. Takes an integer argument and sets the power a character has.
**************************************************************************************************/
	void setPower(int power){ this->power = power;};

/**************************************************************************************************
** Description: Setter Function. Takes one integer argument and sets the Armor of a character.
**************************************************************************************************/
	void setArmor(int a){ armor = a;};

/**************************************************************************************************
** Description: Setter Function. Takes one integer argument and sets the health of a character.
**************************************************************************************************/
	void setHealth(int health){ this->health = health;};

/**************************************************************************************************
** Description: Setter Function. Takes one integer argument and sets the health of a character.
**************************************************************************************************/
	void setMaxHealth(int maxHealth){ this->maxHealth = maxHealth;};

/**************************************************************************************************
** Description: Setter Function. Takes one integer argument and sets the number of die of a 
character has for defense.
**************************************************************************************************/
	void setNumberDefDie(int defDie){numberOfDefDie = defDie;};
/**************************************************************************************************
** Description: Setter Function. Takes one integer argument and sets the number of die of a 
character has for attack.
**************************************************************************************************/
	void setNumberAttDie(int attDie){numberOfAttDie = attDie;};
/**************************************************************************************************
** Description: Setter Function. Takes one integer argument and sets the number of side a die has
for defense.
**************************************************************************************************/
	void setDefDieSides(int sides){defDieSides = sides;};
/**************************************************************************************************
** Description: Setter Function. Takes one integer argument and sets the number of side a die has
for attack.
**************************************************************************************************/
	void setAttDieSides(int sides){attDieSides = sides;};

/**************************************************************************************************
** Description: Setter Function. Takes in characterType argument and sets the type.
**************************************************************************************************/
	void setCharacterType(characterType cType){this->type = cType;};

/**************************************************************************************************
** Description: Setter Function. Takes in characterType argument and sets the type.
**************************************************************************************************/
	void setCharacterClass(characterClass cClass){this->cClass = cClass;};

/**************************************************************************************************
** Description: Setter Function. Takes in string argument and sets the character name.
**************************************************************************************************/
	void setName(std::string name){this->name = name;};

/**************************************************************************************************
** Description: Setter Function. Takes in a bool argument and sets the isAlive data member.
**************************************************************************************************/
	void setIsAlive(bool isAlive){this->isAlive = isAlive;};
};
#endif