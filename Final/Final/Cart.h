#pragma once
#include "Item.h"
#include<string>
using namespace std;

class Cart
{
public:
    Cart(string);
        //Constructor
        //  Sets name according to parameter.  
        //  Postcondition: _name = name.
    bool purchase(Item);
        //Function to add purchased item to cart.
        //  Postcondition: Item is added to _arr array
    void PrintTotal();
        //Function to print total of all items in _arr array
        //  Postcondition: Total of items is printed.
private:
    string _name;
    int _count;
    Item _arr[100];
};

