#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int Student::numStudents = 0;

Student::Student()
{
	numStudents++;
	for (int i = 0; i < 4; i++)
	{
		examScores[i] = 0.0;
	}
	firstName = "";
	lastName = "";
	ssNumber = "";
}

Student::Student(string fname, string lname, string ssNum)
{
	numStudents++;
	for (int i = 0; i < 4; i++)
	{
		examScores[i] = 0;
	}

	setFirstName(fname);
	setLastName(lname);
	setSSNum(ssNum);
}

Student::~Student()
{
	numStudents--;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getSSNum()
{
	return ssNumber;
}

double* Student::getScores()
{
	double scores[4];

	
	scores[0] = examScores[0];
	scores[1]= examScores[1];
	scores[2] = examScores[2];
	scores[3]= examScores[3];

	return scores;
}

void Student::setFirstName(string fname)
{
	firstName = fname;
}

void Student::setLastName(string lname)
{
	lastName = lname;
}

void Student::setSSNum(string ssNum)
{
	ssNumber = ssNum;
}

void Student::setScores(double score[])
{

	score[0] = examScores[0];
	score[1] = examScores[1];
	score[2] = examScores[2];
	score[3] = examScores[3];
}

double Student::aveScore()
{
	double total = 0;
	for (int i = 0; i < 4; i++)
	{
		total += examScores[i];
	}

	return total / 4;
}

void Student::studentInfo()
{

	cout << lastName << "  " ;
	cout << firstName << "  ";
	cout << ssNumber << "  " << "\n";

}