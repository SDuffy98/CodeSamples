/*
* GameCharacter.h
*
* Version information v0.1
* Authors: <Insert group member names and IDs> of student(s) who write each class
* Date: 24/11/2017
* Description: header file for GameCharacter class
* Copyright notice
*/

#pragma once
#include <string>
#include<vector>
#include "Weapon.h"
#include "Armour.h"

enum CharacterState { Idle, Running, Sleeping, Walking, Defending, Dead };

class GameCharacter
{
	
private:
	//declaring private variables
	std::string characterName_;
	float health_;
	float weightLimit_;
	int equippedWeapon_;
	int equippedArmour_;
	std::vector<Weapon>weapons_;
	std::vector<Armour>armours_;
	int food_;
	CharacterState state_;

public:
	//default constructor
	GameCharacter();

	//custom constructor
	GameCharacter(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food, CharacterState state);

	//declaring setters and getters 

	std::string GetCharacterName() const;
	void SetCharacterName(std::string name);

	void Sethealth(float health);
	float Gethealth() const;

	void SetweightLimit(float weightLimit);
	float GetweightLimit() const;

	void SetequippedWeapon(int weapon);
	int GetequippedWeapon() const;

	void SetequippedArmour(int armour);
	int GetequippedArmour() const;

	void Setfood(int food);
	int Getfood() const;


	//=0 to make it a purely virtual function aka abstract
	virtual bool Attack(GameCharacter &character) = 0;
	void Defend(int armour);
	void Walk();
	void Run();
	virtual void Eat();
	virtual void Sleep();
	Weapon GetWeapon(int index);
	Armour GetArmour(int index);
	virtual bool PickUpWeapon(Weapon &weapon);
	virtual bool PickUpArmour(Armour &armour);
	void DropItem(Armour &item);
	void DropItem(Weapon &item);
	bool EquipWeapon(int weapon);
	bool EquipArmour(int armour);
	void DamageArmour(int armour);
	void DamageWeapon(int weapon);
	void AddFood(int amount);
	CharacterState GetState();
	void SetState(CharacterState state);

	~GameCharacter();
};

