#ifndef ITEM_H
#define ITEM_H

#include<string>
using std::string;

class Item
{
public:
    Item();
        //Default constructor
        //  sets private member variables to default values
    Item(string, double);
        //Constructor
        //  Sets name and cost according to the parameters.
        //  Postcondition: _name = name; _cost = cost
    string getName();
        //Function to return _name.
        //  Postcondition _name is returned.
    double getCost();
        //Function to return _cost.
        //  Postcondition: The value of _cost is returned.
 private:
    string _name;
    double _cost;
};

#endif
