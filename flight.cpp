#include<iostream>

using namespace std;

struct date_time
{
	int day,month,year,hour,minute; 
};

void setdatetime(date_time dt)
{
	cout<<"Enter the date\n\n";
	cout<<"Date: ";
	cin>>dt.day;
	cout<<"Month: ";
	cin>>dt.month;
	cout<<"Year: ";
	cin>>dt.year;
	cout<<"\nEnter the time\n\n";
	cout<<"Hour: ";
	cin>>dt.hour;
	cout<<"Minute: ";
	cin>>dt.minute;
}

class Flight
{
	protected:
	 double price;
	 int capacity , available_seats;
	 string airline_name , aircraft_name , arrival_airport , dept_airport;
	 date_time arrival , departure;
	
	public:
		void set_flight()
		{
			cout<<"Enter the name of the airline: ";
			cin>>airline_name;
			cout<<"Enter the name of the aircraft: ";
			cin>>aircraft_name;
			cout<<"Enter the airport of depature: ";
			cin>>dept_airport;
			cout<<"Enter the airport of arrival: ";
			cin>>arrival_airport;
			cout<<"\nFor departure\n\n";
			setdatetime(departure);
			cout<<"\nFor arrival\n\n";
			setdatetime(arrival);
			cout<<"\nEnter the capacity: ";
			cin>>capacity;
			cout<<"Enter the base price: ";
			cin>>price;
			available_seats=capacity;
		}
		void isSeatAvailable()
		{
			if(available_seats>0)
			{
				cout<<"The number of available seats are: "<<available_seats<<endl;
			}
			else
			{
				cout<<"Sorry! The aircraft is full.\n";
			}
		}
		void reserveSeat()
		{
			int numSeats;
			cout<<"Enter the number of seats for reservation: ";
			cin>>numSeats;
			if(numSeats>available_seats)
			{
				cout<<"Sorry! Not enough seats for reservation\n";
			}
			else
			{
				available_seats-=numSeats;
				cout<<"Your seats have been reserved\n";
			}
		}
		double calculatePrice()
		{
			string passengerType;
			cout<<"Enter the type of passenger: ";
			cin>>passengerType;
			
			if(passengerType=="adult" || passengerType=="Adult")
			{
				
			}
			else if(passengerType=="child" || passengerType=="Child")
			{
				price=0.5*price;
			}
			else if(passengerType=="senior" || passengerType=="Senior")
			{
				price=0.75*price;
			}
			else
			{
			    cout<<"Invalid passenger type\n";
			}
			return price;
		}
};

int main()
{
	double final_price;
	Flight flight;
	flight.set_flight();
	flight.isSeatAvailable();
	flight.reserveSeat();
	final_price=flight.calculatePrice();
	cout<<"The final price of one ticket now is: "<<final_price<<endl;
}
