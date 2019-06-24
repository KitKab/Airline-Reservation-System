#pragma once
# include "pch.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include "Passenger.h"


namespace FlightApp
{
	class Passenger;
	class Flight
	{
	public:
		Flight() = default;
		Flight(const std::string& departureCity,
			const std::string& arrivalCity,
			int flightNumber,
			int seatsAmount);

		const std::string& getArrivalCity() const;
		void setArrivalCity(const std::string& arrivalCity);

		const std::string& getDepartureCity() const;
		void setDepartureCity(const std::string& departureCity);

		int getFlightNumber() const;
		void setFlightNumber(int flightNumber);

		std::vector<int> getAvailableSeats() const;
		void setAvailableSeats(std::vector<int> availableSeats);
		
		void display() const;
		void reserveSeat();
		void bookTicket(Passenger& passenger);
		std::vector<Passenger>& getPassengers();

	private:
		std::string mDepartureCity;
		std::string mArrivalCity;
		std::vector<Passenger> mPassenger;
		std::vector<int> mAvailableSeats;
		int mFlightNumber = -1;

	};
}