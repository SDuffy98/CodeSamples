/*
* Brawler.h
*
* v1.0
* Author: Sean Duffy (B00719262) Craig Farrer(B00)
* Date: 25/11/17
*
* Copyright notice
*/

#pragma once
#include "GameCharacter.h"
class Brawler :
	public GameCharacter
{
private:
	int punchDamage_;
	int strength_;

public:
	//default constructor
	Brawler();

	//custom constructor
	Brawler(std::string characterName, float health, float weightLimit, int food, CharacterState state, int punchDamage, int strength);

	virtual bool Attack(GameCharacter &character) override;

	bool brawl(GameCharacter &character);

	virtual void Sleep() override;

	//setters and getters
	void SetpunchDamage(int punchDamage);
	int GetpunchDamage() const;

	void Setstrength(int strength);
	int Getstrength() const;

	//default destructor
	~Brawler();

};

