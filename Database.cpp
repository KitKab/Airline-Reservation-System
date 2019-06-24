
#include"pch.h"
#include <iostream>
#include <stdexcept>
#include<limits>
#include "Database.h"
#include"Passenger.h"
#include"Flight.h"
using namespace std;


namespace FlightApp
{
	Flight& Database::addFlight(const std::string& departureCity,
		const std::string& arrivalCity, int flightNumber, int seatsAvailable)
	{
		Flight theFlight(departureCity, arrivalCity, flightNumber, seatsAvailable);
		mFlight.push_back(theFlight);
		return mFlight[mFlight.size() - 1];
	}
	
	Flight& Database::getFlight(int flightNumber)
	{
		
		for (auto& flight : mFlight)
			{
				if (flight.getFlightNumber() == flightNumber)
				{
					//flight.setArrivalCity("abcde");
					return flight;
				}

			}
	
	}

	Flight & Database::selectFlight(Database & db)
	{
		// TODO: insert return statement here
		int flightnumber;
		
		system("CLS");
		std::cout << endl;
		std::cout << endl;
		std::cout << "Please input Flight Number: ";
		std::cin >> flightnumber;
		while (!cin)
		{
			cout << " Invalid Flight number " << endl;
			cin.clear();
			cin.ignore();
			cout << endl; cout << endl;
			cout << "Please input valid flight number: ";
			cin >> flightnumber;

		}
		return db.getFlight(flightnumber);
	}
	
	

	vector<Flight>& Database::getAllFlights()
	{
		return mFlight;
	}

	void Database::displayAllFlights(Database db) 
	{	
		vector<Flight>& flightList = db.getAllFlights();
		cout << endl;
		cout << endl;
		cout << "-------------------------------------------------------- " << endl;
		cout << "****** Displaying Flight List ******" << endl;
		cout << "-------------------------------------------------------- " << endl;
		cout << "Flight No." << " " << "Departure City" <<" " << "Arrival City" <<  " " << "Available Seats" << endl;
		cout << "-------------------------------------------------------- " << endl;
		for (auto& flight : flightList)
		{
			flight.display();
		}
		cout << endl;
	}

	
	void Database::displayPassengerTicket(Database& db)
	{
		Flight& flight = selectFlight(db);
		int passengerId = 0;
		cout << endl;
		cout << endl;
		cout << "Please input Passenger ID: ";
		cin >> passengerId;
		while(!cin)
			
		{
			cout << " Invalid passenger ID " << endl;
			cin.clear();
			cin.ignore();
			cout << "Please input Passenger ID: ";
			cin >> passengerId;

		}
		bool passengerExists = false;
		vector<Passenger>& passenger = flight.getPassengers();
		if (passenger.size() == 0)
		{
			cout << "There are no passengers on this flight !" << endl;
		}
		for (auto& p : passenger)
		{
			//cout << "Passenger Id " << p.getPassengerId() << endl;
			if ( p.getPassengerId() == passengerId )
			{
				passengerExists = true;
				cout << endl;
				cout << endl;
				cout << "\n";
				cout << "----------------------------------------------------------" << endl;
				cout << "****** Displaying Passenger Ticket ******" << endl;
				cout << "----------------------------------------------------------" << endl;
				cout << "Passenger Id: " << p.getPassengerId() << endl;
				cout << "Passenger Name: " << p.getFirstName() << " " << p.getLastName() << endl;
				cout << "Flight No." << flight.getFlightNumber() << endl;
				cout << "Flight Departure City: " << flight.getDepartureCity() << endl;
				cout << "Flight Arrival City: " << flight.getArrivalCity() << " " << endl;
				cout<< 	"Seat Number: " << p.getSeatNumber() << endl;
			}
			
		}

	}

void Database::displayPassengerInfo(Database& db)
	{
		Flight& flight = selectFlight(db);
		vector<Passenger>& pList = flight.getPassengers();
		cout << "---------------------------------------------------------------------" << endl;
		cout << "****** Displaying Passenger Information on the Flight******" << endl;
		cout << "--------------------------------------------------------------------" << endl;
		for (Passenger& passenger : pList)
		{
			passenger.displayPassenger();
		}
	}
	void Database::displayFlightInformation(Database& db)
	{
		Flight flight = selectFlight(db);
		cout << endl;
		cout << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "****** Displaying Flight Information ******" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "Flight No." << " " << "Departure City" << "   " << "Arrival City" << "  " << "Available Seats" << endl;
		flight.display();
		vector<int> availableSeats = flight.getAvailableSeats();
		cout << endl;
		cout << "Available Seats: " << availableSeats.size() << endl;
		vector<Passenger> & seatsBooked = flight.getPassengers();
		cout << endl;
		cout << "Reserved Seats: " << seatsBooked.size() << endl;
	}
	
}
