#include <iostream>
#include<fstream>
#include <string>
#include<limits>    //for cin.ignore
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<sstream>

using namespace std;


void buffer()
{
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
}
void screen(int n,string a)
{
	Sleep(n*1000);
	system("cls");
	system("COLOR 0e"); // Set background to black and text to yellow
    system("cls");      // Clear the console screen

    // Set output code page to 437 (for ASCII art)
    SetConsoleCP(437);
    SetConsoleOutputCP(437);

    char spinner[] = {'|', '/', '-', '\\'}; // Array of spinner characters
    int numFrames = sizeof(spinner) / sizeof(spinner[0]); // Number of frames

    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t "<<a<<"...";

    int frameIndex = 0;
    int startTime = GetTickCount(); // Get current system time in milliseconds

    while (true) {
        int currentTime = GetTickCount();
        if (currentTime - startTime >= 1000) // Stop after 1 seconds (1000 milliseconds)
            break;

        if (currentTime - startTime < 1800) { // While loading message is displayed
            cout << "\r\t\t\t\t\t\t\t" << spinner[frameIndex++] << " Loading..." << flush;
            if (frameIndex == numFrames)
                frameIndex = 0;
        } else { // After loading message is complete, display static character
            cout << "\r\t\t\t\t\t\t\t" << spinner[frameIndex] << " Loading...  " << flush;
        }

        Sleep(100); // Adjust animation speed here
    }
    system("cls");

}

struct date_time 
{
    int day, month, year, hour, minute; 
};

ostream& operator<<(ostream& os, const date_time& dt) 
{
    os << dt.day << "/" << dt.month << "/" << dt.year << " " << dt.hour << ":" << dt.minute;
    return os;
}

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
        buffer();
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
    
    void setAirlineName(string an)
    {
    	airline_name=an;
	}
	void setDeparture(date_time d)
	{
		departure=d;
	}
	void setArrival(date_time a)
	{
		arrival=a;
	}
	void setCapacity(int c)
	{
		capacity=c;
	}
	void setAvailableSeats(int as)
	{
		available_seats=as;
	}
	void setPrice(int p)
	{
		price=p;
	}

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

const int MAX_FLIGHTS = 100; 

class User
{
	protected:
		string username;
		string password;
		string full_name;
	public:
		bool cont;
		User()
		{
			username="",password="",full_name="";
			cont=false;
		}
		User(string u, string p,string fn)
		{
			username=u;
			password=p;
			full_name=fn;
		}       
        void registration()
		{
        	cout<<"Enter your username: ";
        	getline(cin,username);
        	cout<<"Enter your password: ";
        	getline(cin,password);
        	cout<<"Enter your full name: ";
        	getline(cin,full_name);
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
                Sleep(500);
                system("cls");
                cout << "Welcome!!!" << endl;
            } 
			else 
			{
                cout << "Invalid username or password. Please try again." << endl;
            }
        } 
		while (!loggedIn);

        return loggedIn;
        
    }
};
class Admin : public User ,public Flight
{
  private:
    int adminID;
    
  public:
  	int numFlights; 
  	Flight flights[MAX_FLIGHTS]; 
  	
    Admin(string uname, string pwd, string fn): adminID(1001), User(uname,pwd,fn), numFlights(0) {}

// Inside the Admin class

void createFlight() {
    if (numFlights >= MAX_FLIGHTS) {
        cout << "Cannot create a new flight. Maximum capacity reached." << endl;
        return;
    }

    Flight newFlight; // Create a new Flight object

    // Prompt the administrator to set details for the new flight
    cout << "Enter details for the new flight:\n";
    newFlight.set_flight();

    // Add the new flight to the system
    flights[numFlights] = newFlight;
    numFlights++;
    cout << "Flight created successfully." << endl;

    // Write flight details to a file
    ofstream outFile("flights.txt", ios::app); // Open the file in append mode
    if (!outFile.is_open()) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    outFile << newFlight.getAirlineName() << "," << newFlight.getDeparture().day << "/" << newFlight.getDeparture().month << "/" << newFlight.getDeparture().year << " " << newFlight.getDeparture().hour << ":" << newFlight.getDeparture().minute << ",";
    outFile << newFlight.getArrival().day << "/" << newFlight.getArrival().month << "/" << newFlight.getArrival().year << " " << newFlight.getArrival().hour << ":" << newFlight.getArrival().minute << ",";
    outFile << newFlight.getCapacity() << ",";
    outFile << newFlight.getAvailableSeats() << ",";
    outFile << newFlight.getPrice() << endl;

    outFile.close(); // Close the file
}


