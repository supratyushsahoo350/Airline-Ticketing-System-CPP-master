#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include<Windows.h>
using namespace std;
struct User {
	string username;
	string password;
	string email;
};
fstream file;

struct Ticket
{
	string Sno;
	string Name;
	string depart;
	string dest;
	string SeatNum;
	string Price;
	string Class;
	string Date;
	string FlightNo;
	string time;
};

struct SeatRecord {
	string RowA;
	string RowB;
	string RowC;
};


fstream myfile;
ifstream File2;
Ticket AllTickets[200];

void intro();
string SeatChoose();
int SplitStruct();
void printTic(int Count);
int fclass(int a);
void SaveTic(Ticket a);
void EditTicket();
void DelTicket();
void Display(int c);
void Login(int c);
void Registration(int c);
void LuggageDetails();
void Payment();

int main()
{
	system("mode 650");
	intro();
	int c;
	srand(time(0));
	c = (rand() % 10000);
	string Choice;
	cout << "\n\n\t\t\t\t\t\t\t\t=============================================== \n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t Welcome to Airline Ticketing Sysyem\t \n";
	cout << "\n\n\t\t\t\t\t\t\t\t=============================================== \n";
	cout << "\n\n\t\t\t\t\t\t\t\t\tPlease choose an option \n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t1. Registeration. \n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t2. Already a user? Login now. \n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t3. Close Application. \n";
	cout << "\n\n\t\t\t\t\t\t\t\t\tEnter your choice(1-3): ";
	for (int i = 1; i > 0; i++)
	{
		cin >> Choice;
		if (Choice == "1" || Choice == "Registration" || Choice == "registration" || Choice == "register" || Choice == "Register")
		{
			Registration(c);
			break;
		}
		else if (Choice == "2" || Choice == "Login" || Choice == "login")
		{
			Login(c);
			break;
		}
		else if (Choice == "3")
		{
			cout << "\n\n\t\t\t\t\t\t\t\t The Program will now exit! \n";
			cout << "\n\n\t\t\t\t\t\t\t\t ";
			exit(0);
		}
		else
			cout << "\n\n\t\t\t\t\t\t\t\tInvalid Input, Re-enter your choice(1-3): ";
	}

}

void intro() {
	cout << endl << endl << endl << endl << "\t\t\t\t\t"; Sleep(900);
	cout << "\n\t\t\t\t\t         ||||       ||||||| ||||||||||  ||||      ||||||| ||||||||||  |||| |||||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t        ||  ||      ||||||| |||    |||  ||||      ||||||| ||||  ||||  |||| |||| "; Sleep(200);
	cout << "\n\t\t\t\t\t       |||  |||       |||   ||||||||||  ||||        |||   ||||  ||||  |||| ||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t      ||||||||||      |||   |||||||     ||||        |||   ||||  ||||  |||| ||||||| "; Sleep(200);
	cout << "\n\t\t\t\t\t     |||      |||   ||||||| ||| ||||    ||||||||| ||||||| ||||  ||||  |||| |||| "; Sleep(200);
	cout << "\n\t\t\t\t\t    ||||       |||| ||||||| |||  |||||  ||||||||| ||||||| ||||  |||||||||| ||||||||||"; Sleep(200);
	cout << endl << endl << "\t\t\t"; Sleep(300);
	cout << "\n\t\t\t        |||||||||| ||||||| ||||||||| ||||  |||| ||||||||||  ||||||||| |||||||||| ||||||||||  |||| |||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t        |||||||||| ||||||| ||||||||| |||| |||   ||||        ||||||||| |||||||||| ||||  ||||  |||| ||||       ||||"; Sleep(200);
	cout << "\n\t\t\t           ||||      |||   |||       |||||||    |||||||     |||          ||||    ||||  ||||  |||| ||||           "; Sleep(200);
	cout << "\n\t\t\t           ||||      |||   |||       |||||||    |||||||     |||          ||||    ||||  ||||  |||| ||||  |||||||||"; Sleep(200);
	cout << "\n\t\t\t           ||||    ||||||| ||||||||| |||| |||   ||||        |||||||||    ||||    ||||  ||||  |||| ||||  |||  ||||"; Sleep(200);
	cout << "\n\t\t\t          ||||||   ||||||| ||||||||| ||||  |||| ||||||||||  |||||||||   ||||||   ||||  |||||||||| |||||||||  ||||"; Sleep(200);
	cout << endl << endl << "\t\t\t\t\t"; Sleep(300);
	cout << "\n\t\t\t\t\t         ||||||||| ||||   |||| ||||||||| |||||||||| ||||||||||  ||||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||      ||||   |||| ||||      |||||||||| ||||        ||||||||||||||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||||||| ||||||||||| |||||||||    ||||    |||||||     ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         |||||||||        |||| |||||||||    ||||    |||||||     ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t              |||| ||||   ||||      ||||    ||||    ||||        ||||  ||||  ||||"; Sleep(200);
	cout << "\n\t\t\t\t\t         ||||||||| ||||||||||| |||||||||   ||||||   ||||||||||  ||||  ||||  ||||"; Sleep(200);
	cout << endl << endl << endl << endl << endl << "\t\t\t\t\t\t\t"; Sleep(1000);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\tProject Prepared by:"; Sleep(400);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t--------------------"; Sleep(500);
	cout << "\n\n\t\t\t\t\t\t\t\t  SUPRATYUSH SAHOO     21051350"; Sleep(1000);
    cout << "\n\n\t\t\t\t\t\t\t\t  DEBASISH NAYAK       21051889";
	cout << "\n\n\t\t\t\t\t\t\t\t  SUSREE SOUMYA ROUT   2105841";
	cout << "\n\n\t\t\t\t\t\t\t\t  RISHAV PRASAD         2105818";
	cout << "\n\n\t\t\t\t\t\t\t\t  AAYUSH KUMAR          2105344";
	Sleep(3500);
	system("cls");
}





