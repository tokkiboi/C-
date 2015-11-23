// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 6 - Comparative Cost of Living in US Cities
/*	Write a C++ program to compare cost of living in cities throughout the United States.	*/

#include <iostream>
#include <fstream>  // Allow file handling: Input/Output to and from file(s)
#include <string>   // Utilize string variable
#include <cstdlib>  // Required for Exit() function
#include <iomanip>  // Input/Output Formatting library

// FUNCTION PROTOTYPE DECLARATION
double comp_index(double,double,double,double,double,double);
void signature();

using namespace std;

// FUNCTION MAIN
int main()
{
	// Declaring variables
	int count=0;
	double c_index;
	double max;
	double min;
	string state_name,max_string,min_string;
	double groceries,housing,utilities,transportation,health,misc;
	char ch='\n';
	
	// Declare myFile as file handler
	ifstream myFileIn;
	myFileIn.open("costIndex.txt");
	ofstream myFileOut;
	myFileOut.open("costIndex.txt",ios::app);
		
		// If-Else statement to check success/fail on file open
		if (myFileIn.fail())	
		{
			cerr << "\033[1;31mFile could not be open\033[0m\n";
			system("read -n 1 -s -p \"Press any key to continue...\"\n" );
			exit(1);
		}
		else {cout << "\033[1;31mFile successfully open.. continuing...\033[0m\n";}

	// While loop to read in data from file until data input is valid
	while (getline(myFileIn,state_name))
	{
		myFileIn >> groceries >> housing >> utilities >> transportation >> health >> misc;
		myFileIn.ignore(100,ch);	// Clear buffer before transitioning to next getline from cin to rid empty line retrieved
		myFileOut << setprecision(1) << fixed << endl;	// Set output to display 1 digit after decimal point.
		myFileOut << "State Name:\t\t" << state_name << endl;
		myFileOut << "Groceries:\t\t" << "\033[0m" << setw(5) << right << groceries << endl;
		myFileOut << "Housing:\t\t" << "\033[0m" << setw(5) << right << housing << endl;
		myFileOut << "Utilities:\t\t" << "\033[0m" << setw(5) << right << utilities << endl;
		myFileOut << "Transportation:\t\t" << "\033[0m" << setw(5) << right << transportation << endl;
		myFileOut << "Health:\t\t\t" << "\033[0m" << setw(5) << right << health << endl;
		myFileOut << "Misc:\t\t\t" << "\033[0m" << setw(5) << right << misc << endl;
		c_index=comp_index(groceries,housing,utilities,transportation,health,misc);
		myFileOut << "\033[1;32m" << "Composite Index:\t" << setw(5) << right << c_index << endl;

                cout << setprecision(1) << fixed << endl;     // Set output to display 1 digit after decimal point.
                cout << "State Name:\t\t" << state_name << endl;
                cout << "Groceries:\t\t" << "\033[0m" << setw(5) << right << groceries << endl;
                cout << "Housing:\t\t" << "\033[0m" << setw(5) << right << housing << endl;
                cout << "Utilities:\t\t" << "\033[0m" << setw(5) << right << utilities << endl;
                cout << "Transportation:\t\t" << "\033[0m" << setw(5) << right << transportation << endl;
                cout << "Health:\t\t\t" << "\033[0m" << setw(5) << right << health << endl;
                cout << "Misc:\t\t\t" << "\033[0m" << setw(5) << right << misc << endl;
                c_index=comp_index(groceries,housing,utilities,transportation,health,misc);
                cout << "\033[1;32m" << "Composite Index:\t" << setw(5) << right << c_index << endl;
		cout << setprecision(1) << fixed << endl;
		cout << "State Name:\t\t" << state_name << endl;
		cout << "Composite Index:\t" << setw(5) << right << c_index << endl;

		// If statement to declare max composite index/min composite index and corresponding city name
		if ((c_index >= min) && (c_index >= max))
		{
			max=c_index;
			min=c_index;
			max_string=state_name;
		}
		else if (c_index <= min)
		{
			min=c_index;
			min_string=state_name;
		}
		count++;
	}
myFileIn.close();
		cout << "\n";
		myFileOut << "\n";
		myFileOut << "The Min:\t\t" << setw(5) << right <<  min << min_string << endl;
		myFileOut << "The Max:\t\t" << setw(5) << right <<  max << max_string << endl;
		cout << "\033[1;31mThe Min:\t\t" << "\033[0m" << setw(5) << right << min << "\t" << "\033[1;31m" << min_string << "\033[0m" << endl;
		cout << "\033[1;31mThe Max:\t\t" << "\033[0m" << setw(5) << right << max << "\t" << "\033[1;31m" << max_string << "\033[0m" << endl;
myFileOut.close();	// close file
signature();
return 0;
}

// FUNCTION COMP_INDEX
/*	PRE:		Following variables passed by value:
			groc - income spent on Groceries
			house - income spent on Housing
			util - income spent on Utilities
			trans - income spenbt on Transportation
			hlth - income spent on Health
			misc - income spent on Miscellaneous
	POST:		Return the composite index
	PURPOSE:	Compute the composite index */
double comp_index(double groc,double house,double util,double trans,double hlth,double misc)
{
	// Declare variable index to store the composite index
	double index=((0.13*groc)+(0.29*house)+(0.1*util)+(0.12*trans)+(0.12*hlth)+(0.24*misc));
	// return calculated composite index
	return index;
}

// FUNCTION SIGNATURE
void signature()
{
ofstream myFileOut;
	myFileOut.open("costIndex.txt",ios::app);
	string position1="Student Name:\t";
	string position2="E-mail:\t\t";
	string position3="Assignment:\t";
	myFileOut << "\n" << endl;
	myFileOut << position1+ "Alex Kim" << endl;
	myFileOut << position2+ "alexkim80@gmail.com" << endl;
	myFileOut << position3+ "Lab 6 - Comparative Cost of Living in US Cities" << endl;
myFileOut.close();
}

/* OUTPUT */

