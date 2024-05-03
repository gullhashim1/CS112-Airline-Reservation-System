#include <iostream>
#include <string>
#include<windows.h>
#include<conio.h>
#include<cstdlib>

using namespace std;

struct date_time 
{
    int day, month, year, hour, minute; 
};

void setdatetime(date_time &dt) 
{ 
    cout << "Enter the date\n\n";
    cout << "Date: ";
    cin >> dt.day;
    cout << "Month: ";
    cin >> dt.month;
    cout << "Year: ";
    cin >> dt.year;
    cout << "\nEnter the time\n\n";
    cout << "Hour: ";
    cin >> dt.hour;
    cout << "Minute: ";
    cin >> dt.minute;
}

class Flight 
{
  protected:
    double price;
    int capacity, available_seats;
    string airline_name, aircraft_name, arrival_airport, dept_airport;
    date_time arrival, departure;

  public:
    void set_flight() {
        cout << "Enter the name of the airline: ";
        cin >> airline_name;
        cout << "Enter the name of the aircraft: ";
        cin >> aircraft_name;
        cout << "Enter the airport of departure: ";
        cin >> dept_airport;
        cout << "Enter the airport of arrival: ";
        cin >> arrival_airport;
        cout << "\nFor departure\n\n";
        setdatetime(departure);
        cout << "\nFor arrival\n\n";
        setdatetime(arrival);
        cout << "\nEnter the capacity: ";
        cin >> capacity;
        cout << "Enter the base price: ";
        cin >> price;
        available_seats = capacity;
    }

    void isSeatAvailable() 
	{
        if (available_seats > 0) 
		{
            cout << "The number of available seats are: " << available_seats << endl;
        } else 
		{
            cout << "Sorry! The aircraft is full.\n";
        }
    }

    void reserveSeat() 
	{
        int numSeats;
        cout << "Enter the number of seats for reservation: ";
        cin >> numSeats;
        if (numSeats > available_seats) 
		{
            cout << "Sorry! Not enough seats for reservation\n";
        } else 
		{
            available_seats -= numSeats;
            cout << "Your seats have been reserved\n";
        }
    }

    double calculatePrice() 
	{
        string passengerType;
        cout << "Enter the type of passenger: ";
        cin >> passengerType;

        if (passengerType == "adult" || passengerType == "Adult") 
		{
            // Do nothing, price remains the same
        } else if (passengerType == "child" || passengerType == "Child") 
		{
            price = 0.5 * price;
        } else if (passengerType == "senior" || passengerType == "Senior") 
		{
            price = 0.75 * price;
        } else 
		{
            cout << "Invalid passenger type\n";
        }
        return price;
    }

    // Getter functions to access flight details
    string getAirlineName() const {
        return airline_name;
    }

    date_time getDeparture() const {
        return departure;
    }

    date_time getArrival() const {
        return arrival;
    }
    int getCapacity() const {
        return capacity;
    }

    int getAvailableSeats() const {
        return available_seats;
    }

    double getPrice() const {
        return price;
    }
};

const int MAX_FLIGHTS = 100; // Maximum number of flights the system can handle

class User
{
	protected:
		string username;
		string password;
	public:
		User()
		{
			username="",password="";
		}
		User(string u, string p)
		{
			username=u;
			password=p;
		}
		bool cont=false;       
        void registration()
		{
        	cout<<"Enter your username: ";
        	getline(cin,username);
        	cout<<"Enter your password: ";
        	getline(cin,password);
		}
	    bool login() 
		{
        string u, p;
        bool loggedIn = false;
        do 
		{
            cout << "Enter the username: ";
            getline(cin, u);
            cout << "Enter the password: ";
            getline(cin, p);
            if (username == u && password == p) 
			{
                loggedIn = true;
                cout << "Welcome!!!" << endl;
            } else 
			{
                cout << "Invalid username or password. Please try again." << endl;
            }
        } 
		while (!loggedIn);

        return loggedIn;
    }	
};
class Admin : public User 
{
  private:
    int adminID;
    Flight flights[MAX_FLIGHTS]; // Array to store flights
    int numFlights; // Number of flights currently in the system

