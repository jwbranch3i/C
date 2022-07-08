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

const int MAXSTUDENTS = 24;

// declare function prototype 
double calculateGrade(Student);
Student getData(ifstream&);
string lGrade(double);


int main()
{
	// declare all variables
	Student newStudent;
	Student students[MAXSTUDENTS];

	ifstream inFile;

	int numStudent = 0;

	double grade;

	// open the data file and check whether the file cannot be found
	inFile.open("students.txt");
	if (!inFile)
	{
		cout << "Cannot open input file." << endl;
		return 1;
	}

	while (inFile && numStudent < MAXSTUDENTS)
	{
		newStudent = getData(inFile);
		newStudent.final_score = calculateGrade(newStudent);
		newStudent.letter_grade = lGrade(newStudent.final_score);

		students[numStudent] = newStudent;
		numStudent++;
	}

	for (int i = 0; i < numStudent; i++)
	{
		cout << students[i].name << "'s final grade is ";
		cout << students[i].final_score << "% (grade: ";
		cout << students[i].letter_grade << ")" << endl;
	}

	inFile.close();
	return 0;
}

string lGrade(double score)
{
	string grade;

	if (score >= 90)
		grade = 'A';
	else if (score >= 80)
		grade = 'B';
	else if (score >= 70)
		grade = 'C';
	else if (score >= 60)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}

double calculateGrade(Student students)
{
	double final_grade;
	double lab_ave;
	double lab_total = 0;

	for (int i = 0; i < 4; i++)
	{
		lab_total += students.labs[i];
	}
	lab_ave = lab_total / 4;

	final_grade = ((students.final_exam * .25) + (students.midterm * .25) + (lab_ave * .5));

	return final_grade;
}

Student getData(ifstream& inFile)
{
	Student newStudent;
	string trash;

	getline(inFile, newStudent.name);

	inFile >> newStudent.midterm >> newStudent.final_exam;
	inFile.ignore();
	inFile >> newStudent.labs[0] >> newStudent.labs[1]
			>> newStudent.labs[2]
			>> newStudent.labs[3];

	inFile.ignore();

	return newStudent;
}
