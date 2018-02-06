/*
* Armour.h
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 28/11/17
*
* Copyright notice
*/

#pragma once
#include "Item.h"

enum ArmourType { Cardboard, Leather, Wood, Iron, Steel};

class Armour :
	public Item
{
private:
	int defence_;
	int armourHealth_;
	ArmourType armourType_;

public:
	//default constructor
	Armour();

	//custom construtor
	Armour(std::string armourName, int value, float weight, int defence, int armourHealth, ArmourType armourType);

	//declaring setters and getters
	void Setdefence(int defence);
	int Getdefence()const;

	void SetarmourHealth(int armourHealth);
	int GetarmourHealth()const;

	//default destructor
	~Armour();
};