  public:
    // Constructor with predefined Admin ID
    Admin(string uname, string pwd): adminID(1001), User(uname,pwd), numFlights(0) {}

    // Method to create a new flight in the system
    void createFlight() 
	{
        // Check if there's space for a new flight
        if (numFlights >= MAX_FLIGHTS) 
		{
            cout << "Cannot create a new flight. Maximum capacity reached." << endl;
            return;
        }
        
        else
        {
        Flight newFlight; // Create a new Flight object

        // Prompt the administrator to set details for the new flight
        cout << "Enter details for the new flight:\n";
        newFlight.set_flight();

        // Add the new flight to the system
        flights[numFlights] = newFlight;
        numFlights++;

        cout << "Flight created successfully." << endl;
        }
    }

    // Method to cancel an existing flight
    void cancelFlight(Flight flightToCancel) 
	{
        bool found = false;
        for (int i = 0; i < numFlights; ++i) 
		{
            // Compare the details of the flight to cancel with each flight in the system
            if (flights[i].getAirlineName() == flightToCancel.getAirlineName() &&
                flights[i].getDeparture().day == flightToCancel.getDeparture().day &&
                flights[i].getDeparture().month == flightToCancel.getDeparture().month &&
                flights[i].getDeparture().year == flightToCancel.getDeparture().year &&
                flights[i].getDeparture().hour == flightToCancel.getDeparture().hour &&
                flights[i].getDeparture().minute == flightToCancel.getDeparture().minute &&
                flights[i].getArrival().day == flightToCancel.getArrival().day &&
                flights[i].getArrival().month == flightToCancel.getArrival().month &&
                flights[i].getArrival().year == flightToCancel.getArrival().year &&
                flights[i].getArrival().hour == flightToCancel.getArrival().hour &&
                flights[i].getArrival().minute == flightToCancel.getArrival().minute) 
				{
                // If the flight is found, remove it from the array
                for (int j = i; j < numFlights - 1; ++j) 
				{
                    flights[j] = flights[j + 1];
                }
                numFlights--; // Decrement the number of flights
                found = true;
                break; // No need to continue searching
            }
        }
        if (found) 
		{
            cout << "Flight canceled successfully." << endl;
        } 
		else 
		{
            cout << "Flight not found. Unable to cancel." << endl;
        }
    }
    // Method to display a list of all flights in the system
void viewAllFlights() 
{
    if (numFlights == 0) 
	{
        cout << "No flights available." << endl;
        return;
    }
    cout << "List of all flights:" << endl;
    for (int i = 0; i < numFlights; ++i) 
	{
        cout << "Flight " << i + 1 << ":" << endl;
        cout << "Airline: " << flights[i].getAirlineName() << endl;
        cout << "Departure: " << flights[i].getDeparture().day << "/" << flights[i].getDeparture().month << "/" << flights[i].getDeparture().year;
        cout << " at " << flights[i].getDeparture().hour << ":" << flights[i].getDeparture().minute << endl;
        cout << "Arrival: " << flights[i].getArrival().day << "/" << flights[i].getArrival().month << "/" << flights[i].getArrival().year;
        cout << " at " << flights[i].getArrival().hour << ":" << flights[i].getArrival().minute << endl;
        cout << "Capacity: " << flights[i].getCapacity() << endl;
        cout << "Available Seats: " << flights[i].getAvailableSeats() << endl;
        cout << "Base Price: " << flights[i].getPrice() << endl;
        cout << endl;
    }
}

};

class regularUser: User
{
	private:
		
	public: 
};


int main() 
{
	int choice1;
	string admin_username = "hashim"; // Username constant
    string admin_password = "1234"; // Password constant
    string enteredUsername, enteredPassword;
    cout.width(30);
	cout<<"1. Admin";
	cout.width(30);
	cout<<"2.User\n\n";
	cout<<"Choose an option\n\t\t\t";
	cin>>choice1;
	
	switch(choice1)
	{
    
    case 1:	
        cout << "Enter Username:\n\t\t\t ";
        cin >> enteredUsername;
        cout << "Enter Password:\n\t\t\t ";
        cin >> enteredPassword;
        break;
    
    case 2:
    	break;

		case 3:
		break;
    	
    default:
    	break;
}
  return 0;
}