void LuggageDetails()
{
	cout << "\n\n\t\t\t\t\t\t\t\tYour allowance is based on the total weight of all your baggage.";
	cout << "\n\n\t\t\t\t\t\t\t\tEconomy Class: ";
	cout << "\n\n\t\t\t\t\t\t\t\t2 x 25kg Baggages allowed! ";
	cout << "\n\n\t\t\t\t\t\t\t\ttBusiness Class: ";
	cout << "\n\n\t\t\t\t\t\t\t\t2x 35kg Baggages allowed! ";
	cout << "\n\n\t\t\t\t\t\t\t\tBaggage Dimensions are as follows: ";
	cout << "\n\n\t\t\t\t\t\t\t\tThe total dimensions of a bag should not exceed 300 cm(118 inches)\n\n\n";

	cout << "\n\n\t\t\t\t\t\t\t\t\t*******************";
	cout << "\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n\n\t\t\t\t\t\t\t\t\t*\t\t  *\n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t*******************\n\n\n";
	system("pause");
}



void Payment()
{
	string name, lname, cc, cvv, dob;

	cout << endl << endl;
	cout << "\n\n\t\t\t\t\t\t\t\t===============PAYMENT DETIALS===============" << endl;

	cout << "\n\n\t\t\t\t\t\t\t\tEnter First Name: ";
	cin >> name;

	cout << "\n\n\t\t\t\t\t\t\t\tEnter Last Name: ";
	cin >> lname;


check:
	cout << "\n\n\t\t\t\t\t\t\t\tEnter Credit/Debit Card Number (16 digits): ";
	cin >> cc;
	if (cc.length() != 16)
	{
		cout << "\n\n\t\t\t\t\t\t\tCC number must have a length of 16 only! \n";
		goto check;
	}
	else
		check2:
	cout << "\n\n\t\t\t\t\t\t\t\tEnter CVV (3 digits): ";
	for (int i = 0; i > -1; i++)
	{
		char temp;
		temp = _getch();
		if (temp != 13 && temp != 8)
		{
			_putch('*');
		}
		if (temp == 13)
		{
			break;
		}
		if (temp == 8 || temp == 127 && !cvv.empty())
		{
			cout << "\b \b";
			cvv.erase(cvv.size() - 1);
		}
		else
			cvv += temp;
	}
	if (cvv.length() != 3)
	{
		cout << "\n\n\t\t\t\t\t\t\tCVV number must have a length of 3 only! \n";
		cvv = "";
		goto check2;
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\t\t\tEnter Date Of Birth(DD/MM/YYYY): ";
		cin >> dob;
		cout << "\n\n\t\t\t\t\t\t\t\tYour payment is successfully processed!";
		
		fstream payfile;
		payfile.open("Payment_Details.txt", payfile.app);
		payfile << name << "-" << lname << "-" << cc << "-" << cvv << "-" << dob << "-" << "\n";
		payfile.close();
	}
	cout << "\n\n\t\t\t\t\t\t\t\t";
	system("pause");
}


