#include"pch.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include"Flight.h"
#include"Passenger.h"


using namespace std;

namespace FlightApp {
	class Passenger;
	
	Flight::Flight(const std::string& departureCity, const std::string& arrivalCity,
		int flightNumber, int noOfSeats)
		: mDepartureCity(departureCity),
		mArrivalCity(arrivalCity),
		mFlightNumber(flightNumber)
	{
		for (int i = 1; i <= noOfSeats; i++)
		{

			mAvailableSeats.push_back(i);

		}

	}

	const std::string& Flight::getArrivalCity() const
	{
		return mArrivalCity;
	}
	void Flight::setArrivalCity(const std::string& arrivalCity)
	{
		mArrivalCity = arrivalCity;
	}

	const std::string& Flight::getDepartureCity() const
	{
		return mDepartureCity;
	}
	void Flight::setDepartureCity(const std::string& departureCity)
	{
		mDepartureCity = departureCity;
	}
	int Flight::getFlightNumber() const
	{
		return mFlightNumber;
	}
	void Flight::setFlightNumber(int flightNumber)
	{
		mFlightNumber = flightNumber;
	}
	void Flight::setAvailableSeats(std::vector<int> availableSeats)
	{
		mAvailableSeats = availableSeats;
	}
	std::vector<int>  Flight::getAvailableSeats() const {
		return mAvailableSeats;
	}

	void Flight::reserveSeat()
	{
		auto availableSeats = getAvailableSeats();
		for (int seat : availableSeats)
		{
			cout << seat << " ";
		}
		cout << endl;
		cout << "Please select your preferred seat: " << endl;
		int selectedSeat;
		cin >> selectedSeat;
		Passenger passenger;
		passenger.createPassenger();
		passenger.setSeatNumber(selectedSeat);
		bookTicket(passenger);
		//passenger.displayPassenger();
	}

	vector<Passenger>& Flight::getPassengers() 
	{
		return mPassenger;
	}

	void Flight::bookTicket(Passenger &passenger)
	{
		mPassenger.push_back(passenger);  
		int seatNumber = passenger.getSeatNumber();
		//get th seat number and remove it from the available seats vector.
		mAvailableSeats.erase(std::remove(mAvailableSeats.begin(),
			mAvailableSeats.end(), seatNumber), mAvailableSeats.end());
	
		auto availableSeats = getAvailableSeats();
		cout << endl;
		cout << "Congratulations, ticket booked successfully ! Your seat number is: " << passenger.getSeatNumber() << endl;
		cout << "Remaining Seats " << endl;
		for (int remainingseats : availableSeats)
		{
			{
				cout << remainingseats << " ";
			}
		}
	}

	void Flight::display() const
	{
		cout << endl;
		cout << endl;
		vector<int> availableSeats = getAvailableSeats();		
		//cout << "Flight Number: " << getFlightNumber() << " " << "Departure City: " << getDepartureCity() << " " << "Arrival City: " << getArrivalCity() << " " << endl;
		cout << getFlightNumber() << "\t  " << getDepartureCity() << " \t  "  << getArrivalCity() << "\t  " << availableSeats.size() <<endl;
	}
}
