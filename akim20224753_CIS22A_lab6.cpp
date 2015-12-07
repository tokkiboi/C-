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
	double c_index=0;
	string state_name,max_string,min_string;
	double groceries,housing,utilities,transportation,health,misc;
	double max;
	double min;
	char ch='\n';
	string str=" ";
	
		// If-Else statement to check success/fail on file open
	ifstream myFileIn("costIndex.txt");
	ofstream myFileOut("lab6_output.txt",ios::out|ios::app);
		if (myFileIn.fail())	
		{
			cerr << "\033[1;31mFile could not be open\033[0m\n";
			system("read -n 1 -s -p \"Press any key to continue...\"\n" );
			exit(1);
		}
		else {cout << "\033[1;31mFile successfully open.. continuing...\033[0m\n";}
	
	// While loop to read in data from file until data input is valid
	
	while (getline(myFileIn,state_name,ch)){
	myFileIn >> groceries >> housing >> utilities >> transportation >> health >> misc;
//cout << state_name << "--" << groceries << "\t" << housing << "\t" << utilities << "\t" << transportation << "\t" << health << "\t" << misc << endl;
	myFileIn.get(ch);
//	getline(myFileIn,str);
        c_index=comp_index(groceries,housing,utilities,transportation,health,misc);
		myFileOut << setprecision(1) << fixed << endl;	// Set output to display 1 digit after decimal point.
		myFileOut << "State Name:\t\t" << state_name << endl;
		myFileOut << "Composite Index:\t" << setw(5) << right << c_index;
		if ((c_index >= max) && (c_index >= min))
		{
			max = c_index;
			min = c_index;
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
		myFileOut << setprecision(1) << fixed;
		myFileOut << "\n";
                myFileOut << "The Min:\t\t" << setw(5) << right <<  min << "\t" << min_string << endl;
                myFileOut << "The Max:\t\t" << setw(5) << right <<  max << "\t" << max_string << endl;
myFileOut.close();
		cout << setprecision(1) << fixed;
		cout << "\n";
		cout << "\033[1;31mThe Min:\t\t" << "\033[0m" << setw(5) << right << min << "\t" << "\033[1;31m" << min_string << "\033[0m" << endl;
                cout << "\033[1;31mThe Max:\t\t" << "\033[0m" << setw(5) << right << max << "\t" << "\033[1;31m" << max_string << "\033[0m" << endl;
signature();
system("read -n 1 -s -p \"Press any key to continue...\"\n");
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
	string position1="Student Name:\t";
	string position2="E-mail:\t\t";
	string position3="Assignment:\t";
	cout << "\n";
	cout << position1+ "Alex Kim" << endl;
	cout << position2+ "alexkim80@gmail.com" << endl;
	cout << position3+ "Lab 6 - Comparative Cost of Living in US Cities" << endl;
ofstream myFileOut("lab6_output.txt",ios::app);
	myFileOut << "\n" << endl;
	myFileOut << position1+ "Alex Kim" << endl;
	myFileOut << position2+ "alexkim80@gmail.com" << endl;
	myFileOut << position3+ "Lab 6 - Comparative Cost of Living in US Cities" << endl;
}

/* OUTPUT
tokkiboi@voyager~/programming/cpp $ ./a.out 
File successfully open.. continuing...


The Min:		 84.0	Pryor, Creek, OK
The Max:		214.2	New, York, (Manhattan), NY

Student Name:	Alex Kim
E-mail:		alexkim80@gmail.com
Assignment:	Lab 6 - Comparative Cost of Living in US Cities
Press any key to continue...
*/
