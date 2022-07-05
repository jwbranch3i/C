/* Lab 02B
  Program caluclates the new salary for an employee based on current salary and
  employment status. */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   double FULLTIME_FACULTY_INCREASE = .03;
   double PART_TIME_FACULTY_INCREASE = 500.;
   double FULLTIME_STAFF_INCREASE = .025;
   double PART_TIME_STAFF_INCREASE = 300.;

   double salary;
   double newSalary = 0.;
   int position;     // faculty or staff
   int full_or_part; // fulltime or part-time

   cout << fixed << showpoint << setprecision(2);
   cout << "Please enter your current salary: ";
   cin >> salary;
   cout << "\nAre you faculty of staff? Enter 1 for faculty and 2 for staff: ";
   cin >> position;

   if (position >= 1 && position <= 2) // valid input
   {
      if (position == 1) // faculty
      {
         cout << "\nAre you fulltime or part-time faculty? Enter 1 for fulltime and 2 for part-time: ";
         cin >> full_or_part;
         if (full_or_part >= 1 && full_or_part <= 2) // valid input
         {
            if (full_or_part == 1) // full time faculty
            {
               newSalary = salary + (salary * FULLTIME_FACULTY_INCREASE);
            }
            else // part-time faculty
            {
               newSalary = salary + PART_TIME_FACULTY_INCREASE;
            }
            cout << "\nYour current salary is: $" << salary;
            cout << "\nYour new salary is: $" << newSalary;
         }
         else
            cout << "\ninvalid input";
      }
      else // staff
      {
         cout << "\nAre you fulltime or part-time staff? Enter 1 for fulltime and 2 for part-time: ";
         cin >> full_or_part;
         if (full_or_part >= 1 && full_or_part <= 2) // valid input
         {
            if (full_or_part == 1) // full time staff
            {
               newSalary = salary + (salary * FULLTIME_STAFF_INCREASE);
            }
            else // part-time staff
            {
               newSalary = salary + PART_TIME_STAFF_INCREASE;
            }
            cout << "\nYour current salary is: $" << salary;
            cout << "\nYour new salary is: $" << newSalary;
         }
         else
            cout << "\ninvalid input";
      }
   }
   else
      cout << "\ninvalid input";
}