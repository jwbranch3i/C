///////////////////////////////////////////////////////////////
// 
// Filename : Lab04A.cpp
// Date: June 19,2022
// Programmer: John Branch
// 
// Description:
//		This code caclulates the 2-point and 3-point percentages for a basketball
//		player's recent NBA game based on the number of total shots attempted
//		and total shots made.
// 
///////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

// declare function prototypes
int get2ptsMade();
int get3ptsMade();
int get2ptsAttempted();
int get3ptsAttempted();
double calc2ptsPercent(int, int);
double calc3ptsPercent(int, int);
bool IsBetterThanChance(double);



int main()
{
	int two_pts_made;
	int two_pts_attempted;
	int three_pts_made;
	int three_pts_attempted;
	double two_pt_percent;
	double three_pt_percent;
	bool two_pt_result;
	bool three_pt_result;

	two_pts_made = get2ptsMade();
	two_pts_attempted = get2ptsAttempted();
	three_pts_made = get3ptsMade();
	three_pts_attempted = get3ptsAttempted();

	two_pt_percent = calc2ptsPercent(two_pts_made, two_pts_attempted);
	three_pt_percent = calc3ptsPercent(three_pts_made, three_pts_attempted);

	two_pt_result = IsBetterThanChance(two_pt_percent);
	three_pt_result = IsBetterThanChance(three_pt_percent);


	if (two_pt_result)
		cout << "This player made 50% or above for his 2-point shots.";
	else
		cout << "This player made less than 50% for his 2-point shots.";

	if (three_pt_result)
		cout << "\nThis player made 50% or above for his 3-point shots.";
	else
		cout << "\nThis player made less than 50% for his 3-point shots.";

	return 0;
}

///////////////////////////////////////////////////////////////
// Function: get2ptsMade()
// 
// Description:
//		Ask for and inputs the number of two point shots made
// 
// Parameters:
//		None
// 
// Returns:
//		returnVal: numnber of two point shots made
// 
///////////////////////////////////////////////////////////////
int get2ptsMade()
{
	int points;

	cout << "Enter the player's number of 2-point made: ";
	cin >> points;
	return points;
}

///////////////////////////////////////////////////////////////
// Function: get3ptsMade()
// 
// Description:
//		Ask for and inputs the number of three point shots made
// 
// Parameters:
//		None
// 
// Returns:
//		returnVal: numnber of three point shots made
// 
///////////////////////////////////////////////////////////////
int get3ptsMade()
{
	int points;

	cout << "Enter the player's number of 3-point made: ";
	cin >> points;
	return points;
}

///////////////////////////////////////////////////////////////
// Function: get2ptsAttempted()
// 
// Description:
//		Ask for and inputs the total number of two point shots attempted
// 
// Parameters:
//		None
// 
// Returns:
//		returnVal: numnber of two point shots attempted
// 
///////////////////////////////////////////////////////////////
int get2ptsAttempted()
{
	int points;

	cout << "Enter the player's number of 2-point attempted: ";
	cin >> points;
	return points;
}

///////////////////////////////////////////////////////////////
// Function: get3ptsAttempted()
// 
// Description:
//		Ask for and inputs the total number of three point shots attempted
// 
// Parameters:
//		None
// 
// Returns:
//		returnVal: numnber of three point shots attempted
// 
///////////////////////////////////////////////////////////////
int get3ptsAttempted()
{
	int points;

	cout << "Enter the player's number of 2-point attempted: ";
	cin >> points;
	return points;
}

///////////////////////////////////////////////////////////////
// Function: calc2ptsPercent(int, int)
// 
// Description:
//		Calculates the percentage of 2-point made
// 
// Parameters:
//		int - number of 2-point made
//		int - number of 2-point attempted
// 
// Returns:
//		returnVal: double - percentage of 2-point made
// 
///////////////////////////////////////////////////////////////
double calc2ptsPercent(int ptsMade, int ptsAttempt)
{
	double percent;

	percent = static_cast<double>(ptsMade) / ptsAttempt;
		return percent * 100;
}

///////////////////////////////////////////////////////////////
// Function: calc3ptsPercent(int, int)
// 
// Description:
//		Calculates the percentage of 2-point made
// 
// Parameters:
//		int - number of 3-point made
//		int - number of 3-point attempted
// 
// Returns:
//		returnVal: double - percentage of 3-point made
// 
///////////////////////////////////////////////////////////////
double calc3ptsPercent(int ptsMade, int ptsAttempt)
{
	double percent;

	percent = static_cast<double>(ptsMade) / ptsAttempt;
	return percent * 100;
}

///////////////////////////////////////////////////////////////
// Function: IsBetterThanChance(double)
// 
// Description:
//		Calculates if player made more or less of shots attempted
// 
// Parameters:
//		double - percentage of points made / points attempted
// 
// Returns:
//		returnVal: bool - true if player made 50% or above, fales otherwise
// 
///////////////////////////////////////////////////////////////
bool IsBetterThanChance(double stat)
{
	if (stat >= 50)
		return true;
	else
		return false;
}
