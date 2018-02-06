/*
* COM326 Assignment 1
*FlightSystem.cpp
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 21/10/2017
*
*/

#include "FlightSystem.h"

//vectors
std::vector<Aircraft> FlightSystem::ListAllAircraft()
{
	return aircraftList_;
}

std::vector<Aircraft> FlightSystem::ListAllCruisingAircraft()
{
	std::vector <Aircraft> cruisingAircraft_;
	for (std::vector<int>::size_type index = 0; index != aircraftList_.size(); index++)
	{
		if (aircraftList_.at(index).GetAltitude() >= 30000)
		{
			cruisingAircraft_.push_back(aircraftList_.at(index));
		}
	}
	return cruisingAircraft_;
}

//functions
void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, int groundspeed, int altitude, std::string gridReference, int heading)
{
	// loop to find if aircraft already exists
	for (std::vector<int>::size_type i= 0; i!= aircraftList_.size(); i++)
	{
		//checks to see if the flightnumber already exists
		if (aircraftList_[i].GetFlightNumber() == flightNumber)
		{
			// prints out to tell the user the flight is already in the system
			std::cout << "Flight " << flightNumber << " already in the system." << std::endl; //prints out to tell user flight is already registered
			return;
		}
	}
			// creating a temp aircraft value called A
			Aircraft A (flightNumber, airline, aircraftType, groundspeed, altitude, gridReference, heading);

			// if flight does not exist it adds it to the list
			aircraftList_.push_back(A); //flight is added to list if it is a new flight
			//collision detection
			(COLLISION_DETECTION(flightNumber, altitude, gridReference));
			//system(CLS) to stop the flight printing out twice
			system("pause");
			system("CLS");
			//prints out to notify the user that the aircraft has been added
			std::cout << "\nAircraft has been added to the system." << std::endl;
}

int FlightSystem::numAircraftInSector()
{
	//prints out to tell the user the number of aircrafts within the sector
	std::cout << "The Number of Aircraft currently within the sector is: " << aircraftList_.size() << std::endl;
	//the size of the aircraft list which will be the number of aircrafts within the system.
	return aircraftList_.size(); //returns the aircraft list
}

void FlightSystem::RemoveAircraft(std::string flightNumber)
{
	// loop to find if aircraft exists
	for (int i = 0; i != aircraftList_.size(); i++)
	{
		if (aircraftList_[i].GetFlightNumber() == flightNumber)
		{
			aircraftList_.erase(aircraftList_.begin() + i);

			//notifies the user the flight has been removed
			std::cout << "Flight: " << flightNumber << " removed from the system." << std::endl;
			return;
		}
		else
		{
			// prints out to tell the user the flight is not in the system
			std::cout << "Flight: " << flightNumber << " is not in the system." << std::endl;
		}
	}
}

void FlightSystem::ChangeHeading(std::string flightNumber, int heading)
{
	int count = 0;
	for (int i = 0; i != aircraftList_.size(); i++)
	{
		// loop to find if aircraft exists
		if (aircraftList_[i].GetFlightNumber() == flightNumber)
		{
			//if it does exist
			aircraftList_.at(i).SetHeading(heading);
			std::cout << "Heading of flight: " << flightNumber << " changed to: " << heading << std::endl;
			return;
		}
		else {
			count++;
		}
	}
		if (aircraftList_.size() == count)
		{
			//if flight doesn't exist:
			std::cout << "Flight: " << flightNumber << " is not in the system." << std::endl;
		}
	}

int FlightSystem::GetHeading(std::string flightNumber)
{
	// loop to find if aircraft exists
	for (int i= 0; i != aircraftList_.size(); i++)
	{
		if (aircraftList_[i].GetFlightNumber() == flightNumber)
		{
			return aircraftList_.at(i).GetHeading();
		}
		else {
			// prints out to tell the user the flight is not in the system
			std::cout << "Flight number " << flightNumber << " is not in the system" << std::endl;
		}
	}
	return 0;
}

void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude)
{
	int count = 0;
	std::string tempGridRef;
	for (int i = 0; i != aircraftList_.size(); i++)
	{
		// loop to find if aircraft exists
		if (aircraftList_[i].GetFlightNumber() == flightNumber)
		{
			tempGridRef = aircraftList_[i].GetGridReference();
			//if it does exist
			aircraftList_.at(i).SetAltitude(altitude);
			std::cout << "Altitude of flight: " << flightNumber << " changed to: " << altitude << std::endl;
			
			break;
		}
		else {
			count++;
		}
	}
	if (aircraftList_.size() == count)
	{
		//if flight doesn't exist:
		std::cout << "Flight: " << flightNumber << " is not in the system." << std::endl;
	}
	COLLISION_DETECTION(flightNumber, altitude, tempGridRef);
}

int FlightSystem::GetAltitude(std::string flightNumber)
{
	// loop to find if aircraft already exists
	for (int i = 0; i != aircraftList_.size(); i++)
	{
		//if the aircraft exists
		if (aircraftList_[i].GetFlightNumber() == flightNumber)
		{
			//returns the altitude of the specified flight 
			return aircraftList_.at(i).GetAltitude();
		}
		else {
			//if flight does not exist it will tell the user
			std::cout << "Flight number " << flightNumber << " is not in the system" << std::endl;
		}
	}
	return 0;
}

//collision detection
void FlightSystem::COLLISION_DETECTION(std::string flightNumber, int altitude, std::string gridReference)
{
	//assigning a temp value to the value of altitude thats been passed in
	unsigned int tempAltitude = altitude; 
	//declaring a variable called distance, so that i can compare the 2 temp altitudes
	unsigned int distance = 3000;
	//loop tp run through the aircraft list 
	for (std::vector<int> ::size_type i = 0; i != aircraftList_.size(); i++) 
	{
		//assigning a second variable to store the value of altitude at position i in the loop
		unsigned int tempAltitude2 = aircraftList_.at(i).GetAltitude();
		//if flight number does not equal the flight number just found at i
			if (flightNumber != aircraftList_.at(i).GetFlightNumber()) 
			{
				if (aircraftList_.at(i).GetGridReference() == gridReference && tempAltitude - tempAltitude2 <= distance || tempAltitude2 - tempAltitude <= distance)
				{
				//prints a message telling the user a collision is possible
					std::cout << "Warning - Aricraft collision possible between " << flightNumber << " and " << aircraftList_.at(i).GetFlightNumber() << std::endl;
			   }
		   }
	 }
}
