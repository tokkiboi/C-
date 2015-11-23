// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 6 - Comparative Cost of Living in US Cities
/*	Write a C++ program to compare cost of living in cities throughout the United States.	*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

double comp_index(double,double,double,double,double,double);
void signature();

using namespace std;

int main()
{
	int count=0;
	double c_index;
	double max;
	double min;

string state_name,max_string,min_string;
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
while (getline(myFile,state_name)){
		myFile >> groceries >> housing >> utilities >> transportation >> health >> misc;
		myFile.ignore(100,ch);
		cout << setprecision(1) << fixed << endl;
		cout << "\033[1;32m" << "State Name:\t\t" << state_name << endl;
		cout << "\033[1;33m" << "Groceries:\t\t" << "\033[0m" << setw(5) << right << groceries << endl;
		cout << "\033[1;33m" << "Housing:\t\t" << "\033[0m" << setw(5) << right << housing << endl;
		cout << "\033[1;33m" << "Utilities:\t\t" << "\033[0m" << setw(5) << right << utilities << endl;
		cout << "\033[1;33m" << "Transportation:\t\t" << "\033[0m" << setw(5) << right << transportation << endl;
		cout << "\033[1;33m" << "Health:\t\t\t" << "\033[0m" << setw(5) << right << health << endl;
		cout << "\033[1;33m" << "Misc:\t\t\t" << "\033[0m" << setw(5) << right << misc << endl;
		c_index=comp_index(groceries,housing,utilities,transportation,health,misc);
		cout << "\033[1;32m" << "Composite Index:\t" << setw(5) << right << c_index << endl;
		if ((c_index >= min) && (c_index >= max)){
		max=c_index;
		min=c_index;
		max_string=state_name;}
		else if (c_index <= min){
		min=c_index;
		min_string=state_name;}
		count++;}
myFile.close();
		cout << "\n";
		cout << "\033[1;31mThe Min:\t\t" << "\033[0m" << setw(5) << right << min << "\t" << "\033[1;31m" << min_string << "\033[0m" << endl;
		cout << "\033[1;31mThe Max:\t\t" << "\033[0m" << setw(5) << right << max << "\t" << "\033[1;31m" << max_string << "\033[0m" << endl;
signature();
return 0;
}

double comp_index(double groc,double house,double util,double trans,double hlth,double misc)
{
double index=((0.13*groc)+(0.29*house)+(0.1*util)+(0.12*trans)+(0.12*hlth)+(0.24*misc));
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
