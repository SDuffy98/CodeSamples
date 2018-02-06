/*
* Weapon.h
*
* v1.0
* Author: Sean Duffy
* Date: 25/11/17
*
* Copyright notice
*/

#pragma once
#include "Item.h"

class Weapon :
	public Item
{
private:
	int weaponHitStrength_;
	int weaponHealth_;

public:
	//default constructor
	Weapon();

	//custom constructor
	Weapon(int weaponStrength, int weaponHealth);

	Weapon(std::string weaponName, int Value, float weight, int hitStrength, int health);

	//setters and getters
	void SetweaponHitStrength(int weaponHitStrength);
	int GetweaponHitStrength() const;

	void SetweaponHealth(int weaponHealth);
	int GetweaponHealth() const;

	//default destructor
	~Weapon();
};

