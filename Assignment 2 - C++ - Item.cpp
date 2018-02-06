/*
* Weaponry.cpp
*
* v1.0
* Author: Sean Duffy
* Date: 25/11/17
*
* Copyright notice
*/

#include "Item.h"

//default constructor
Item::Item()
{
}

//custom constructor
Item::Item(std::string itemName, int itemValue, float weight)
	: itemName_(itemName), itemValue_(itemValue), weight_(weight)
{
}

//setters and getters
void Item::SetitemName(std::string itemName)
{
	itemName_ = itemName;
}
std::string Item::GetitemName() const
{
	return itemName_;
}

void Item::SetitemValue(int itemValue)
{
}
int Item::GetitemValue() const
{
	return itemValue_;
}

void Item::Setweight(float weight)
{
	weight_ = weight;
}
float Item::Getweight() const
{
	return weight_;
}

//default destructor
Item::~Item()
{
}


