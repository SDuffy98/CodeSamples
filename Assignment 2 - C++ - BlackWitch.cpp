/*
* BlackWitch.cpp
*
* Version information: v1.0
* Author: Sean Duffy (B00719262)
* Date: 28/11/17
*
* Copyright notice
*/

#include "BlackWitch.h"

//std::string GameCharacter::characterName_ = "BlackWitch";
//GameCharacter::characterName_ = "BlackWitch";

//default constructor
BlackWitch::BlackWitch()
{
}

//custom contrustor
BlackWitch::BlackWitch(std::string characterName, float health, float weightLimit, int food, CharacterState state, int magicProficiency, int darkPower)
	: magicProficiency_(magicProficiency), darkPower_(darkPower)
{
	this->SetCharacterName(characterName);
	this->Sethealth(health);
	this->SetweightLimit(weightLimit);
	this->Setfood(food);
}

//setters and getters
void BlackWitch::SetmagicProficiency(int magicProficiency)
{
	magicProficiency_ = magicProficiency;
}
int BlackWitch::GetmagicProficiency() const
{
	return magicProficiency_;
}

void BlackWitch::SetdarkPower(int darkPower)
{
	darkPower_ = darkPower;
}
int BlackWitch::GetdarkPower() const
{
	return darkPower_;
}


bool BlackWitch::Attack(GameCharacter & character)
{
	//declaring variables 
	bool success = false;
	Weapon weapon;
	Armour armour = character.GetArmour(character.GetequippedArmour());
	int successfull = (rand() % 100);
	int armourDefence = character.GetArmour(character.GetequippedArmour()).Getdefence();
	int bonusDamage;
	float Damage = character.Gethealth() / 100;
	int tempHealth = character.Gethealth();
	int tempArmourHealth = armour.GetarmourHealth();
	//int armourDamage = extraAttack + 10;

	//declaring the bonus damage for the attacks, due to this character being a blackwitch.
	//if the gamecharacters darkPower is full, their attacks have an etra 20 damage
	if (darkPower_ == 100) {
		bonusDamage = 20;
	}
	else
	{
		//if dark power is less than full, bonusDamage is 0
		bonusDamage = 0;
	}

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
	// if the character is defending, there is only a 20% chance of the attack being succcessfull. 
	if (character.GetState() == Defending && character.GetequippedArmour() != -1 && Gethealth() > 20) {
		if (successfull <= 20) {
			//attack happened
			success = true;
			return true;
		}
		else {
			//otherwise attack failed.
			success = false;
			return false;
		}
	}

	//if character is running, or walking, or idle, they are not wearing armour and thier health is greater than 20, the chance of attack increases to 60%
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
				tempHealth = tempHealth - ((Damage * 10) + bonusDamage);
				//save the characters new health value
				character.Sethealth(character.Gethealth() - tempHealth);

				if (armour.GetitemName().size() > 0) {
					armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % (100 * 90)));
				}
			}
			else if (character.GetState() != Dead || Sleeping || Defending && character.Gethealth() > 20 && character.GetequippedArmour() > -1) {

				// +20% damage for all other types of attacks, idle/walking/running, so using an else statement
				//gamecharacter can have an extra attack if darkpower is full, if it is an extra 20 will be taken off the target characters health
				tempHealth = tempHealth - ((Damage * 20) + bonusDamage);
				character.Sethealth(character.Gethealth() - tempHealth);

				//if the character is wearing armour, cause damage to the armour due to attack
				if (armour.GetitemName().size() > 0)
				{
					armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % (100 * 90)));
				}
			}
		}
		//if characters armour health reaches 0, drop the armour
		if (character.GetArmour(character.GetequippedArmour()).GetarmourHealth() <= 0) {
			DropItem(character.GetArmour(character.GetequippedArmour()));
		}
	}
	//if attack is not true, cause damage to the gamecharacters weapon, random chance between 10 and 20%
	if (success == false) {
		if (character.GetequippedWeapon() > -1) {
			int weaponHealth = weapon.GetweaponHealth();
			int randDamage = rand() % 11 + 10;
			weapon.SetweaponHealth(weaponHealth - randDamage);

			//if gamecharacters weapon health reaches 0, drop weapon
			if (weapon.GetweaponHealth() <= 0) {
				DropItem(weapon);
			}
		}
	}
	//return the variable
	return success;
}

void BlackWitch::Bewitch(GameCharacter & character)
{
	//declaring variables
	float bchance = 10;
	float profChance = GetmagicProficiency() * 5;
	float totalSuccess = bchance + profChance;
	float hit = rand() % 100;

	if (hit <= totalSuccess) {
		character.Sleep();
	}
	else {
		return;
	}
}

void BlackWitch::Sleep()
{
	SetState(CharacterState::Sleeping);
	int tempHealth = Gethealth() / 100;
	tempHealth = tempHealth * 115;
	Sethealth(tempHealth);
	//loop to make sure characters health does not exceed 100.
	if (Gethealth() > 100)
	{
		Sethealth(100);
	}
}




//default destructor
BlackWitch::~BlackWitch()
{
}
