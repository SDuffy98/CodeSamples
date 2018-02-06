/*
* COM326 Assignment 1
*Main.cpp
*
* Version information: v1.0
* Author: Sean Duffy
* Date: 21/10/2017
*
*/

#include <iostream>
#include <string>
#include <regex>
#include <iostream>
#include <cstdlib> //to allow use of exit(0)
#include "FlightSystem.h"

using namespace std;

void menu(FlightSystem system1); //declaring the menu

void menu(FlightSystem system1)
{
	//initialising values
	std::string flightNumber;
	std::string airline;
	std::string aircraftType;
	int groundSpeed;
	int altitude;
	int tempAltitude;
	std::string gridReference;
	int heading;

	std::string option; //used to store users input

	//initialising functions
	//caps to differenciate from other function names
	void ADD_AIRCRAFT(FlightSystem system1);
	void LIST_ALL_AIRCRAFT(FlightSystem system1);
	void LIST_ALL_CRUISING_AIRCRAFT(FlightSystem system1);
	void REMOVE_AIRCRAFT(FlightSystem system1);
	void CHANGE_HEADING(FlightSystem system1);
	void GET_HEADING(FlightSystem system1);
	void CHANGE_ALTITUDE(FlightSystem system1);
	void GET_ALTITUDE(FlightSystem system1);
	void NUMBER_IN_SECTOR(FlightSystem system1);
	void CLOSE_PROGRAM(FlightSystem system1);

	//opening message
	std::cout << "\t\t\t\t\t   Welcome to the flight system operator" << std::endl;
	std::cout << " " << std::endl; //prints a blank space to make the menu more user friendly
	std::cout << "\n\t\t\t\t\t\tPlease select an option" << std::endl;
	std::cout << " " << std::endl; //prints a blank space to make the menu more user friendly

	//menu items
	std::cout << "\nPress [1] to add an aircraft." << std::endl;
	std::cout << "\nPress [2] to view all aircrafts within the system. " << std::endl;
	std::cout << "\nPress [3] to view all cruising aircrafts. " << std::endl;
	std::cout << "\nPress [4] to remove an aircraft from the system. " << std::endl;
	std::cout << "\nPress [5] to change the heading of an aircraft. " << std::endl;
	std::cout << "\nPress [6] to view the heading of an aircraft (Must know flight number)" << std::endl;
	std::cout << "\nPress [7] to change the alititude of an aircraft. (Must know flight number)" << std::endl;
	std::cout << "\nPress [8] to view the altitude of an aircraft. (Must know flight number)" << std::endl;
	std::cout << "\nPress [9] to view the number of aircrafts in sector" << std::endl;
	std::cout << "\nPress [0] to exit " << std::endl;
	std::cout << " " << std::endl;
	//declaring a variable called option to store users option
	std::cin >> option; 

	//User Input Options

	//add aircraft
	if (option == "1")
	{
		system("CLS");
		//calls the add aircraft function
		ADD_AIRCRAFT(system1);
	}

	//view all aircrafts
	if (option == "2")
	{
		//calls list all aircraft function
		LIST_ALL_AIRCRAFT(system1);
	}

	//view all cruising aircrafts
	if (option == "3")
	{
		//calls list all cruising aircraft function
		LIST_ALL_CRUISING_AIRCRAFT(system1);
	}

	//remove aircraft
	if (option == "4")
	{
		//calls remove aircraft function
		REMOVE_AIRCRAFT(system1);
	}

	//change heading
	if (option == "5")
	{
		//calls change heading function
		CHANGE_HEADING(system1);
	}

	//get heading
	if (option == "6")
	{
		//calls get heading function
		GET_HEADING(system1);
	}

	//change altitude
	if (option == "7")
	{
		//calls change altitude function
		CHANGE_ALTITUDE(system1);
	}

	//get altitude
	if (option == "8")
	{
		//calls the get altitude function
		GET_ALTITUDE(system1);
	}

	//view the number of Aircrafts within system
	if (option == "9")
	{
		//calls number of aircraft in sector function
		system1.numAircraftInSector();
	}

	//close the program
	if (option == "0")
	{
		//calls close program function 
		CLOSE_PROGRAM(system1);
	}
}

//Main Methods

//option 1 - add Aircraft
void ADD_AIRCRAFT(FlightSystem system1)
{
	std::string flightNumber;
	 std::cout << "Please enter a Flight Number ";
	 //stores users answer in flightNumber
	 std::cin >> flightNumber;

	 std::string airline;
	 std::cout << "Please enter the airline ";
	 //stores users answer in airline
     std::cin >> airline;

	std::string aircraftType;
	std::cout << "Please enter the aircraft type ";
	//stores users answer in aircraft type
	std::cin >> aircraftType;

	int groundSpeed;
	std::cout << "Please enter the ground speed ";
	//stores users answer in groundspeed
	std::cin >> groundSpeed;

	int altitude;
	std::cout << "Please enter the altitude ";
	//stores users answer in altitude
	std::cin >> altitude;

	std::string gridReference;
	std::cout << "Please enter the grid reference ";
	//stores users answer in grid reference
	std::cin >> gridReference;

	int heading;
	std::cout << "Please enter the heading ";
	//stores users answer in heading
	std::cin >> heading;

	system1.AddAircraft(flightNumber, airline, aircraftType, groundSpeed, altitude, gridReference, heading);
	
	//pause to stop console from closing when user hasnt finished looking
	system("Pause"); 
	//clears the screen so its more user friendly
	system("CLS");
	//recalls the menu so program doesnt close 
	menu(system1);
}

