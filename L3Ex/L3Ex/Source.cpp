#include <iostream>

using namespace std;

int main() {
    double num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "your number: " << num << "\n";
    if (num == 0)
        cout << "your number is zero";
    else if (num > 0)
        cout << "your number is positive";
    else if (num < 0)
        cout << "your number is negative";


    return 0;
}

