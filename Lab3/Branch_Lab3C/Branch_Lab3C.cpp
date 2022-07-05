#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int numStudents;
	int numExams;
	int examCount;
	int scoreCount;  //count of score entry attempts
	double classAve = 0;
	int studentTotal;
	int score;

	cout << "\nHow many students are in your class? ";
	cin >> numStudents;

	cout << "How many exams did each student complete? ";
	cin >> numExams;

	cout << fixed << showpoint << setprecision(2);
	for (int sCounter = 1; sCounter <= numStudents; sCounter++)
	{
		cout << "\n\nEnter scores for student " << sCounter << ":\n";

		studentTotal = 0;
		scoreCount = 0;
		examCount = 0;
		for (int eCounter = 1; eCounter <= numExams; eCounter++)
		{
			scoreCount++;
			cout << "Score " << scoreCount << ": ";
			cin >> score;
			if ((score >= 0) && (score <= 100))
			{
				studentTotal += score;
				examCount++;
			}
			else
				continue;
		}
		cout << "Average score: " << static_cast<double>(studentTotal) / examCount;
		classAve += static_cast<double>(studentTotal) / examCount;
	}
	cout << "\n\nClass average score is " << classAve / static_cast<double>(numStudents) << "\n\n";
}