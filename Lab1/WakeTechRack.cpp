/*Wake Tech Rack is having a t-shirt sale.  This program calculates the
  total price of a sale after the original price of the t-shirt, the
  discount rate and the number of t-shirts ordered.  Output is sent
  both to console and to a text file.*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	ofstream outData;

	const double SHIPPING = 3.99;
	const double TAX_RATE = .07;

	double original_price;
	double discount_rate;
	double sale_price;
	double subtotal;
	double sales_tax;
	double total;

	int number_ordered;

	cout << "Enter original price of t-shirt: ";
	cin >> original_price;

	cout << "Enter discount rate of t-shirt: ";
	cin >> discount_rate;

	cout << "Enter number of t-shirt ordered: ";
	cin >> number_ordered;

	sale_price = original_price - (original_price * discount_rate);
	subtotal = sale_price * number_ordered;
	sales_tax = subtotal * TAX_RATE;
	total = subtotal + sales_tax + SHIPPING;

	cout << fixed << showpoint << setprecision(2);
	cout << endl << "Original price: $" << original_price << endl;
	cout << "Discount rate: " << discount_rate * 100 << "%" << endl;
	cout << "Number ordered: " << number_ordered << endl;
	cout << "Sales price: $" << sale_price << endl;
	cout << "Subtotal: $" << subtotal << endl;
	cout << "Tax: $" << sales_tax << endl;
	cout << "Shipping and handling: $" << SHIPPING << endl;
	cout << "Total payment: $" << total << endl;

	outData.open("Lab1BReceipt.txt");

	outData << fixed << showpoint << setprecision(2);
	outData << endl << "Original price: $" << original_price << endl;
	outData << "Discount rate: " << discount_rate * 100 << "%" << endl;
	outData << "Number ordered: " << number_ordered << endl;
	outData << "Sales price: $" << sale_price << endl;
	outData << "Subtotal: $" << subtotal << endl;
	outData << "Tax: $" << sales_tax << endl;
	outData << "Shipping and handling: $" << SHIPPING << endl;
	outData << "Total payment: $" << total << endl;

	outData.close();
}