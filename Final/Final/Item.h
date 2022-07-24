#ifndef ITEM_H
#define ITEM_H

#include<string>
using std::string;

class Item
{
public:
    Item();
        //Default constructor
    Item();
    string getName();
    double getCost();
 private:
    string name;
    double cost;
};

#endif
