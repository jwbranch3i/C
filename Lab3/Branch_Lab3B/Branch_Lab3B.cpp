#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream infile;

    string firstName;
    string lastName;
    string fileName;
    int score;
    int number_of_students = 0;
    int num_odd_scores = 0;
    int sum_odd_scores = 0;
    int num_even_scores = 0;
    int sum_even_scores = 0;
    int highest_score;
    int lowest_score;

    cout << "Welcome to Wake's Grade Book Processing System\n\n";
    cout << "What is the name of your file? ";
    cin >> fileName;

	infile.open(fileName);
    if (!infile)                                  
    {
        cout << "Cannot open the input file." << endl;
        cout << "Program terminates!!!" << endl;
        return 1;
    }

    infile >> firstName >> lastName >> score;
    highest_score = score;
    lowest_score = score;
    while (infile)
    {
        number_of_students++;

        //count and total odd and even scores
        if (score % 2 == 0)
        {
            num_even_scores++;
            sum_even_scores += score;
        }
        else
        {
            num_odd_scores++;
            sum_odd_scores += score;
        }

        // determine high and low scores
        if (highest_score < score)
            highest_score = score;

        if (lowest_score > score)
            lowest_score = score;
        infile >> firstName >> lastName >> score;
    }
    infile.close();

    cout << "\nThe number of students in the file is " << number_of_students << endl;
    cout << "There are " << num_odd_scores << " odd scores and " << num_even_scores << " even scores" << endl;
    cout << "The sum of the odd scores is " << sum_odd_scores << endl;
    cout << "The sum of the even scorse is " << sum_even_scores << endl; 
    cout << "The sum of all teh scores is " << sum_odd_scores + sum_even_scores << endl;
    cout << "The highest score is " << highest_score << endl;
    cout << "The lowest score is " << lowest_score << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "The lowest score is " << (sum_even_scores + sum_odd_scores) / static_cast<double>(number_of_students) << endl;
}