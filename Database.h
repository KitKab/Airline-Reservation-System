#pragma once
#include <vector>
#include<string>
#include "Flight.h"
#include"Passenger.h"

namespace FlightApp
{

	class Database
	{
	public:
		Flight& addFlight(const std::string& departureCity, const std::string& arrivalCity, int flightNumber, int seatsAvailable);
		
		Flight& getFlight(int flightNumber);
		std::vector<Flight>& getAllFlights();
		Flight& selectFlight(Database& db);
		//void displayAll() const;
		void displayFlightInformation(Database& db);
		void displayAllFlights(Database db) ;
		void displayPassengerInfo(Database& db);
		//void displayPax() const;
		void displayPassengerTicket(Database& db);
	private:
		std::vector<Flight> mFlight;
		std::vector<Passenger> mPassenger;
	};
}
