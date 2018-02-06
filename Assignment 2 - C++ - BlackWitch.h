/*
* BlackWitch.h
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 28/11/17
*
* Copyright notice
*/

#pragma once
#include "GameCharacter.h"


class BlackWitch :
	public GameCharacter
{
private:
	int magicProficiency_;
	int darkPower_;

public:
	//default constructor
	BlackWitch();

	//custom constructor
	BlackWitch(std::string characterName, float health, float weightLimit, int food, CharacterState state, int magicProficiency, int darkPower);

	//setters and getters
	void SetmagicProficiency(int magicProficiency);
	int GetmagicProficiency() const;

	void SetdarkPower(int darkPower);
	int GetdarkPower() const;

	virtual bool Attack(GameCharacter &character)override;
	void Bewitch(GameCharacter &character);
	virtual void Sleep() override;

	//default destructor
	~BlackWitch();
};

