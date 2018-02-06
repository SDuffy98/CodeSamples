/*
* Cleric.h
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 28/11/17
*
* Copyright notice
*/

#pragma once
#include "GameCharacter.h"

class Cleric :
	public GameCharacter
{
private:
	int pietyLevel_;

public:
	//default constructor
	Cleric();

	//custoum constructor
	Cleric(std::string characterName, float health, float weightLimit, int food, CharacterState state, int pietyLevel);

	virtual bool Attack(GameCharacter &character) override;
	void PrayFor(GameCharacter &character);
	virtual void Sleep() override;

	//setters and getters
	void SetpietyLevel(int pietyLevel);
	int GetpietyLevel() const;

	//default destructor
	~Cleric();
};

