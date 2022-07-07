///////////////////////////////////////////////////////////////////////////
// Filename: Lab7.cpp
// Date: July 7 2022
// Programmer: John Branch
// 
// Description:
//		This program reads student's name ans scores from the file "students.txt"
//		The students final grade is calculated based on midterm and final exam averages.
// 
///////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Student
{
	string name;
	double midterm;
	double final_exam;
	double labs[4];
	double final_score;
	string letter_grade;
};

const int NUMSTUDENTS = 24;
// declare function prototype 
void calculateGrade(Student);
Student getData(ifstream&);


int main()
{
	// declare all variables
	Student newStudent;
	Student students[24];
	int numStudent = 0;
	ifstream inFile;
	char letterGrade = ' ';

	// open the data file and check whether the file cannot be found
	inFile.open("students.txt");
	if (!inFile)
	{
		cout << "Cannot open input file." << endl;
		return 1;
	}

	while (inFile)
	{
		newStudent = getData(inFile);

		cout << newStudent.name << endl;
	}


	/*	while (inFile)
		{
			// call calculateGrade function to calculate student’s final numeric score 
				// and update student’s record, write your code here
			………


				// store the current student record in the students array and update numStudent
				// write your code here
				………


				// ignore the ‘\n’ at the end of current student record in the data file 
					// before reading next student record, write your code here
				………



				// read next student record, write your code here
				………


		}
	// close the data file, write your code here  */


	return 0;
}

double calculateGrade(Student students)
{
	double final_grade;
	double lab_ave;
	double lab_total;

	for (int i = 0, i < 4, i++)
	{
		lab_total += students.labs[i];
	}

	lab_ave = (students.final_exam * .25) + (students.midterm * .25) + (lab_total * .5);

	return lab_ave;
}

Student getData(ifstream& inFile)
{
	Student newStudent;
	string trash;

	getline(inFile, newStudent.name);

	inFile >> newStudent.midterm >> newStudent.final_exam;

	inFile >> newStudent.labs[0] >> newStudent.labs[1]
			>> newStudent.labs[2]
			>> newStudent.labs[3];

	inFile >> trash;

	return newStudent;
}