//option 2 - view all aircrafts
void LIST_ALL_AIRCRAFT(FlightSystem system1)
{
    std::vector <Aircraft> AllCraft = system1.ListAllAircraft();
		for (int i = 0; AllCraft.size() > i; i++)
{
    std::cout << "The flight number is " << AllCraft[i].GetFlightNumber() << std::endl;
	std::cout << "The airline is " << AllCraft[i].GetAirline() << std::endl;
	std::cout << "The aircraft type is " << AllCraft[i].GetAircraftType() << std::endl;
	std::cout << "The groundspeed is " << AllCraft[i].GetGroundSpeed() << std::endl;
	std::cout << "The altitude is " << AllCraft[i].GetAltitude() << std::endl;
	std::cout << "The grid reference is " << AllCraft[i].GetGridReference() << std::endl;
	std::cout << "The heading is " << AllCraft[i].GetHeading() << std::endl;
	cout << "" << std::endl;
}

	//stops the console from closing for when the user hasnt finished reading
	system("Pause");
	//clears the console screen so its more user friendly
	system("CLS");
	//recalls the menu to stop program from closing
	menu(system1);
}

//option 3 - view all cruising aircrafts  
void LIST_ALL_CRUISING_AIRCRAFT(FlightSystem system1) 
{
	//loop to check which aircrafts have an altitude above 30,000
	std::vector <Aircraft> CruisingAircraft = system1.ListAllCruisingAircraft();
		for (int i = 0; CruisingAircraft.size() > i; i++)
{
	std::cout << "The flight number is " << CruisingAircraft[i].GetFlightNumber() << std::endl;
	std::cout << "The airline is " << CruisingAircraft[i].GetAirline() << std::endl;
	std::cout << "The aircraft type is " << CruisingAircraft[i].GetAircraftType() << std::endl;
	std::cout << "The groundspeed is " << CruisingAircraft[i].GetGroundSpeed() << std::endl;
	std::cout << "The altitude is " << CruisingAircraft[i].GetAltitude() << std::endl;
	std::cout << "The grid reference is " << CruisingAircraft[i].GetGridReference() << std::endl;
	std::cout << "The heading is " << CruisingAircraft[i].GetHeading() << std::endl;
}
	//stops the console from closing when user hasnt finished reading 
	system("Pause");
	//clears the console window so its more user friendly
	system("CLS");
	//recalls the menu to stop program from closing
	menu(system1);
}

//option 4 - remove an aircraft
void REMOVE_AIRCRAFT(FlightSystem system1)
{
	std::string flightNumber;
	std::cout << "Enter flight number of the flight you want to remove " << std::endl;
	std::cin >> flightNumber;

	system1.RemoveAircraft(flightNumber);

	system("Pause");
	system("CLS");
	menu(system1);
}

//option 5 - change the heading of an aircraft
void CHANGE_HEADING(FlightSystem system1) //Change heading of aircraft
{
	std::string flightNumber;
	int heading;
	std::cout << "Please enter the flight number for the flight heading you want to change " << std::endl;
	std::cin >> flightNumber;
	std::cout << "Please enter the new heading of flight "<< flightNumber << std::endl;
	std::cin >> heading;

	system1.ChangeHeading(flightNumber, heading);

	system("Pause");
	system("CLS");
	menu(system1);
}

//option 6 - view the heading of an aircraft
void GET_HEADING(FlightSystem system1) //Get heading of an aircraft
{
	std::string flightNumber;
	std::cout << "Please enter the flight number for the flight heading you want to view " << std::endl;
	std::cin >> flightNumber;

	std::cout << system1.GetHeading(flightNumber) << std::endl;

	system("Pause");
	system("CLS");
	menu(system1);
}

//option 7 - change the altitude of an aircraft
void CHANGE_ALTITUDE(FlightSystem system1) //Change altitude of an aircraft
{
	std::string flightNumber;
	int altitude;
	std::cout << "Please enter the flight number for the flight altitude you want to change " << std::endl;
	std::cin >> flightNumber;
	std::cout << "Please enter the new altitude of the flight " << std::endl;
	std::cin >> altitude;

	system1.ChangeAltitude(flightNumber, altitude);

	system("Pause");
	system("CLS");
	menu(system1);
}

//option 8 - view the heading of an aircraft
void GET_ALTITUDE(FlightSystem system1) //Get Altitude of an aircraft
{
	std::string flightNumber;
	std::cout << "Please enter the flight number for the flight altitude you want to view " << std::endl;
	std::cin >> flightNumber;
	
	std::cout<<system1.GetAltitude(flightNumber)<<std::endl;

	system("Pause");
	system("CLS");
	menu(system1);
}

//option 9 - view the number of aircrafts within the sector
void NUMBER_IN_SECTOR(FlightSystem system1)
{
	system1.numAircraftInSector();
}

//option 0 - close the program
void CLOSE_PROGRAM(FlightSystem system1)
{
	//std::cout << "Are you sure you want to exit?";
	exit(0);
}

//main method
int main(std::string option)
{
	FlightSystem system1; //declaration of flight system object which holds a vector
	// a do while loop to keep the program open 
	do
	{
		//calls the menu function declared above
		menu(system1);
		//keeps it open while the user does not press 0 (indicating they want to close the program)
	} while (option != "0");
}


