#include <iostream>
#include <string>
#include <fstream>
#include "ClassRoom.h"
#include "Student.h"
#include "ClassRoom.h"

using namespace std;

ClassRoom::ClassRoom()
{
	className = "";
	numStudents = 0;
}

ClassRoom::ClassRoom(string name)
{
	className = name;
	numStudents = 0;
}

int ClassRoom::getNumberOfStudents()
{
	return numStudents;
}

double ClassRoom::classAvg()
{
	double total;

	total = 0;
	for (int i = 0; i < getNumberOfStudents(); i++)
	{
		total += regStudent[i].aveScore();
	}
	return total / getNumberOfStudents();
}

void ClassRoom::readStudents()
{
	ifstream inFile;

	string lname;
	string fname;
	string ssNum;
	double score1;
	double score2;
	double score3;
	double score4;

	int count = 0;

	inFile.open("studentinfo.txt");
	if (!inFile)
	{
		cout << "Cannot open input file." << endl;
		return;
	}

	while (inFile && count < 20)
	{
		inFile >> lname >> fname >> ssNum >> score1 >> score2 >> score3 >> score4;
		regStudent[count] = Student(fname, lname, ssNum, score1, score2, score3, score4);
		count++;
	}
	numStudents += count - 1;
}

void ClassRoom::listStudents()
{
	for (int i = 0; i < numStudents; i++)
	{
		regStudent[i].studentInfo();
	}

}

void ClassRoom::sortbyAvg()
{
	studentSort( 1 );
}

void ClassRoom::sortbyName()
{
	studentSort( 2 );
}

void ClassRoom::studentSort(int sortType)
{
	string temp1;
	string temp2;

	int index;
	int smallestIndex;
	int location;
	Student temp;

	for (index = 0; index < getNumberOfStudents() - 1; index++)
	{
		smallestIndex = index;

		for (location = index + 1; location < getNumberOfStudents(); location++)
		{
			if (sortType == 1)
			{
				if (regStudent[location].aveScore() < regStudent[smallestIndex].aveScore())
					smallestIndex = location;
			}
			else if (sortType == 2)
			{
				temp1 = regStudent[location].getLastName();
				temp2 = regStudent[smallestIndex].getLastName();

				if (regStudent[location].getLastName() < regStudent[smallestIndex].getLastName())
					smallestIndex = location;
			}
			else
				return;
		}

		temp = regStudent[smallestIndex];
		regStudent[smallestIndex] = regStudent[index];
		regStudent[index] = temp;

	}
}