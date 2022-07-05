///////////////////////////////////////////////////////////////
// 
// Filename : Lab04B.cpp
// Date: June 19,2022
// Programmer: John Branch
// 
// Description:
//		This program calculates the total price of a sale after the original
//      price of the t - shirt, the discount rateand the number of t - shirts
//      ordered.Output is sent both to console and to a text file.
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include<iomanip>

using namespace std;

const double SHIPPING = 3.99;
const double TAX_RATE = .07;

// declare function prototypes 
void getInputs(double&, double&, int&);
void calculate(double, double, int, double&, double&, double&, double&);
void display(double, double, int, double, double, double, double);



int main()
{
	char selection = 'Y';

	double original_price;
	double discount_rate;
	double sale_price;
	double subtotal;
	double sales_tax;
	double total;

	int number_ordered;

	while (selection == 'Y' || selection == 'y')
	{
		cout << "\n\nAre you ready for checkout (Y or N)? ";
		cin >> selection;
		if (selection == 'Y' || selection == 'y')
		{
			getInputs(original_price, discount_rate, number_ordered);
			calculate(original_price, discount_rate, number_ordered,
				sale_price, subtotal, sales_tax, total);
			display(original_price, discount_rate, number_ordered,
				sale_price, subtotal, sales_tax, total);
		}
	}
	cout << "\nThanks for using this program!";
	return 0;
}

///////////////////////////////////////////////////////////////
// Function: getInputs
// 
// Description:
//		Asks user to input original price, discount rate, and number
//		of t-shirts ordered.
// 
// Parameters:
//		double - (by reference) original_price
//		double - (by reference) discount rate
//		int - (by reference) number of t_shirs ordered
// 
// Returns:
//		void
// 
///////////////////////////////////////////////////////////////
void getInputs(double& price, double& discount, int& numShirts)
{
	double myPrice;
	double myDiscount;
	int myNumShirts;

	cout << "Enter original price of t-shirt: ";
	cin >> myPrice;

	cout << "Enter discount rate of t-shirt: ";
	cin >> myDiscount;

	cout << "How many t-shirts did you buy? ";
	cin >> myNumShirts;

	price = myPrice;
	discount = myDiscount;
	numShirts = myNumShirts;
}

///////////////////////////////////////////////////////////////
// Function: calculate
// 
// Description:
//		Calculate sales price, subtotal, tax and total amount due
// 
// Parameters:
//		double - original_price
//		double - discount rate
//		int - number of t_shirs ordered
//		double - (by reference) sale price
//		double - (by reference) sub total
//		double - (by reference) sales tax
//		double - (by reference) total amount
// 
// Returns:
//		void
// 
///////////////////////////////////////////////////////////////
void calculate(double price, double discount, int numShirts,
	double& salePrice, double& sTotal, double& tax, double& gTotal)
{
	salePrice = price - (price * discount);
	sTotal = salePrice * numShirts;
	tax = sTotal * TAX_RATE;
	gTotal = sTotal + tax + SHIPPING;
}


	///////////////////////////////////////////////////////////////
	// Function: display
	// 
	// Description:
	//		print sales reciept to output
	// 
	// Parameters:
	//		double - original_price
	//		double - discount rate
	//		int - number of t_shirs ordered
	//		double -  sale price
	//		double -  sub total
	//		double -  sales tax
	//		double -  total amount
	// 
	// Returns:
	//		void
	// 
	///////////////////////////////////////////////////////////////
	void display(double price, double discount, int numShirts,
		double salePrice, double sTotal, double tax, double gTotal)
	{
		cout << fixed << showpoint << setprecision(2);

		cout << "\nOriginal price: $" << price;
		cout << "\nDiscount rate: " << discount * 100 << "%";
		cout << "\nNumber ordered: " << numShirts;
		cout << "\nSales price: $" << salePrice;
		cout << "\nSubtotal: $" << sTotal;
		cout << "\nTax: $" << tax;
		cout << "\nShipping and handling: $" << SHIPPING;
		cout << "\nTotal payment: $ " << gTotal;
	}