string SeatChoose()
{
	fstream Seat;
	int count = 0, delimit = 0;
	string line;
	SeatRecord Seats[10];
	Seat.open("Seat_Details.txt");
	while (getline(Seat, line))
	{
		count++;
	}
	Seat.close();
	Seat.open("Seat_Details.txt");
	for (int j = 0; j < count; j++)
	{
		string line1;
		getline(Seat, line1);
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowA += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowB += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			Seats[j].RowC += temp;
		}
	}
	Seat.close();
	string RowName, SeatNum, FinalSeatNum;
	bool Flag = false;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tA" << "\t" << " B" << "\t" << " C" << "\t\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t" << Seats[i].RowA << "\t" << Seats[i].RowB << "\t" << Seats[i].RowC << "\t\n";
	}

	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t======================================\n";
	for (int x = 0; x > -1; x++)
	{
		cout << "\n\n\t\t\t\t\t\t\t\t\tEnter the row name that you chose: ";
		cin >> RowName;
		if (RowName != "A" && RowName != "B" && RowName != "C")
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\tInvalid row, please try again. ";
		}
		else
			break;
	}
	for (int x = 0; x > -1; x++)
	{
		check7:
		cout << "\n\n\t\t\t\t\t\t\t\t\tEnter the seat number that you chose: ";
		cin >> SeatNum;
		if (SeatNum == "XX")
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\tInvalid seat, please try again! \n";
			goto check7;
		}
		for (int i = 0; i < 10; i++)
		{
			if (RowName == "A")
			{
				if (SeatNum == Seats[i].RowA)
				{
					Seats[i].RowA = "XX";
					Flag = true;
					break;
				}
			}
			else if (RowName == "B")
			{
				if (SeatNum == Seats[i].RowB)
				{
					Seats[i].RowB = "XX";
					Flag = true;
					break;
				}
			}
			else if (RowName == "C")
			{
				if (SeatNum == Seats[i].RowC)
				{
					Seats[i].RowC = "XX";
					Flag = true;
					break;
				}
			}
		}


		if (Flag == false)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tSeat number not found, please try again. \n";
		}
		else
			break;
	}
		FinalSeatNum = RowName + SeatNum;
		ofstream Del;
		Del.open("Seat_Details.txt", ios::trunc);
		Del.close();
		Del.open("Seat_Details.txt", ios::trunc);
		for (int i = 0; i < 10; i++)
		{
			Del << Seats[i].RowA << "-" << Seats[i].RowB << "-" << Seats[i].RowC << "-\n";
		}
		Del.close();
		return FinalSeatNum;
	}





int SplitStruct()
{
	int q, count = 0, delimit = 0;
	string b, line;
	myfile.open("Booking_Details.txt");
	while (getline(myfile, line)) //dynamic 
	{
		count++;
	}
	myfile.close();
	myfile.open("Booking_Details.txt");
	for (int j = 0; j < count; j++)
	{
		string line1;
		getline(myfile, line1);
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].Sno += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].Price += temp;
		} //Checked

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].FlightNo += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].Name += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].Date += temp;
		}


		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].time += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].depart += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].dest += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].SeatNum += temp;
		}
		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line1[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			AllTickets[j].Class += temp;
		}
	}
	myfile.close();
	return count;
}

void printTic(int Count)
{

	string line, Serial_Num;
	bool Found = false;

	//Printing Details of ticket:
	check3:
	cout << "\n\n\t\t\t\t\t\t\t\tEnter the serial number of the ticket that you want to view: ";
	cin >> Serial_Num;
	cout << "\n\n\t\t\t\t\t\t\t\t=============================================================\n";
	for (int i = 1; i < Count; i++)
	{

		if (Serial_Num == AllTickets[i].Sno)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\t"<< AllTickets[i].Name << " is the name of the Passenger of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].Price << " is the price of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].FlightNo << " is the Flight number of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].Sno << " is the serial number of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].Date << " is the date of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].time << " is the time of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].depart << " is the Departure location of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].dest << " is the Destination of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].SeatNum << " is the seat number of this ticket. \n";
			cout << "\n\n\t\t\t\t\t\t\t\t\t" << AllTickets[i].Class << " is the class of this ticket. ";
			Found = true;
			cout << "\n\n\t\t\t\t\t\t\t\t=============================================================\n";
		}
	}
	if (Found == false)
	{
		cout << "\n\n\t\t\t\t\t\t\t\t\tSerial not found, please try again. ";
		goto check3;
	}
	cout << "\n\n\t\t\t\t\t\t\t\t\t";
	system("pause");
}


int fclass(int a)
{
	//Calculating Amount:
	int amount = 0;
	if (a == 1)
	{
		amount = 25000;
	}
	else if (a == 2)
	{
		amount = 60000;
	}
	return amount;
}

