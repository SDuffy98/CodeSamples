/*
* Brawler.cpp
*
* v1.0
* Author: Sean Duffy
* Date: 25/11/17
*
* Copyright notice
*/

#include "Brawler.h"
#include "GameCharacter.h"


//default constructor
Brawler::Brawler() {}

//std::string characterName_ = "Brawler";

Brawler::Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength)
	: punchDamage_(punchDamage), strength_(strength)
{
	this->SetCharacterName(characterName);
	this->Sethealth(health);
	this->SetweightLimit(weightLimit);
	this->Setfood(food);
}

bool Brawler::Attack(GameCharacter & character)
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
	int armourDamage = extraAttack + 10;

	if (character.GetState() == Dead || character.Gethealth() <= 20){
		//attack failed if character is dead or health is below 20
		success = false;
		return false;
	} 

	//if the Gamecharacter does not have a weapon, use brawl function
	if (character.GetState() != Dead && character.Gethealth() >= 20 && EquipWeapon(GetequippedWeapon()) == -1)
	{
		Brawler::brawl(character);
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
			//attack failed
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

	if (success = true){
	    //if the character is sleeping, health is automatically set to 0 when being attacked
		if (character.GetState() == Sleeping) {

			//character is dead 
			character.Sethealth(0);

			//if the character is wearing armour
			if (armour.GetitemName().size() > 0) {
			//cause damage to armour due to the attack
			armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % armourDamage));
				}
			}

		if (Gethealth() > 20) {
			if (character.GetState() == Defending && successfull<=20)
				{
				//10% extra damage is character is defending + 10% of strength x 5 since its a brawler
				tempHealth = tempHealth - ((Damage * 10 + extraAttack));
				//save the characters new health value
				character.Sethealth(character.Gethealth() - tempHealth);

				if (armour.GetitemName().size() > 0){
					armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % armourDamage));
					}
				} else if (character.GetState() != Dead || Sleeping || Defending && character.Gethealth() > 20 && character.GetequippedArmour() > -1) {
					// +20% damage for all other types of attacks, idle/walking/running, so using an else statement
					tempHealth = tempHealth - ((Damage * 20 + extraAttack));
					character.Sethealth(character.Gethealth() - tempHealth);

					if (armour.GetitemName().size() > 0)
					{
						armour.SetarmourHealth(character.GetequippedArmour() - (tempArmourHealth % armourDamage));
					}
				}
			}
		//if armour health reaches 0, drop armour
		if (character.GetArmour(character.GetequippedArmour()).GetarmourHealth() <= 0) {
			DropItem(character.GetArmour(character.GetequippedArmour()));
			}
		}
		
		if (success == false) {
			if (character.GetequippedWeapon() > -1) {
				int weaponHealth = weapon.GetweaponHealth();
				int randDamage = rand() % 11 + 10;
				weapon.SetweaponHealth(weaponHealth - randDamage);
				//if weapon health is 0, drop weapon
				if (weapon.GetweaponHealth() <= 0) {
					DropItem(weapon);
			}
		}
		}
	return success;
}
	

bool Brawler::brawl(GameCharacter & character)
{
	int successfull = rand() % 100;
	int damage = character.Gethealth() / 100;
	bool success = false;
	
	//character must not be wearing armour for the brawl function to work
	if (character.GetequippedArmour() == -1) {
			if (successfull >= 80) {
				success = false;
			}
			else {
				success = false;
			}
		} 

		else {
			if (successfull <= 60) {
				success = false;
			}

			else {
				success = false;
			}
		}
		

	if (success = true)
	{
		character.GetState();
		// -50% health
		if (character.GetState() == Sleeping) {

			character.Sethealth(0);
			character.Sethealth(damage * 50);
			//character.GetArmour(character.GetequippedArmour()).SetarmourHealth(character.GetequippedArmour() * 0.9);
			if (character.GetequippedArmour() != -1) {


				int armourHealth = character.GetArmour(GetequippedArmour()).GetarmourHealth();
				character.DamageArmour(armourHealth - (armourHealth / 100 * 10));

			}
			CharacterState{ Idle };
			return true;
		}
		// - 5% health
		else if (character.GetState() == Defending) {

			character.Sethealth(damage * 95);
			//character.GetArmour(character.GetequippedArmour()).SetarmourHealth(character.GetequippedArmour() * 0.9);
			if (character.GetequippedArmour() != -1) {


				int armourHealth = character.GetArmour(GetequippedArmour()).GetarmourHealth();
				character.DamageArmour(armourHealth - (armourHealth / 100 * 10));

			}
			CharacterState{ Idle };
			return true;

		}
	}

	else
		//-10% health
	{
		character.Sethealth(damage * 90);
		character.GetArmour(character.GetequippedArmour()).SetarmourHealth(character.GetequippedArmour() * 0.9);
		CharacterState{ Idle };
		if (character.GetequippedArmour() != -1) {


			int armourHealth = character.GetArmour(GetequippedArmour()).GetarmourHealth();
			character.DamageArmour(armourHealth - (armourHealth / 100 * 10));

		}
		return true;
	}

}

void Brawler::Sleep()
{
	//set the character state to sleeping.
	SetState(CharacterState::Sleeping);
	int tempHealth = Gethealth() / 100;
	tempHealth = tempHealth * 120;
	Sethealth(tempHealth);
	//loop to make sure health does not exceed 100.
	if (Gethealth() > 100)
	{
		Sethealth(100);
	}


}

//setters and getters 
void Brawler::SetpunchDamage(int punchDamage)
{
	punchDamage_ = punchDamage;
}

int Brawler::GetpunchDamage() const
{
	return punchDamage_;
}

void Brawler::Setstrength(int strength)
{
	strength_ = strength;
}

int Brawler::Getstrength() const
{
	return strength_;
}

//default deconstructor
Brawler::~Brawler() {}
