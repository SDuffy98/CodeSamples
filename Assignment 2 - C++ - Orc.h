/*
* Orc.h
*
* Version information: v1.0
* Author: Sean Duffy B00719262
* Date: 28/11/17
*
* Copyright notice
*/

#pragma once
#include "GameCharacter.h"

class Orc :
	public GameCharacter
{

private:
	int ferociousness_;
	int strength_;

public:
	//default constructor
	Orc();

	//custom constructor
	Orc(std::string characterName, float health, float weightLimit, int food, CharacterState state, int ferociousness, int strength);

	virtual bool Attack(GameCharacter &character)override;
	void Scream(GameCharacter &character);
	virtual void Sleep() override;

	//setters and getters
	void Setferociousness(int ferociousness);
	int Getferociousness() const;

	void Setstrength(int strength);
	int Getstrength() const;

	//default destructor
	~Orc();
};

