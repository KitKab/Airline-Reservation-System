
#pragma once 
#include"pch.h"
#include<iostream>
#include<vector>
#include<string>
#include"Flight.h"

namespace FlightApp {
	class Passenger {
	public:
		Passenger() = default;
		Passenger(const std::string& firstName, const std::string& lastName, const std::string& passengerContact, int passengerId);
		
		
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& firstName);
		const std::string& getLastName() const;

		void setPassengerContact(const std::string& passengerContact);
		const std::string& getPassengerContact()const;

		void setPassengerId(int passengerId);
		int getPassengerId()const;

		void setSeatNumber(int seatNumber);
		int getSeatNumber()const;

		Passenger& createPassenger();
		void displayPassenger()const;
	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mPassengerContact;
		int mPassengerId;
		int mSeatNumber = -1;
	};
}
