#include <iostream>
#include <string>
#include "Cart.h"
#include "Item.h"

using namespace std;

int main()
{
    char choice = ' ';
    string itemName = "";
    double cost = 0.0;
    bool added;
    Item newItem;

    // create a Cart object
    Cart shoppingCart("My Cart");

    cout << "Would you like to puchase an item from the store (y/n)? ";
    cin >> choice;
    choice = tolower(choice);
    while (choice == 'y')
    {
        cin.ignore();
        cout << "What is the name of the item that you like to purchase? ";
        getline(cin, itemName);
        cout << "What is the cost of the item? ";
        cin >> cost;

        // create an Item object 
        newItem = Item(itemName, cost);
 

        // call cart object’s Purchase function to add item in the cart array
        added = shoppingCart.purchase(newItem);
        if (!added)
        {
            cout << "Error: You have exceeded the limit of allowed purchases." << endl;
            break;
        }
        // ask user to input next purchased item name and cost
        cout << "Would you like to puchase another item from the store (y/n)? ";
        cin >> choice;
        choice = tolower(choice);
    }
    // call cart object’s function to calculate and display total cost
    shoppingCart.PrintTotal();
        return 0;
}
