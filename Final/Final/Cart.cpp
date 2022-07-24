#include <iostream>
#include <iomanip>
#include <string.h>
#include "Cart.h"
#include "Item.h"

using namespace std;

Cart::Cart(string name)
{
	_name = name;
	_count = 0;
}

bool Cart::purchase(Item item)
{
	if (_count >= 100)
		return false;
	else
	{
		_arr[_count] = item;
		_count++;
	}
	return true;
}

void Cart::PrintTotal()
{
	double total = 0;

	for (int i = 0; i < _count; i++)
	{
		total += _arr[i].getCost();
	}

	cout << fixed << setprecision(2);
	cout << "The total cost of the purchase is: " << total << endl;
}