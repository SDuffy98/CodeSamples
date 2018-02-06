/*
* Weapon.cpp
*
* v1.0
* Author: Sean Duffy
* Date: 25/11/17
*
* Copyright notice
*/

#include "Weapon.h"
#include <string>

//default constructor
Weapon::Weapon()
{
}

//custom constructor
Weapon::Weapon(int weaponHitStrength, int weaponHealth)
	: weaponHitStrength_(weaponHitStrength), weaponHealth_(weaponHealth)
{
}

//custom constructor
Weapon::Weapon(std::string weaponName, int Value, float weight, int hitStrength, int health)
	: Item(weaponName, Value, weight), weaponHitStrength_(hitStrength), weaponHealth_(health)
{	

}


//setters and getters
void Weapon::SetweaponHitStrength(int weaponHitStrength)
{
	weaponHitStrength_ = weaponHitStrength;
}
int Weapon::GetweaponHitStrength() const
{
	return weaponHitStrength_;
}

void Weapon::SetweaponHealth(int weaponHealth)
{
	weaponHealth_ = weaponHealth;
}
int Weapon::GetweaponHealth() const
{
	return weaponHealth_;
}

//desfult destructor
Weapon::~Weapon()
{
}
