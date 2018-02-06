/*
* COM326 Assignment 1
*FlightSystem.h
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 21/10/2017
*
*/

#pragma once
#include <string>
#include <vector>
#include<iostream>
#include "Aircraft.h"


class FlightSystem
{

private:
	std::vector <Aircraft> aircraftList_;

public:
	void AddAircraft(std::string flightNumber, std::string  airline, std::string aircraftType, int groundSpeed, int altitude, std::string gridReference, int heading);

	//vectors
	std::vector <Aircraft> ListAllAircraft();
	std::vector<Aircraft> ListAllCruisingAircraft();

	//declaring variables
	int numAircraftInSector();
	void RemoveAircraft(std::string flightNumber);
	void ChangeHeading(std::string flightNumber, int heading);
	int GetHeading(std::string flightNumber);
	void ChangeAltitude(std::string flightNumber, int altitude);
	int GetAltitude(std::string flightNumber);

	//collision detection
	void COLLISION_DETECTION(std::string flightNumber, int altitude, std::string gridReference);
};
