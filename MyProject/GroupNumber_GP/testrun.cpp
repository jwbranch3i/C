#include <iostream>
#include "Student.h"
#include "ClassRoom.h"

using namespace std;

int main()
{
	ClassRoom room("CSC130");

	room.readStudents();
	room.listStudents();
	cout << "\n\n";

	room.sortbyAvg();
	room.listStudents();
	cout << "\n\n";

	room.sortbyName();
	room.listStudents();
	cout << "\n\n";

	cout << "Number of students in class " << room.getNumberOfStudents() << "\n\n";
	cout << "Class average " << room.classAvg() << "\n\n";

}