void SaveTic(Ticket a)
{
	string b, line;
	fstream myfile;
	//Saving information of Newticket function:
	myfile.open("Booking_Details.txt", myfile.app);
	myfile << a.Sno << "-" << a.Price << "-" << a.FlightNo << "-" << a.Name;
	myfile << "-" << a.Date << "-" << a.time << "-" << a.depart << "-";
	myfile << a.dest << "-" << a.SeatNum << "-" << a.Class << "-\n";
	myfile.close();
	SplitStruct();
}

void EditTicket()
{
	string Check, line;
	int count = 0;
	bool found = false;
	fstream FILE;

	//Counting number of lines previously written in booking file:
	FILE.open("Booking_Details.txt");
	while (getline(FILE, line)) //dynamic 
	{
		count++;
	} 
	FILE.close();

	//Checking serial number to edit details:
check4:
	char valcheck;
	cout << "\n\n\t\t\t\t\t\tEnter the serial number of the booking that you want to edit: ";
	cin >> Check;
	cout << "\n";
	for (int i = 0; i < count; i++)
	{
		if (Check == AllTickets[i].Sno)
		{
			found = true;

			//Edit name here
			cout << "\n\n\t\t\t\t\t\tYour Previous Customer Name was: " << AllTickets[i].Name << ".\n\t\t\t\t\t\tIf You Want to change the name press \'n\' and Hit \'Enter\' to continue with the same name: ";
			valcheck = _getch();
			if (valcheck == 13) {
				cout << "\n\n\t\t\t\t\t\tYour Customer Name is Set to " << AllTickets[i].Name;
			}
			else {
				cout << "\n\n\t\t\t\t\t\tEnter New Name of Customer: ";
				cin.ignore();
				getline(cin, AllTickets[i].Name);
			}

			//Edit Boarding City Here:
			cout << "\n\n\t\t\t\t\t\tYour Boarding City was: " << AllTickets[i].depart << ".\n\t\t\t\t\t\tIf You Want to change the boarding city press \'n\' and Hit \'Enter\' to continue with the same city: ";
			valcheck = _getch();
			if (valcheck == 13) {
				cout << "\n\n\t\t\t\t\t\tYour Boarding City is Set to " << AllTickets[i].depart;
			}
			else {
				cout << "\n\n\t\t\t\t\t\t\tEnter New Boarding city: ";
				getchar();
				getline(cin, AllTickets[i].depart);
			}

			//Edit Destination Here:
			cout << "\n\n\t\t\t\t\t\tYour Destination was: " << AllTickets[i].dest << ".\n\t\t\t\t\t\tIf You Want to change the destination press \'n\' and Hit \'Enter\' to continue with the same destination: ";
			valcheck = _getch();
			if (valcheck == 13) {
				cout << "\n\n\t\t\t\t\t\tYour Destination is Set to " << AllTickets[i].dest;
			}
			else {
				cout << "\n\n\t\t\t\t\t\tEnter New Destination: ";
				getchar();
				getline(cin, AllTickets[i].dest);
			}

			//Edit Date of Departure Here:
			cout << "\n\n\t\t\t\t\t\tYour Date of Departure was: " << AllTickets[i].Date << ".\n\t\t\t\t\t\tIf You Want to change the date of departure press \'n\' and Hit \'Enter\' to continue with the same date: ";
			valcheck = _getch();
			if (valcheck == 13) {
				cout << "\n\n\t\t\t\t\t\tYour Date of Departure is Set to " << AllTickets[i].Date;
			}
			else {
				cout << "\n\n\t\t\t\t\t\tEnter New Date of Departure(DD/MM/YYYY): ";
				getchar();
				getline(cin, AllTickets[i].Date);
			}

			//Edit time of Departure Here:
			cout << "\n\n\t\t\t\t\t\tYour Time of Departure was: " << AllTickets[i].time << ".\n\t\t\t\t\t\tIf You Want to change the time of departure press \'n\' and Hit \'Enter\' to continue with the same time: ";
			valcheck = _getch();
			if (valcheck == 13) {
				cout << "\n\n\t\t\t\t\t\tYour Time of Departure is Set to " << AllTickets[i].time;
			}
			else {
				cout << "\n\n\t\t\t\t\t\tEnter New Time of Departure(HH:MM AM/PM): ";
				cin.ignore();
				getline(cin, AllTickets[i].time);
			}

			cout << "\n\n\t\t\t\t\t\tAlert: Your previously booked seat number cannot be changed now! ";

			//Editing Class:
			cout << "\n\n\t\t\t\t\t\t1) Regular\n\n\t\t\t\t\t\t2) Business\n\n\t\t\t\t\t\tPick class (1-2): ";
			int x;
			cin >> x;
			if (x == 1) {
				AllTickets[i].Class = "Economy";
			}
			else if (x == 2) {
				AllTickets[i].Class = "Business";
			}
			AllTickets[i].Price = to_string(fclass(x));

			cout << "\n\n\t\t\t\t\t\tYour New Price of Ticket: ";
			cout << AllTickets[i].Price;
			break;
		}
	}

	//Checking Serial No:
	if (found == false)
	{
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\tSerial not found! \n";
		Sleep(600);
		goto check4;
	}
	else
	{
		//Writing Edited details:
		ofstream file1;
		file1.open("Booking_Details.txt", ios::trunc);
		file1.close();
		file1.open("Booking_Details.txt", ios::app);
		for (int i = 0; i < count; i++)
		{
			file1 << AllTickets[i].Sno << "-" << AllTickets[i].Price << "-" << AllTickets[i].FlightNo << "-" << AllTickets[i].Name;
			file1 << "-" << AllTickets[i].Date << "-" << AllTickets[i].time << "-" << AllTickets[i].depart << "-";
			file1 << AllTickets[i].dest << "-" << AllTickets[i].SeatNum << "-" << AllTickets[i].Class << "-\n";
		}
		file1.close();
		cout << "\n\n\t\t\t\t\t\t\tTicket successfully edited!\n\n";
		cout << "\n\n\n\t\t\t\t\t\tLoading"; Sleep(200);
		cout << "."; Sleep(200);
		cout << "."; Sleep(400);
		cout << "."; Sleep(200);
		cout << "."; Sleep(200);
		cout << "."; Sleep(200);
		Sleep(1000);
	}
}

