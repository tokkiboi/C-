// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 6 - Comparative Cost of Living in US Cities
/*	Write a C++ program to compare cost of living in cities throughout the United States.	*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <climits>

double comp_index(double,double,double,double,double,double);
void signature();

using namespace std;

int main()
{
int count=0;
int max=INT_MAX;
int min=INT_MIN;
string state_name;
double groceries,housing,utilities,transportation,health,misc;
char ch='\n';
	ifstream myFile;
	myFile.open ("costIndex.txt");
		if (myFile.fail())
	{
		cerr << "\033[1;31mFile could not be open\033[0m\n";
		system("read -n 1 -s -p \"Press any key to continue...\"\n" );
		exit(1);
	}
else {cout << "\033[1;31mFile successfully open.. continuing...\033[0m\n";}
	while (!myFile.eof())
	{
		getline (myFile,state_name);
		myFile >> groceries >> housing >> utilities >> transportation >> health >> misc;
		myFile.ignore(100,ch);
		cout << setprecision(1) << fixed << endl;
		cout << "\033[1;32m" << "State Name:\t\t" << state_name << endl;
		cout << "\033[1;33m" << "Groceries:\t\t" << "\033[0m" << groceries << endl;
		cout << "\033[1;33m" << "Housing:\t\t" << "\033[0m" << housing << endl;
		cout << "\033[1;33m" << "Utilities:\t\t" << "\033[0m" << utilities << endl;
		cout << "\033[1;33m" << "Transportation:\t\t" << "\033[0m" << transportation << endl;
		cout << "\033[1;33m" << "Health:\t\t\t" << "\033[0m" << health << endl;
		cout << "\033[1;33m" << "Misc:\t\t\t" << "\033[0m" << misc << endl;
		cout << "\033[1;32m" << "Composition Index:\t" << comp_index(groceries,housing,utilities,transportation,health,misc) << "\033[0m" << endl;
		count++;
	}
myFile.close();
signature();
return 0;
}

double comp_index(double groc,double house,double util,double trans,double hlth,double misc)
{
double index=(0.13*groc)+(0.29*house)+(0.1*util)+(0.12*trans)+(0.12*hlth)+(0.24*misc);
return index;
}

void signature(){
string position1="Student Name:\t";
string position2="E-mail:\t\t";
string position3="Assignment:\t";
cout << "\n" << endl;
cout << position1+ "Alex Kim" << endl;
cout << position2+ "alexkim80@gmail.com" << endl;
cout << position3+ "Lab 6 - Comparative Cost of Living in US Cities" << endl;
}
