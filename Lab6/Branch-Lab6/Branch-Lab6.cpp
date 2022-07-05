////////////////////////////////////////////////////////////////
//
// Filename: Branch-Lab6.cpp
// Date July 1, 2022
// Programmer: John Branch
//
// Description:
//		This program reads data from a text file , job titles and salary data,
//      and performs analytic tasks on the data.
//
/////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int MAXINPUT = 20;
const int LOW = 0;
const int HIGH = 1;

void getNumbers(string workLine, int num[]);

int main()
{
	ifstream infile;
	stringstream ss;

	string workChar;
	string myline;
	string workNum;
	string temp;

	string jobs[MAXINPUT];
	double salaryRanges[MAXINPUT][2];
	double avgSalary[MAXINPUT];

	int lineCt;
	int num[2];
	int minIndex;
	int maxIndex;

	infile.open("job-salaries.txt");
	if (!infile)
	{
		cout << "No file found!";
		return  1;
	}
	cout << setw(35) << left << "Job"
		 << setw(20) << right << "Low Salary"
		 << setw(20) << right << "High Salary"
		 << setw(20) << right << "Average Salary"
		 << endl;
	
	lineCt = 0;
	maxIndex = 1;
	minIndex = 1;
	while (infile && lineCt < MAXINPUT)
	{ 
		getline(infile, myline);
		jobs[lineCt] = myline;

		if (infile)
		{
			getline(infile, myline);

			getNumbers(myline, num);

			salaryRanges[lineCt][LOW] = num[0];
			salaryRanges[lineCt][HIGH] = num[1];
			avgSalary[lineCt] = (salaryRanges[lineCt][LOW] + salaryRanges[lineCt][HIGH]) / 2;

			cout << setw(50) << left << jobs[lineCt] 
				 << setw(20) << salaryRanges[lineCt][LOW] 
				 << setw(20) << salaryRanges[lineCt][HIGH]
				 << setw(20) << avgSalary[lineCt] << endl;

			if (avgSalary[lineCt] > avgSalary[minIndex])
				maxIndex = lineCt;


			if (avgSalary[lineCt] < avgSalary[minIndex])
				minIndex = lineCt;

		}
		lineCt++;
	}


	

	return 0;
}

void getNumbers(string workLine, int num[])
{
	stringstream ss;
	ss << workLine;

	string temp;
	int found;
	int ct;

	ct = 0;
	while (!ss.eof())
	{
		ss >> temp;

		if (stringstream(temp) >> found)
		{
			num[ct] = found;
			ct++;
		}
		temp = "";
	}

}