void NewTicket(int c)
{
	string inp;
	int q, b;
	Ticket a;

	cout << "\n\n\t\t\t\t\t\t\t\t\t\tCreate New Ticket  \n\n";


	cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Name of Customer: ";
	cin.ignore();
	getline(cin, a.Name);

	cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Boarding city: ";
	getline(cin, a.depart);
	cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Destination: ";
	getline(cin, a.dest);

	cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Date of Departure(DD/MM/YYYY): ";
	getline(cin, a.Date);
	cout << "\n\n\t\t\t\t\t\t\t\t\tEnter Time of Departure(HH:MM AM/PM): ";
	getline(cin, a.time);
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tAvailable Seats: \n";
	a.SeatNum = SeatChoose();

	cout << "\n\n\t\t\t\t\t\t\t\t\t1) Economy\n\n\t\t\t\t\t\t\t\t\t2) Business\n\n\t\t\t\t\t\t\t\t\tPick class (1-2): ";
	string x;
	int y;

	for (int i = 0; i > -1; i++)
	{
		cin >> x;
		if (x == "1") {
			a.Class += "Economy";
			y = 1;
			break;
		}
		else if (x == "2") {
			a.Class += "Business";
			y = 2;
			break;
		}
		else
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\tInvalid input! Please enter again (1-2): ";
		}
	}

	//function to return price of class:
	a.Price = to_string(fclass(y));

	cout << "\n\n\t\t\t\t\t\t\t\t\tPrice of ticket: ";
	cout << a.Price;
	cout << "\n\n\t\t\t\t\t\t\t\t";
	system("pause");


	//Function to Select Payment:
	Payment();
	
	//Generating Flight No.
	system("cls");
	srand(time(0));
	b = (rand() % 10000);
	a.FlightNo += "PK" + to_string(b);
	cout << "\n\n\t\t\t\t\t\t\t\t\tYour Flight no: " << a.FlightNo;
	

	//Assigning a Serial No.
	a.Sno += to_string(c);
	cout << "\n\n\t\t\t\t\t\t\t\t\tSessional serial number is: " << a.Sno << endl;

	//function to save ticket:
	SaveTic(a);

	cout << "\n\n\t\t\t\t\t\t\t\t\tNew ticket successfully created!\n\n";
	cout << "\n\n\t\t\t\t\t\t\t\t\t";
	cout << "\n\n\n\t\t\t\t\t\t\t\tLoading"; Sleep(200);
	cout << "."; Sleep(200);
	cout << "."; Sleep(400);
	cout << "."; Sleep(200);
	cout << "."; Sleep(200);
	cout << "."; Sleep(200);
	Sleep(1000);


}

