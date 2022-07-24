#include <string>
#include "Item.h"

using namespace std;

Item::Item()
{
	_name = "";
	_cost = 0.0;
}

Item::Item(string name, double cost)
{
	_name = name;
	_cost = cost;
}

string Item::getName()
{
	return _name;
}

double Item::getCost()
{
	return _cost;
}