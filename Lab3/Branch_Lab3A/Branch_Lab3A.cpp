#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const double SALES_TAX = .06;
const double CHICKEN_PRICE = 4.99;
const double SPICY_CHICKEN_PRICE = 5.29;
const double FISH_PRICE = 5.59;
const double SPICY_FISH_PRICE = 5.99;

int main()
{
	int sandwich_choice = 0;
	double order_total = 0;

	cout << fixed << showpoint << setprecision(2);
	cout << "1 - Original Chicken Sandwich [price: $" << CHICKEN_PRICE << "]\n";
	cout << "2 - Spicy Chicken Sandwich [price: $" << SPICY_CHICKEN_PRICE << "]\n";
	cout << "3 - Original Fish Sandwich [price: $" << FISH_PRICE << "]\n";
	cout << "4 - Spicy Fish Sandwich [price: $" << SPICY_FISH_PRICE << "]\n\n";

	while (sandwich_choice != 99)
	{
		cout << "Enter the number of sandwich [1/2/3/4] or 99 to calculate total: ";
		cin >> sandwich_choice;

		if (sandwich_choice == 1)
			order_total = order_total + CHICKEN_PRICE;
		else if (sandwich_choice == 2)
			order_total = order_total + SPICY_CHICKEN_PRICE;
		else if (sandwich_choice == 3)
			order_total = order_total + FISH_PRICE;
		else if (sandwich_choice == 4)
			order_total = order_total + SPICY_FISH_PRICE;
	}
	cout << "Subtotal: $ " << order_total << "\n";
	cout << "Tax: $ " << order_total * SALES_TAX << "\n";
	cout << "Total: $ " << order_total + (order_total * SALES_TAX);

}