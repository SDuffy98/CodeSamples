/*
* Orc.cpp
*
* Version information: v1.0
* Author: Sean Duffy B00719262
* Date: 28/11/17
*
* Copyright notice
*/
#include <string>
#include <iostream>
#include "Orc.h"

//std::string characterName_ = "Orc";

//default construtor
Orc::Orc() {}

//custom constructor
Orc::Orc(std::string characterName, float health, float weightLimit, int food, CharacterState state, int ferociousness, int strength) :
	ferociousness_(ferociousness), strength_(strength)
{
	this->SetCharacterName(characterName);
	this->Sethealth(health);
	this->SetweightLimit(weightLimit);
	this->Setfood(food);
}

void Orc::Setferociousness(int ferociousness)
{
	ferociousness_ = ferociousness;
}
int Orc::Getferociousness() const
{
	return ferociousness_;
}

void Orc::Setstrength(int strength)
{
	strength_ = strength;
}
int Orc::Getstrength() const
{
	return strength_;
}

bool Orc::Attack(GameCharacter & character)
{
	//declaring variables 
	bool success = false;
	Weapon weapon;
	Armour armour = character.GetArmour(character.GetequippedArmour());
	int successfull = (rand() % 100);
	int armourDefence = character.GetArmour(character.GetequippedArmour()).Getdefence();
	int extraAttack = (strength_ / 10) * 5;
	float Damage = character.Gethealth() / 100;
	int tempHealth = character.Gethealth();
	int tempArmourHealth = armour.GetarmourHealth();
	
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
	//if characters state is defending only a 20% chance of the attack being successful.
	if (character.GetState() == Defending && character.GetequippedArmour() != -1 && Gethealth() > 20) {
		if (successfull <= 20) {
			//if the random chance is less than 20, attack took place 
			success = true;
			return true;
		}
		else {
			//else attack has failed
			success = false;
			return false;
		}
	}
	//for all other states the chance of attack is 60%
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

	//if the attack has happened, making necessary changes to characters health
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
				//10% extra damage is character is defending + 10% of strength x 5 since its an Orc
				tempHealth = tempHealth - ((Damage * 10 + extraAttack));
				//save the characters new health value
				character.Sethealth(character.Gethealth() - tempHealth);

				if (armour.GetitemName().size() > 0) {
					armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % (100*90)));
				}
			}
			else if (character.GetState() != Dead || Sleeping || Defending && character.Gethealth() > 20 && character.GetequippedArmour() > -1) {
				// +20% damage for all other types of attacks, idle/walking/running, so using an else statement
				tempHealth = tempHealth - ((Damage * 20 + extraAttack));
				character.Sethealth(character.Gethealth() - tempHealth);

				if (armour.GetitemName().size() > 0)
				{
					armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % (100 * 90)));
				}
			}
		}
		//if the characters armour health reaches 0, drop the armour
		if (character.GetArmour(character.GetequippedArmour()).GetarmourHealth() <= 0) {
			DropItem(character.GetArmour(character.GetequippedArmour()));
		}
	}

	//else if the attack didnt take place, the characters weapon still has to be damaged
	if (success == false) {
		//if the character has a weapon
		if (character.GetequippedWeapon() > -1) {
			int weaponHealth = weapon.GetweaponHealth();
			int randDamage = rand() % 11 + 10;
			//take the random damage away from the wepaons health
			weapon.SetweaponHealth(weaponHealth - randDamage);
			//if the weapons health has reached 0, drop the wepaon
			if (weapon.GetweaponHealth() <= 0) {
				DropItem(weapon);
			}
		}
	}
	return success;
}
	

void Orc::Sleep() {
	//set the characters state to sleeping 
	SetState(CharacterState::Sleeping);
	int tempHealth = Gethealth() / 100;
	//add 15% to characters health 
	tempHealth = tempHealth * 115;
	Sethealth(tempHealth);
	//loop to make sure the characters health does not exceed 100.
	if (Gethealth() > 100)
	{
		Sethealth(100);
	}
}


void Orc::Scream(GameCharacter & character)
{
	int random = rand() % 100;
	int percentage = 20 + (5 * Getferociousness());
	int total = random + percentage;

	//79 is 55% to fail
	if (total >= 79)
	{
		//set the characters state to running
		character.SetState(CharacterState::Running);
	}
	else
	{
		std::cout << "Scream has failed" << std::endl;
	}
}

//default destructor
Orc::~Orc()
{
}
