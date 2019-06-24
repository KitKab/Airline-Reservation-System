
#include"pch.h"
#include<iostream>
#include<string>
#include"Passenger.h"

using namespace std;
namespace FlightApp
{
	Passenger::Passenger(const std::string& firstName, const std::string& lastName,
		const std::string& passengerContact, int passengerId)
		:mFirstName(firstName), mLastName(lastName),
		mPassengerContact(passengerContact),mPassengerId(passengerId)
	{
	}

	void Passenger::setFirstName(const string& firstName)
	{
		mFirstName = firstName;
	}

	const string& Passenger::getFirstName()const
	{
		return mFirstName;
	}

	void Passenger::setLastName(const string& lastName)
	{
		mLastName = lastName;
	}
	const string& Passenger::getLastName() const
	{
		return mLastName;
	}
	void Passenger::setPassengerContact(const string& passengerContact)
	{
		mPassengerContact = passengerContact;
	}
	const string& Passenger::getPassengerContact() const
	{
		return mPassengerContact;
	}
	void Passenger::setPassengerId(int passengerId)
	{
		mPassengerId = passengerId;
	}
	int Passenger::getPassengerId() const
	{
		return mPassengerId;
	}
	void Passenger::setSeatNumber(int seatNumber)
	{
		mSeatNumber = seatNumber;
	}
	int Passenger::getSeatNumber() const
	{
		return mSeatNumber;
	}

	Passenger& Passenger::createPassenger()
	{
		cout << endl;
		cout << endl;
		cout << "First Name: ";
		cin >> mFirstName;
		cout << "Last Name: ";
		cin >> mLastName;
		cout << "Contact Number: ";
		cin >> mPassengerContact;
		cout << "Passenger Id: ";
		cin >> mPassengerId;
		Passenger passenger;
		passenger.setFirstName(mFirstName);
		passenger.setLastName(mLastName);
		passenger.setPassengerContact(mPassengerContact);
		passenger.setPassengerId(mPassengerId);
		return passenger;
	}
	void Passenger::displayPassenger() const {
		cout << endl;
		cout << endl;
		cout << "Passenger Id: " << getPassengerId() << endl;
		cout << "Passenger Name:" << getLastName() << ", " << getFirstName() << endl;
		cout << "Contact Information: " << getPassengerContact() << endl;
		cout << "Seat Number: " << getSeatNumber() << endl;
	}
}