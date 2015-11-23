// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 6 - Comparative Cost of Living in US Cities
// Suggested Processes #1 & #2

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
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
		getline (myFile,state_name);
		myFile >> groceries >> housing >> utilities >> transportation >> health >> misc;
		myFile.ignore(100,ch);
		cout << "State Name:\t\t" << state_name << endl;
		cout << "Groceries:\t\t" << groceries << endl;
		cout << "Housing:\t\t" << housing << endl;
		cout << "Utilities:\t\t" << utilities << endl;
		cout << "Transportation:\t\t" << transportation << endl;
		cout << "Health:\t\t\t" << health << endl;
		cout << "Misc:\t\t\t" << misc << endl;
myFile.close();
return 0;
}

/* output
File successfully open.. continuing...
State Name:		Anniston-Calhoun, County, ALt
Groceries:		101.2
Housing:		74.8
Utilities:		111.2
Transportation:		88.8
Health:			89.3
Misc:			96.6
*/
