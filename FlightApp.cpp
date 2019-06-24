#include"pch.h"
#include "pch.h"
#include <iostream>
#include"Flight.h"
#include"Database.h"
#include"Passenger.h"
using namespace std;
using namespace FlightApp;



int displayMenu();
int main()
{
	Database flightDB;
	Database passengerDB;

	flightDB.addFlight("Seattle", "Anchorage", 100, 10);
	flightDB.addFlight("Las Vegas", "Seattle", 101, 10);
	flightDB.addFlight("Seattle", "Las Vegas", 102, 10);
	
	//Flight &flight1;
	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 1:
			flightDB.displayAllFlights(flightDB);
			break;
		case 2:
			flightDB.displayAllFlights(flightDB);
			{Flight& flight = flightDB.selectFlight(flightDB);
			flight.reserveSeat(); }
			break;
		case 3:
			flightDB.displayPassengerInfo(flightDB);
			break;
		case 4:
			flightDB.displayFlightInformation(flightDB);
			break;
		case 5:
			flightDB.displayPassengerTicket(flightDB);
			break;
		case 0:
			return 0;
		default:
			cerr << "Not a valid selection !" << endl;
			break;
		}
	}
	return 0;
	
}


int displayMenu()
{
	int selection;
	cout << endl;
	cout << endl;
	
	cout << "------------------------------------------------------------" << endl;
	cout << "****** Welcome to AirLine Reservation System ******" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	cout << "****** Please select from the following options ******" << endl;
	cout << endl;
	cout << "1. Flight Schedule " << endl;
	cout << "2. Reserve a Flight " << endl;
	cout << "3. Display Passenger Information " << endl;
	cout << "4. Flight Details " << endl;
	cout << "5. Passenger Ticket Information" << endl;
	cout << "0. Exit the Program" << endl;
	cout << "Your Selection: ";
	cin >> selection;
	return selection;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
