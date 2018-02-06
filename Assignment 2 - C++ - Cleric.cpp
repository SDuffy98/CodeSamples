/*
* Cleric.cpp
*
* Version information: v1.0
* Author: Sean Duffy (B00719262)
* Date: 28/11/17
*
* Copyright notice
*/

#include "Cleric.h"

//std::string characterName_ = "Cleric";

//default constructor
Cleric::Cleric() {}

//custom constrcutor

Cleric::Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState state, int pietyLevel)
	: pietyLevel_(pietyLevel)
{
	this->SetCharacterName(characterName);
	this->Sethealth(health);
	this->SetweightLimit(weightLimit);
	this->Setfood(food);
}

//setters and getters
void Cleric::SetpietyLevel(int pietyLevel)
{
	pietyLevel_ = pietyLevel;
}
int Cleric::GetpietyLevel() const
{
	return pietyLevel_;
}

//not sure if works, attack function is in the gamecharacter.cpp file, trying to call that function here.
bool Cleric::Attack(GameCharacter & character)
{
	//declaring variables 
	bool success = false;
	Weapon weapon;
	Armour armour = character.GetArmour(character.GetequippedArmour());
	int successfull = (rand() % 100);
	int armourDefence = character.GetArmour(character.GetequippedArmour()).Getdefence();
	//int extraAttack = (strength_ / 10) * 5;
	float Damage = character.Gethealth() / 100;
	int tempHealth = character.Gethealth();
	int tempArmourHealth = armour.GetarmourHealth();
	//int armourDamage = extraAttack + 10;

	if (character.GetState() == Dead || character.Gethealth() <= 20) {
		//attack failed if character is dead or health is below 20
		success = false;
		return false;
	}
	//if character is not dead && they do not have armour
	if (character.GetState() == Defending  && character.GetequippedArmour() == -1 && Gethealth() > 20) {

		//get the Gamecharacters characters weapon
		weapon = GetWeapon(GetequippedWeapon());

		//if the 80% chance is true, attack can begin, else attack has failed
		if (successfull <= 80) {
			success = true;
			return true;
		}
		else {
			success = false;
			return false;
		}
	}
	//if character is defending, theres a 20% chance of the attack happening.
	if (character.GetState() == Defending && character.GetequippedArmour() != -1 && Gethealth() > 20) {
		if (successfull <= 20) {
			success = true;
			return true;
		}
		else {
			success = false;
			return false;
		}
	}
	//for all other states there is a 60% chance of the attack being successful
	if (character.GetState() == Idle || Running || Walking && character.GetequippedArmour() != -1 && Gethealth() > 20) {
		if (success <= 60) {
			success = true;
			return true;
		}
		else {
			success = false;
			return false;
		}
	}

	//if the attack is true, decide what type of damage to take 
	if (success = true) {
		//if the character is sleeping, health is automatically set to 0 when being attacked
		if (character.GetState() == Sleeping) {

			//character is dead 
			character.Sethealth(0);

			//if the character is wearing armour
			if (armour.GetitemName().size() > 0) {
				//cause damage to armour due to the attack
				armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % (100 * 90)));
			}
		}

		if (Gethealth() > 20) {
			if (character.GetState() == Defending && successfull <= 20)
			{
				//10% extra damage is character is defending + 10% 
				tempHealth = tempHealth - ((Damage * 10));
				//save the characters new health value
				character.Sethealth(character.Gethealth() - tempHealth);

				if (armour.GetitemName().size() > 0) {
					armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % (100 * 90)));
				}
			}
			else if (character.GetState() != Dead || Sleeping || Defending && character.Gethealth() > 20 && character.GetequippedArmour() > -1) {
				// +20% damage for all other types of attacks, idle/walking/running, so using an else statement
				tempHealth = tempHealth - ((Damage * 20));
				character.Sethealth(character.Gethealth() - tempHealth);

				//if character has armour, deal damage to armour since attack took place
				if (armour.GetitemName().size() > 0)
				{
					armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % (100 * 90)));
				}
			}
		}
		//if armour health reaches 0, 
		if (character.GetArmour(character.GetequippedArmour()).GetarmourHealth() <= 0) {
			DropItem(character.GetArmour(character.GetequippedArmour()));
		}
	}
	//if attack didnt happen, the characters wepaon has to be damaged
	if (success == false) {
		//if the gamecharacter has a weapon
		if (character.GetequippedWeapon() > -1) {
			int weaponHealth = weapon.GetweaponHealth();
			int randDamage = rand() % 11 + 10;
			weapon.SetweaponHealth(weaponHealth - randDamage);
			//if the weapon heath is 0, drop the weapon
			if (weapon.GetweaponHealth() <= 0) {
				DropItem(weapon);
			}
		}
	}
	return success;
}
	


void Cleric::PrayFor(GameCharacter & character)
{
	//declaring the variables to use within this class
	int prayForChance = rand() % 100;
	//finding 5% of the characters current health
	int fivePercent = character.Gethealth() / 100 * 5;
	//setting the characters health to 5% x the pietyLevel
	int addHealth11 = character.Gethealth() + (fivePercent * pietyLevel_);
	//50% chance of this working 
		if (prayForChance <= 50) {
			//if ot works, set the characters health 
			character.Sethealth(addHealth11);
			GameCharacter::Sethealth(addHealth11);
		}
}

void Cleric::Sleep()
{
	//set the characters state to sleeping 
	SetState(CharacterState::Sleeping);
	//finding 1% of the characters health 
	int tempHealth = Gethealth() / 100;
	//multiplying the characters health by 120
	tempHealth = tempHealth * 120;
	Sethealth(tempHealth);
	//loop to make sure health does not exceed 100
	if (Gethealth() > 100)
	{
		Sethealth(100);
	}
}


//default destructor
Cleric::~Cleric()
{
}
