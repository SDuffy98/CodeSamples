/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: Sean Duffy (B00719262)
* Date: 24/11/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/

#include "GameCharacter.h"
#include "Brawler.h"
#include "Orc.h"

//default constructor
GameCharacter::GameCharacter()
{
}
//custom constructor
GameCharacter::GameCharacter(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food, CharacterState state)
	: health_(health), weightLimit_(weightLimit), equippedWeapon_(equippedWeapon), equippedArmour_(equippedArmour), food_(food)
{
}

//setters and getters 
void GameCharacter::SetCharacterName(std::string characterName)
{
	characterName_ = characterName;
}
std::string GameCharacter::GetCharacterName() const
{
	return characterName_;
}

void GameCharacter::Sethealth(float health)
{
	health_ = health;
}
float GameCharacter::Gethealth() const
{
	return health_;
}

void GameCharacter::SetweightLimit(float weightLimit)
{
	weightLimit_ = weightLimit;
}
float GameCharacter::GetweightLimit() const
{
	return weightLimit_;
}

void GameCharacter::SetequippedWeapon(int equippedWeapon)
{
	equippedWeapon_ = equippedWeapon;
}
int GameCharacter::GetequippedWeapon() const
{
	return equippedWeapon_;
}

void GameCharacter::SetequippedArmour(int equippedArmour)
{
	equippedArmour_ = equippedArmour;
}
int GameCharacter::GetequippedArmour() const
{
	return equippedArmour_;
}

void GameCharacter::Setfood(int food)
{
	food_ = food;
}
int GameCharacter::Getfood() const
{
	return food_;
}

void GameCharacter::SetState(CharacterState state)
{
	state_ = state;
}
CharacterState GameCharacter::GetState()
{
	return state_;
}


/*bool GameCharacter::Attack(GameCharacter & character)
{
	return true;
}*/

void GameCharacter::Defend(int armour)
{
	SetState(Defending);

	if (armours_.size() == 0 || armour < armours_.size() || armour > armours_.size()) {
		SetequippedArmour(-1);
	}
	else {
		SetequippedArmour(armour);
	}


}

void GameCharacter::Walk()
{
	CharacterState{ Walking };
}

void GameCharacter::Run()
{
	CharacterState{ Running };
}

Weapon GameCharacter::GetWeapon(int index)
{
	return weapons_.at(index);
}

Armour GameCharacter::GetArmour(int index)
{
	if (armours_.size() <= 0){
		Armour* ar = new Armour();
		return *ar;
}
	return armours_.at(index);
}

bool GameCharacter::PickUpWeapon(Weapon & weapon)
{
	float total{ 0.0f };

	//Add weight of items in the weapons vector to total
	for (int i = 0; i < weapons_.size(); i++)
	{
		total += weapons_[i].Getweight();
	}

	//Add weight of items in the armours vector to total
	for (int i = 0; i < armours_.size(); i++)
	{
		total += armours_[i].Getweight();
	}

	//If total & new weapon weight is LESS THAN OR EQUAL TO weightlimit, add and return true.
	//else return false
	if ((total + weapon.Getweight()) <= GetweightLimit())
	{
		weapons_.push_back(weapon);
		return true;
	}
	else
	{
		return false;
	}
}

bool GameCharacter::PickUpArmour(Armour & armour)
{
	float CharacterWeight = 0.0;

	for (int i = 0; i < weapons_.size(); i++) {
		CharacterWeight += weapons_[i].Getweight();
	}

	for (int i = 0; i < armours_.size(); i++) {
		CharacterWeight += armours_[i].Getweight();
	}
	float theoryWeight = (CharacterWeight + armour.Getweight());
	if (theoryWeight <= GetweightLimit()) {
		armours_.push_back(armour);
		return true;
	}
	return false;
}

void GameCharacter::DropItem(Armour &item) //DB 16/12/2017
{
	//Search for match within the armours_ vector
	//if found, erase from list
	for (int i = 0; i < armours_.size(); i++)
	{
		if (armours_.at(i).GetitemName() == item.GetitemName())
		{
			armours_.erase(armours_.begin() + i);
		}
	}
}

void GameCharacter::DropItem(Weapon & item) //DB 16/12/2017
{
	//i = -1 because weapon vector starts at -1 not 0.
	for (int i = -1; i < weapons_.size(); i++)
	{
		if (weapons_.at(i).GetitemName() == item.GetitemName())
		{
			weapons_.erase(weapons_.begin() + i);
		}
	}
}

bool GameCharacter::EquipWeapon(int weapon)
{
	//If match then SetequippedWeapon & return true
	if (weapon != -1 && weapon <= weapons_.size())
	{
		SetequippedWeapon(weapon);
		return true;
	}
	else
	{
		SetequippedWeapon(-1);
		return false;
	}
}

bool GameCharacter::EquipArmour(int armour)
{
	//If match then SetequippedWeapon & return true
	if (armour != -1 && armour <= armours_.size())
	{
		SetequippedWeapon(armour);
		return true;
	}
	else
	{
		SetequippedWeapon(-1);
		return false;
	}
	
}

void GameCharacter::DamageArmour(int health)
{
	int tempHealth = health;
	int randomDamage = rand() % 11 + 10;
	float newHealth = health - (randomDamage*tempHealth);

	GetArmour(GetequippedArmour()).SetarmourHealth(health);
}

void GameCharacter::DamageWeapon(int health)
{
	int tempHealth = health;
	int randomDamage = rand() % 11 + 10;
	float newHealth = health - (randomDamage*tempHealth);

	GetWeapon(GetequippedWeapon()).SetweaponHealth(health);
}

void GameCharacter::AddFood(int amount) //DB 16/12/2017
{
	//int current = Getfood();
	//Setfood(current += amount);
	Setfood(Getfood() + amount);
}

void GameCharacter::Eat() //DB 16/12/2017
{
	float current = Getfood();
	float twentyPerCent = current / 5;
	float healthGained = twentyPerCent * 0.25;

	health_ += healthGained;
	Setfood(current -= twentyPerCent);

	Sethealth(health_);

	if (Gethealth() > 100)
	{
		Sethealth(100);
	}
}

void GameCharacter::Sleep()
{

}

//default destructor
GameCharacter::~GameCharacter() {
}