void DelTicket()
{
	string Check, line;
	int count = 0, BrLine;
	bool found = false;
	fstream FILE;

	//To count the previously recorded lines in booking file
	FILE.open("Booking_Details.txt");
	while (getline(FILE, line)) //dynamic 
	{
		count++;
	}
	FILE.close();
	//Here user will give Serial Number to delete its booking:
	check5:
	cout << "\n\n\t\t\t\t\t\t\t\t\Enter the serial number of the booking that you want to delete: ";
	cin >> Check;
	cout << "\n";

	//Checking required Serial Number from whole file:
	for (int i = 0; i < count; i++)
	{
		if (Check == AllTickets[i].Sno)
		{
			BrLine = i;
			found = true;
			AllTickets[i].Sno = " ";
			AllTickets[i].Name = " ";
			AllTickets[i].Class = " ";
			AllTickets[i].Date = " ";
			AllTickets[i].depart = " ";
			AllTickets[i].dest = " ";
			AllTickets[i].FlightNo = " ";
			AllTickets[i].Price = " ";
			AllTickets[i].SeatNum = " ";
			AllTickets[i].time = " ";
			break;
		}
	}
	if (found == false)
	{
		cout << "\n\n\t\t\t\t\t\t\t\t\Serial not found! \n";
		goto check5;
		system("pause");
	}
	//Deleting Booking information of that user:
	else
	{
		ofstream file1;

		//Deleting Whole data
		file1.open("Booking_Details.txt", ios::trunc);
		file1.close();
		//Re-writing Data in the file excluding deleted one:
		file1.open("Booking_Details.txt", ios::app);
		for (int i = 0; i < count; i++)
		{
			if (i != BrLine)
			{
				file1 << AllTickets[i].Sno << "-" << AllTickets[i].Price << "-" << AllTickets[i].FlightNo << "-" << AllTickets[i].Name;
				file1 << "-" << AllTickets[i].Date << "-" << AllTickets[i].time << "-" << AllTickets[i].depart << "-";
				file1 << AllTickets[i].dest << "-" << AllTickets[i].SeatNum << "-" << AllTickets[i].Class << "-\n";
			}
		}
		file1.close();
		cout << "\n\n\t\t\t\t\t\t\t\t\Ticket successfully deleted!\n\n";
		system("pause");
	}
}

void Display(int c)
{
	int Counter;
	Counter = SplitStruct();
	system("cls");
	char choice;
	do
	{
		system("cls");
		system("color 11");
		cout << "\n\n\t\t\t\t\t\t\t         Airline Ticket Management System\n";
		cout << "\n\n\t\t\t\t\t\t\t       ============= MAIN MENU =============\n";
		cout << "\n\n\t\t\t\t\t\t\t\t01. Create New Ticket.\n";
		cout << "\n\n\t\t\t\t\t\t\t\t02. Edit Reserved Tickets.\n";
		cout << "\n\n\t\t\t\t\t\t\t\t03. Delete Your Ticket.\n";
		cout << "\n\n\t\t\t\t\t\t\t\t04. Print/Display Booked Ticket.\n";
		cout << "\n\n\t\t\t\t\t\t\t\t05. Luggage Allowance Details.\n";
		cout << "\n\n\t\t\t\t\t\t\t\t06 Exit.\n";
		cout << "\n\n\t\t\t\t\t\t\t\tSelect Your Option (1 - 6): ";
		cin >> choice;
		system("cls");

		if (choice == '1')
		{
			NewTicket(c);
			Counter++;
		}
		else if (choice == '2')
		{
			EditTicket();
		}
		else if (choice == '3')
		{
			DelTicket();
		}
		else if (choice == '4')
		{
			printTic(Counter);
		}
		else if (choice == '5')
		{
			LuggageDetails(); 
		}
		else if (choice == '6')
		{
			cout << "\n\n\t\t\t\t\t\t\t\tThe program will now exit!";
			cout << "\n\n\t\t\t\t\t\t\t\t";
			break;
		}	

	} while (choice != '6');

}

