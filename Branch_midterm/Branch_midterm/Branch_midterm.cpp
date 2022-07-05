#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const double MINFEE = 8.00;
const double MINHOURS = 4.0;
const double OVERMIN_CHARGE = 2.50;
const double COMMERCIAL_CHARGE = 10.00;
const double MAX_CHARGE = 60.00;


// declare function prototypes
void getNameAndHours(string&, double&);  // get name and hours parked
bool isCommercial();  
double calcCharges(double, bool);

int main()
{
	string name;
	double hrs_parked;
	double total;
	char answ;
	char comm;

	ofstream outFile;

	bool do_more = true;
	bool commercial;

	cout << "Enter customer data? (Y/N)";
	cin >> answ;
	if (answ == 'N' || answ == 'n')
		do_more = false;

	outFile.open("report.txt");
	outFile << setw(20) << left << "Customer";
	outFile << setw(15) << right << "Hours" << setw(15) << right << "Charge" << setw(15) << right << "Commercial" << endl;

	while (do_more)
	{
		getNameAndHours(name, hrs_parked);
 		commercial = isCommercial();
		if (commercial)
			comm = 'Y';
		else
			comm = 'N';

		total = calcCharges(hrs_parked, commercial);
		
		outFile << fixed << setprecision(2);
		outFile << setw(20) << left << setw(15) << right << name << setw(15) << right << hrs_parked;
		outFile	<< setw(15) << right << total << setw(15) << right << comm << endl;

		cout << "\nEnter more customer data? (Y/N)" ;
		cin >> answ;
		if (answ == 'N' || answ == 'n')
			do_more = false;

	}
	outFile.close();
}


//////////////////////////////////////////////////////////////////////////
//
// Function: getNameAndHours
//
// Description: Ask for customer's full name and number of houirs parked
//		
// Parameters:
//		string - (by reference) name of customer
//		double - (by reference) number of hours parked
//
// Returns:
//		void
//
/////////////////////////////////////////////////////////////////////////////
void getNameAndHours(string& name, double& hours)
{
	string myname;

	std::cin.ignore();
	cout << "Enter Customer Name: ";
	getline (cin, myname);
	cout << "Enter hours parked: ";
	cin >> hours;

	name = myname;

	return;
}

//////////////////////////////////////////////////////////////////////////
//
// Function: isCommercial
//
// Description: ask if vehicle is commercial
//		
// Parameters:
//		None
//
// Returns:
//		bool - true of vehicle is commercial
//
/////////////////////////////////////////////////////////////////////////////
bool isCommercial()
{
	char answ;

	cout << "Is vehicle commercial(Y/N)? ";
	cin >> answ;

	if (answ == 'Y' || answ == 'y')
		return true;
	else
		return false;
}


//////////////////////////////////////////////////////////////////////////
//
// Function: calcCharges
//
// Description: calculates the charge for each customer
//		
// Parameters:
//		double - number of hours parked
//		bool - true of vehicle is commercial
//
// Returns:
//		double - charge for customer
//
/////////////////////////////////////////////////////////////////////////////
double calcCharges(double hours, bool commercial)
{
	double total = MINFEE;

	if (hours > 4.0)
		total += (hours - 4.0) * OVERMIN_CHARGE;

	if (commercial)
		total += COMMERCIAL_CHARGE;

	if (total > 60.0)
		return 60;
	else
		return total;
}



