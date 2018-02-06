/*
* COM326 Assignment 1
*Aircraft.h
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 21/10/2017
*
*/

#pragma once

#include <string>
#include<iostream>

class Aircraft
{
private:
	//declaring the private values
    std::string flightNumber_; //use '_' to show its private 
	std::string airline_;
	std::string aircraftType_;
	int groundSpeed_;
	int altitude_;
	std::string gridReference_;
	int heading_;

public:
	//default constructor ??
	Aircraft();

	//custom constructor 
	Aircraft(std::string flightNumber, std::string  airline, std::string aircraftType, int groundSpeed, int altitude, std::string gridReference, int heading);

	// declaring the setters and getters
	void SetflightNumber(std::string flightNumber);
	std::string GetFlightNumber() const;

	void SetAirline(std::string airline);
	std::string GetAirline() const;

	void SetAircraftType(std::string aircraftType);
	std::string GetAircraftType() const;

	void SetGroundSpeed(int groundSpeed);
	int GetGroundSpeed() const;

	void SetAltitude(int altitude);
	int GetAltitude() const;

	void SetGridReference(std::string gridReference);
	std::string GetGridReference() const;

	void SetHeading(int heading);
	int GetHeading() const;
};

