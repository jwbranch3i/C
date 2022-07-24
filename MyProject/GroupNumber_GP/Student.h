#pragma once
#include <string>

using namespace std;

class Student
{
	public:
		Student();

		Student(string, string, string, double, double, double, double);		~Student();
		string getFirstName();
		string getLastName();
		string getSSNum();
		double* getScores();

		void setFirstName(string);
		void setLastName(string);
		void setSSNum(string);
		void setScores(double scores[]);

		double aveScore();
		void studentInfo();
		int numberOfStudents();
	private:
		string firstName;
		string lastName;
		string ssNumber;
		double examScores[4];
		static int numStudents;
};