void Login(int c)
{
	system("cls");
	User arr[200];
	int delimit = 0, count = 0, Iterator = 0;
	file.open("Login_Details.txt");
	string line;

	while (getline(file, line)) //dynamic 
	{
		count++;
	}
	file.close();
	file.open("Login_Details.txt");

	for (int j = 0; j < count; j++) //dynamic needed here
	{
		string line;
		getline(file, line);
		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			arr[j].username += temp;
		}

		for (int i = delimit + 1; i > -1; i++)
		{
			char temp;
			temp = line[i];
			if (temp == '-')
			{
				delimit = i;
				break;
			}
			arr[j].password += temp;
		}
	}

	cout << "\n\n\t\t\t\t\t\t\t\t    ===================== LOGIN ===================== \n\n";
	string user, pass;
	bool login = false;

	//checking username and password:
	check:
	cout << "\n\n\t\t\t\t\t\t\t\tEnter authorized Username: ";
	getchar();
	getline(cin, user);
	cout << "\n\n\t\t\t\t\t\t\t\tEnter authorized Password: ";

		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = _getch();
			if (temp != 13 && temp != 8)
			{
				_putch('*');
			}
			if (temp == 13)
			{
				break;
			}
			if (temp == 8 || temp == 127 && !pass.empty())
			{
				cout << "\b \b";
				pass.erase(pass.size() - 1);
			}
			else
				pass += temp;

		}
		cout << "\n";



	
		for (int i = 0; i < count; i++) //and here
		{
			if (user == arr[i].username && pass == arr[i].password)
			{
				login = true;
				break;
			}
		}

		if (login == true)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\tLogged in! \n";
			cout << "\n\n\t\t\t\t\t\t\t\tSessional serial number is: " << c << "\n\n\t\t\t\t\t\t\t\t\t";
			cout << "\n\n\t\t\t\t\t\t\t\t\tLoading"; Sleep(200);
			cout << "."; Sleep(200);
			cout << "."; Sleep(400);
			cout << "."; Sleep(200);
			cout << "."; Sleep(200);
			cout << "."; Sleep(200);
			Sleep(2000);
			Display(c);
		}
		else {
			Beep(1000, 600);
			cout << "\n\n\t\t\t\t\t\t\t\tInvalid login credentials, please try again! \n";
			user = "";
			pass = "";
			goto check;
		}
	
	file.close();
}

void Registration(int c)
{
	system("cls");
	cout << "\n\t\t\t\t\t\t\t\t     ================= REGISTRATION ================= \n\n";

	//File to write Login Details:
	file.open("Login_Details.txt", file.app);
	string Username, Email, Pass = "", ConPass = "";
	bool UserNotFound = true, userNameCorrect = false;
	int myCount;

	//Username:
	cout << "\n\n\t\t\t\t\t\t\t\tPlease enter your Username: ";
user:
	getchar();
	getline(cin, Username);
	myCount = 0;

	//to check special characters:
	for (int i = 0; i < Username.length(); i++) {
		if (Username[i] >= 'a' && Username[i] <= 'z' || Username[i] >= 'A' && Username[i] <= 'Z' || Username[i] >= '0' && Username[i] <= '9' || Username[i] == '@' || Username[i] == '.' || Username[i] == '_' || Username[i] == '-') {
			userNameCorrect = true;
			myCount++;
			continue;
		}
		else if (Username[i] == ' ') {
			userNameCorrect = true;
			myCount++;
			continue;
		}
		else {
			userNameCorrect = false;
			break;
		}
	}

	//to check number of characters
	if (userNameCorrect == false) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\t\tSpecial characters are not allowed! You can only use \'-\' and \'_\'\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your UserName:\t";
		goto user;
	}
	else {
		userNameCorrect = false;
	}
	if (myCount <= 2) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\t\tYour Username must be atleast 3 characters long!\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your UserName:\t";
		goto user;
	}
	else {
		userNameCorrect = false;
	}

	//Email:
	cout << "\n\n\t\t\t\t\t\t\t\tPlease enter a valid Email ID: ";
