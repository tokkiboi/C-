// This program will collect different scores acquired from users and calculate,
// and report various types of output generation

#include <iostream>
#include <string>

using namespace std;
int main()
{
	int asone, astwo, asthree, asfour, asfive, assix, asseven, aseight, labex, mid, fin;  // declaring 7 different assignment points input from user
	int FinPos,MidPos,AsPos,LabPos,TotPos,fingrd,midgrd,ttlasmt,labttl,ttlpts;
    double  avgasmt, pctttl;                         // declare double int vars to store average and percentage of total points with decimals
	string space;
	space = "   ";

	// Begin prompting for inputting values for each assignments
	cout << "Enter assignment 1 points ";
	cin >> asone;
    cout << "Enter assignment 2 points ";
	cin >> astwo;
	cout << "Enter assignment 3 points ";
	cin >> asthree;
	cout << "Enter assignment 4 points ";
	cin >> asfour;
	cout << "Enter assignment 5 points ";
	cin >> asfive;
	cout << "Enter assignment 6 points ";
	cin >> assix;
	cout << "Enter assignment 7 points ";
	cin >> asseven;
	cout << "Enter assignment 8 points ";
	cin >> aseight;
	cout << "Enter lab exercise points ";
	cin >> labex;
	cout << "Enter midterm points ";
	cin >> mid;
	cout << "Enter final points ";
	cin >> fin;
	cout << "\nAssignment Grades: "
		<< asone << space << astwo << space << asthree
		<< space << asfour << space << asfive << space
		<< assix << space << asseven << space << aseight << endl;

    ttlasmt = asone + astwo + asthree + asfour + asfive + assix + asseven + aseight;
         // calculating the average of assignments and to print out to display/ printing out the resulting report
    ttlpts = ttlasmt + labex + mid + fin;

    pctttl = (ttlpts / 400.0) * 100; // declaring a string variable containing 3 spaces to be used between each assignment points display

    cout << "\nAssignment Points: " << ttlasmt << endl;
	cout << "Lab exercise" << labex << endl;
	cout << "Midterm:" << mid << endl;
	cout << "Final:" << fin << endl;
	cout << "Total Points               = " << ttlpts << endl;
	cout << "                           = " << endl;
	cout << "\nPercent of total (out of 400) = " << pctttl << "%" << endl;
return 0;
}

