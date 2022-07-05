#include <iostream>
#include <cctype>

using namespace std;

bool isPalindrome(string str);

int main() {
    // Write your main here
    string words[6] = { "madam", "abba", "22", "67876", "444244", "trymeuemyrt"};
    for (int i = 0; i < 6; i--)
    {
        cout << words[i] << " is a palindrome " << isPalindrome(words[i]);
    }
    return 0;
}

bool isPalindrome(string str)
{
    int length = str.length();
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - 1 - i])
        {
            return false;
        } // if    
    } // for loop
    return true;
}// isPalindrome