    void cancelFlight(Flight flightToCancel) 
	{
        bool found = false;
        for (int i = 0; i < numFlights; ++i) 
		{
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

// Inside the Admin class

void loadFlightsFromFile() {
    ifstream inFile("flights.txt"); // Open the file for reading
    if (!inFile.is_open()) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    // Temporary variables to store flight details while reading from the file
    string airlineName, deptDateTime, arrivalDateTime;
    int capacity, availableSeats;
    double price;
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        // Read flight details from each line
        getline(ss, airlineName, ',');
        getline(ss, deptDateTime, ',');
        getline(ss, arrivalDateTime, ',');
        ss >> capacity;
        ss.ignore(); // Ignore the comma
        ss >> availableSeats;
        ss.ignore(); // Ignore the comma
        ss >> price;

        // Convert date and time strings to date_time objects
        date_time departure, arrival;
        stringstream deptStream(deptDateTime);
        stringstream arrivalStream(arrivalDateTime);
        deptStream >> departure.day >> departure.month >> departure.year >> departure.hour >> departure.minute;
        arrivalStream >> arrival.day >> arrival.month >> arrival.year >> arrival.hour >> arrival.minute;

        // Create a Flight object and add it to the flights array
        Flight flight;
        flight.setAirlineName(airlineName);
        flight.setDeparture(departure);
        flight.setArrival(arrival);
        flight.setCapacity(capacity);
        flight.setAvailableSeats(availableSeats);
        flight.setPrice(price);

        flights[numFlights++] = flight; // Add flight to the array
    }

    inFile.close(); // Close the file
}

};

class Passenger:public User
{
	public: 
	    Passenger(string uname, string pwd,string fn): User(uname,pwd,fn) {}
};
int main() 
{   
    int choice1;
    Admin admin("admin1", "1234", "Admin");
    Passenger p1("ahmad7", "password1", "Ahmad");
    Passenger p2("nabeel25", "password2", "Nabeel");
    Passenger p3("murtaza8", "password3", "Murtaza");
    
    admin.loadFlightsFromFile();

    cout << "\t\t\tWelcome To Airline Reservation\n";
    cout << "\t***********************************************************\n\n";
    cout.width(30);
    cout << "1. Admin";
    cout.width(30);
    cout << "2. User\n\n";
    cout.width(30);
    cout << "Choose an option: ";
    cin >> choice1;
    
    // Clear the input buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   
    screen(0.5, "Welcome");
    
    if (choice1 == 1) {
        // Admin options
        cout << "\t\t\t\tWelcome Admin\n\n";
        if (admin.login()) {
            int adminChoice;
            do {
                cout << "Admin Menu:\n";
                cout << "1. Create a new flight\n";
                cout << "2. Cancel a flight\n";
                cout << "3. View all flights\n";
                cout << "4. Logout\n";
                cout << "Choose an option: ";
                cin >> adminChoice;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

                switch (adminChoice) {
                    case 1:
                        admin.createFlight();
                        break;
                    case 2:
                    {
                        cout << "Enter flight details to cancel: \n";
                        Flight flightToCancel;
                        flightToCancel.set_flight(); // Set flight details to cancel
                        admin.cancelFlight(flightToCancel);
                        break;
                    }
                    case 3:
                        admin.viewAllFlights();
                        break;
                    case 4:
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid option. Please try again.\n";
                        break;
                }
            } while (adminChoice != 4);
        }
    } 
}