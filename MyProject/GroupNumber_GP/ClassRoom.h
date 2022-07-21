#pragma once
#include <string>
#include "Student.h"

using namespace std;

class ClassRoom
{
public:
	ClassRoom();
	ClassRoom(string);

	int getNumberOfStudents();
	double classAvg();
	void readStudents();
	void listStudents();
	void sortbyAvg();
	void sortbyName();

private:
	int numStudents;
	string className;
	void studentSort(int);
	Student regStudent[20];

};
