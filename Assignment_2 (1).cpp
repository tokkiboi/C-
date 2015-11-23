// This program will collect different scores acquired from users and calculate,
// and report various types of output generation

#include <iostream>

using namespace std;
int main()
{
	int asone, astwo, asthree, asfour, asfive, assix, asseven;  // declaring 7 different assignment points input from user
	int labttl, ttlasmt, ttlpts, midgrd, fingrd;                // declare int variables to store total lab, total and avg assignment, midterm, final grade
    double  avgasmt, pctttl;                         // declare double int vars to store average and percentage of total points with decimals
	string space;
	space = "   ";

	// Begin prompting for inputting values for each assignments
	cout << "Enter points for Assignment  1 => ";
	cin >> asone;
    cout << "Enter points for Assignment  2 => ";
	cin >> astwo;
	cout << "Enter points for Assignment  3 => ";
	cin >> asthree;
	cout << "Enter points for Assignment  4 => ";
	cin >> asfour;
	cout << "Enter points for Assignment  5 => ";
	cin >> asfive;
	cout << "Enter points for Assignment  6 => ";
	cin >> assix;
	cout << "Enter points for Assignment  7 => ";
	cin >> asseven;
	cout << "Enter total points for Lab Exercises => ";
	cin >> labttl;
	cout << "Enter points for Midterm       => ";
	cin >> midgrd;
	cout << "Enter points for Final         => ";
	cin >> fingrd;
	cout << "\nThe Assignment points are => "
		<< asone << space << astwo << space << asthree
		<< space << asfour << space << asfive << space
		<< assix << space << asseven << endl;

    ttlasmt = asone + astwo + asthree + asfour + asfive + assix + asseven;     // calculating the average of assignments and to print out to display/ printing out the resulting report
    avgasmt = ttlasmt / 7.0;
    ttlpts = ttlasmt + labttl + midgrd + fingrd;
    pctttl = (ttlpts / 400.0) * 100; // declaring a string variable containing 3 spaces to be used between each assignment points display

	cout << "\nThe average assignment grade is => " << avgasmt << endl;
	cout << "\nTotal assignment points    = " << ttlasmt << endl;
	cout << "Lab exercise points        = " << labttl << endl;
	cout << "Midterm points             = " << midgrd << endl;
	cout << "Final points               = " << fingrd << endl;
	cout << "                          --- " << endl;
	cout << "Total Points               = " << ttlpts << endl;
	cout << "                           = " << endl;
	cout << "\nPercent of total (out of 400) = " << pctttl << "%" << endl;
return 0;
}

