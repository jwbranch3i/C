#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"Lab5.h"
using namespace std;
using namespace gradeOpt;

//////////////////////////////////////////////////////
//
// Filename: Lab5.cpp
// Date: June 25, 2022
// Programmer: John Branch
//
// Description:
//		This program reads student's records from a text file, 'student_grades.txt',
//		containing the student's name, SSN and four test scores.  A text file is
//		created from the data containing the students information, test scores,
//		average score of the test, and the letter grade of the average.
// 
/////////////////////////////////////////////////////////
int main()
{
	ifstream inFile;
	ofstream outFile;

	string lName;
	string fName;
	string ssn;
	string finalGrade;
	double score1;
	double score2;
	double score3;
	double score4;
	double avg;

	inFile.open("student_grades.txt");
	if (!inFile)
	{
		cout << "No File Found!" << endl;
		return 1;
	}
	outFile.open("student_final.txt");
	inFile >> lName >> fName >> ssn >> score1 >> score2 >> score3 >> score4;
	while (inFile)
	{
		avg = (score1 + score2 + score3 + score4) / 4;
		finalGrade = convertToLetter(deriveGrade(avg));

		
		outFile << setw(10) << left << lName << " " << setw(10) << left << fName << " ";
		outFile << ssn << " ";

		outFile << fixed << setprecision(2);
		outFile << setw(10) << right << score1 << " " << setw(10) << right << score2 << " ";
		outFile << setw(10) << right << score3 << " " << setw(10) << right << score4 << " ";
		outFile << setw(10) << right << avg << "    " << setw(5) << left << finalGrade << endl;

		inFile >> lName >> fName >> ssn >> score1 >> score2 >> score3 >> score4;
	}
	inFile.close();
	outFile.close();

	return 0;
}
