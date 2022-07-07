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
	string fname;
	string lname;
	double midterm;
	double final_exam;
	double labs[4];
	double final_score;
};

const int NUMSTUDENTS = 24;
// declare function prototype 
double calculateGrade(Student&, int);
void getData(ifstream& inFile&, Student& students[], int& numStudent);


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

	getData(inFile, students, numStudent);



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
	// close the data file, write your code here
	………


		for (int i = 0; i < numStudent; i++)
		{
			// determine each student’s letter grade (A, B, C, D or F) write your code here
			………


				// display each student’s name, final score and final grade 
					// according to the expected output, write your code here
				………


		}   */
	return 0;
}

void calculateGrade(Student& students, int numStudent)
	{
		// calculate and return student’s final numeric score, write your code here
	………



	}

void getData(ifstream& inFile, Student& students, int& numStudent)
{
	while (inFile)
	{
		inFile >> students[numStudent].fname >> students[numStudent].lname;
		inFile >> students[numStudent].midterm >> students[numStudent].final_exam;
		inFile >> students[numStudent].labs[0] >> students[numStudent].labs[1] >> students[numStudent].labs[2]
			   >> students[numStudent].labs[3];
		numStudent++;
	}
}
