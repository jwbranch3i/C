/////////////////////////////////////////////////////////////////////
//
// Filename: Lab5.h
// Date: June 25, 2022
// Programmer: John Branch
//
//////////////////////////////////////////////////////////////////////
#pragma once
#include<string>
using std::string;

namespace gradeOpt
{
	//enum textGrade definition
	enum textGrade { A_PLUS, A, A_MINUS, B_PLUS, B, B_MINUS, C_PLUS, C, C_MINUS, D_PLUS, D, D_MINUS, F };
	///////////////////////////////////////////////////////////////////
	//
	// Function: deriveGrade
	// 
	// Description:
	//		Takes average test score and returns corrosponding textGrade
	//
	// Parameters:
	//		double - average of grades
	//
	// Returns:
	//		textGrade: letter grade that mataches average
	//
	////////////////////////////////////////////////////////////////////
	textGrade deriveGrade(double average)
	{
		textGrade grade;
		if (average < 60)
			grade = F;
		else if (average >= 60 && average < 63)
			grade = D_MINUS;
		else if (average >= 63 && average < 67)
			grade = D;
		else if (average >= 67 && average < 70)
			grade = D_PLUS;
		else if (average >= 70 && average < 73)
			grade = C_MINUS;
		else if (average >= 73 && average < 77)
			grade = C;
		else if (average >= 77 && average < 80)
			grade = C_PLUS;
		else if (average >= 80 && average < 83)
			grade = B_MINUS;
		else if (average >= 83 && average < 87)
			grade = B;
		else if (average >= 87 && average < 90)
			grade = B_PLUS;
		else if (average >= 90 && average < 93)
			grade = A_MINUS;
		else if (average >= 93 && average < 97)
			grade = A;
		else if (average > 97)
			grade = A_PLUS;

		return grade;
	}

	///////////////////////////////////////////////////////////////////
	//
	// Function: convertToLetter
	// 
	// Description:
	//		Takes a textGrade value and returns corresponding string type.
	//
	// Parameters:
	//		textGrade - 
	//
	// Returns:
	//		string - coresponding string type for textGrade
	//
	////////////////////////////////////////////////////////////////////
	string convertToLetter(textGrade grade)
	{
		string gradeStr;
		if (grade == A_PLUS)
			gradeStr = "A+";
		else if (grade == A)
			gradeStr = "A";
		else if (grade == A_MINUS)
			gradeStr = "A-";
		else if (grade == B_PLUS)
			gradeStr = "B+";
		else if (grade == B)
			gradeStr = "B";
		else if (grade == B_MINUS)
			gradeStr = "B-";
		else if (grade == C_PLUS)
			gradeStr = "C+";
		else if (grade == C)
			gradeStr = "C";
		else if (grade == C_MINUS)
			gradeStr = "C-";
		else if (grade == D_PLUS)
			gradeStr = "D+";
		else if (grade == D)
			gradeStr = "D";
		else if (grade == D_MINUS)
			gradeStr = "D-";
		else if (grade == F)
			gradeStr = "F";

		return gradeStr;
	}
}

