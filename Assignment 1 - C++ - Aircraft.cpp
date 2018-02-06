/*
* COM326 Assignment 1
*Aircraft.cpp
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 21/10/2017
*
*/

#include <string>
#include<iostream>
#include "Aircraft.h"

//Default constructor (not used)
Aircraft::Aircraft()
{
}

//custom constructor, initialising the private variables to public versions 
Aircraft::Aircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundSpeed, int altitude, std::string gridReference, int heading)
	: flightNumber_(flightNumber), airline_(airline), aircraftType_(aircraftType), groundSpeed_(groundSpeed), altitude_(altitude), gridReference_(gridReference), heading_(heading)
{
}

//setters and getters
void Aircraft::SetflightNumber(std::string flightNumber)
{
	flightNumber_ = flightNumber;
}
std::string Aircraft::GetFlightNumber() const
{
	return flightNumber_;
}


void Aircraft::SetAirline(std::string airline)
{
	airline_ = airline;
}
std::string Aircraft::GetAirline() const
{
	return airline_;
}


void Aircraft::SetAircraftType(std::string aircraftType)
{
	aircraftType_ = aircraftType;
}
std::string Aircraft::GetAircraftType() const
{
	return aircraftType_;
}


void Aircraft::SetGroundSpeed(int groundSpeed)
{
	groundSpeed_ = groundSpeed;
}
int Aircraft::GetGroundSpeed() const
{
	return groundSpeed_;
}

void Aircraft::SetAltitude(int altitude)
{
	altitude_ = altitude;
}
int Aircraft::GetAltitude() const
{
	return altitude_;
}


void Aircraft::SetGridReference(std::string gridReference)
{
	gridReference_ = gridReference;
}
std::string Aircraft::GetGridReference() const
{
	return gridReference_;
}

void Aircraft::SetHeading(int heading)
{
	heading_ = heading;
}
int Aircraft::GetHeading() const
{
	return heading_;
}
