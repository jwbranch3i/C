#pragma once
#include "Item.h"
#include<string>
using namespace std;

class Cart
{
public:
    Cart(string);
    bool purchase(item);
    void printTotal();
private:
    string _name;
    int _count;
    Item _arr[100];
};

