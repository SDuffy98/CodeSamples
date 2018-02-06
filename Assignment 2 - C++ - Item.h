/*
* Item.h
*
* v1.0
* Author: Sean Duffy
* Date: 25/11/17
*
* Copyright notice
*/

#pragma once
#include <string>

class Item
{

private:
	std::string itemName_;
	int itemValue_;
	float weight_;

public:
	//default constructor
	Item();

	//custom constructor
	Item(std::string itemName, int itemValue, float weight);

	//setters and getters
	void SetitemName(std::string itemName);
	std::string GetitemName() const;

	void SetitemValue(int itemValue);
	int GetitemValue() const;

	void Setweight(float weight);
	float Getweight() const;

	//default destructor
	~Item();

};