start:
	getline(cin, Email);
	int addretNo, dotNo;
	bool emailCorrect = false;

	//check if space exist
	for (int i = 0; i <= Email.length(); i++) {
		if (Email[i] == ' ') {
			emailCorrect = false;
			break;
		}
		else {
			emailCorrect = true;
			continue;
		}
	}
	if (emailCorrect == false) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\t\tSpace is not allowed in e-mail.\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) {
		emailCorrect == false;
	}



	//Check for special characters
	for (int i = 0; i < Email.length(); i++) {
		if (Email[i] >= 'a' && Email[i] <= 'z' || Email[i] >= 'A' && Email[i] <= 'Z' || Email[i] >= '0' && Email[i] <= '9' || Email[i] == '@' || Email[i] == '.' || Email[i] == '_' || Email[i] == '-') {
			emailCorrect = true;
			continue;
		}
		else {
			emailCorrect = false;
			break;
		}
	}
	if (emailCorrect == false) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\tSpecial characters are not allowed! You can only use \'-\' and \'_\'\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your Email:\t";
		goto start;
	}
	else if (emailCorrect == true) {
		emailCorrect = false;
	}

	//check for @
	for (int i = 0; i <= Email.length(); i++) {
		if (Email[i] == '@') {
			emailCorrect = true;
			addretNo = i;
			break;
		}
		else {
			emailCorrect = false;
			continue;
		}
	}
	if (emailCorrect == false) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\tYour email is invalid! \'@\' is must in an E-mail Address.\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) {
		emailCorrect == false;
	}

	//check number of characters before @
	int myCounVar = 0;
	for (int i = 0; i <= Email.length(); i++) {
		if (Email[i] == '@') {
			break;
		}
		else {
			myCounVar = myCounVar + 1;
		}
	}
	if (myCounVar++ <= 2) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\tYou must have at least three characters in your E-mail before \'@\'.\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) {
		emailCorrect == false;
	}

	//Check if another @ exist?
	for (int i = addretNo + 1; i <= Email.length(); i++) {
		if (Email[i] == '@') {
			emailCorrect = true;
			break;
		}
		else {
			emailCorrect = false;
			continue;
		}
	}
	if (emailCorrect == true) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\tYour email is invalid! You cannot use more than one \'@\'.\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		emailCorrect == false;
		goto start;
	}

	

	//check if . exist?
	dotNo = 0;
	for (int i = 0; i <= Email.length(); i++) {
		if (Email[i] == '.') {
			emailCorrect = true;
			dotNo = i;
			break;
		}
		else {
			emailCorrect = false;
			continue;
		}
	}
	if (emailCorrect == false) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\tYou havent follow the email rules \'.\' is must!\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) {
		emailCorrect == false;
	}

	//check if another . exist?
	for (int i = dotNo + 1; i <= Email.length(); i++) {
		if (Email[i] == '.') {
			emailCorrect = false;
			break;
		}
		else {
			emailCorrect = true;
			continue;
		}
	}
	if (emailCorrect == false) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\t\tYou cannot use more than one \'.\'!\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (emailCorrect == true) {
		emailCorrect == false;
	}

	//check if email have atleast three characters before '.'
	int count = 0;
	for (int i = addretNo + 1; i < dotNo; i++) {
		count = count + 1;
	}
	if (count <= 2) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\t\tyou must have atleast three characters after \'@\'!\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		emailCorrect = false;
		goto start;
	}
	int anotherCount = 0;
	//check if com exist?
	for (int i = dotNo + 1; i <= Email.length(); i++) {
		anotherCount++;
	}
	if (anotherCount <= 2) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\tYour E-mail must have an high level definition of domain having at least \'3\' characters\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	else if (anotherCount >= 6) {
		Beep(1000, 600);
		cout << "\n\n\t\t\t\t\t\tYour E-mail must have an high level definition of domain having at max \'5\' characters\n";
		cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
		goto start;
	}
	
	check6:
	cout << "\n\n\t\t\t\t\t\t\t\tPlease enter the password that you will use to login: ";
	for (int i = 0; i > -1; i++)
	{
		char temp;
		temp = _getch();
		if (temp != 13 && temp != 8)
		{
			_putch('*');
		}
		if (temp == 13)
		{
			break;
		}
		if (temp == 8 || temp == 127 && !Pass.empty())
		{
			cout << "\b \b";
			Pass.erase(Pass.size() - 1);
		}
		else
			Pass += temp;
	}
	cout << "\n\n\t\t\t\t\t\t\t\tPlease enter your password again for confirmation: ";
	for (int i = 0; i > -1; i++)
	{
		char temp;
		temp = _getch();
		if (temp != 13 && temp != 8)
		{
			_putch('*');
		}
		if (temp == 13)
		{
			break;
		}
		if (temp == 8 || temp == 127 && !ConPass.empty())
		{
			cout << "\b \b";
			ConPass.erase(ConPass.size() - 1);
		}
		else
			ConPass += temp;
	}
	cout << "\n\n";
	if (Pass != ConPass)
	{
		cout << "\n\n\t\t\t\t\t\t\t\tPassword do not match, please try again! ";
		Pass = "";
		ConPass = "";
		goto check6;
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\t\t\tRegistration successful! \n";
		file << Username << "-" << Pass << "-" << Email << "\n";
		file.close();
		cout << "\n\n\t\t\t\t\t\t\t\tLoading"; Sleep(200);
		cout << "."; Sleep(200);
		cout << "."; Sleep(400);
		cout << "."; Sleep(200);
		cout << "."; Sleep(200);
		cout << "."; Sleep(200);
		Sleep(1000);
		Login(c);
	}
}