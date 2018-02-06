/*
* Armour.cpp
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 28/11/17
*
* Copyright notice
*/

#include "Armour.h"
#include <string>

//default constructor
Armour::Armour() {}


//custom constructor
Armour::Armour(std::string armourName, int value, float weight, int defence, int armourHealth,  ArmourType armourType)
	: Item(armourName, value, weight), defence_(defence), armourHealth_(armourHealth), armourType_(armourType)
{
}

//setters and getters
void Armour::Setdefence(int defence)
{
	defence_ = defence;
}
int Armour::Getdefence() const
{
	return defence_;
}

void Armour::SetarmourHealth(int armourHealth)
{
	armourHealth_ = armourHealth;
}
int Armour::GetarmourHealth() const
{
	return armourHealth_;
}

//default destructor
Armour::~Armour() {}
