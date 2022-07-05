/* Lab 02A
    Given building letter this program will output what campus the building is on*/

#include <iostream>

using namespace std;

int main()
{
    char building;
 
    cout << "Enter the building letter: ";
    cin >> building;

    switch (building)
    {
        case 'R':
            cout << "Location - RTP Campus";
            break;
        case 'A':
        case 'D':
        case 'E':
            cout << "Location - Southern Campus";
            break;
        case 'H':
        case 'I':
        case 'J':
            cout << "Location - Northern Campus";
            break;
        case 'B':
        case 'C':
             cout << "Location - Western Campus";
            break;
        default:
            cout << "Input error.";
    }
}
