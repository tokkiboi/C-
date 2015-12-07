// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 7 - Choosing a University

#include <iostream>
#include <fstream>  // Allow file handling: Input/Output to and from file(s)
#include <string>   // Utilize string variable
#include <cstdlib>  // Required for Exit() function
#include <iomanip>  // Input/Output Formatting library
#define MAX 1000

using namespace std;

// FUNCTION PROTOTYPE DECLARATION
int getData(ifstream&,string [],string [],string [],double [], int [], double [], double [] );		
int search(string [],int,string);
void output(string [],string [],string [],double[], int[], double[], double[], int);			
void sortSelect(string [],string [], string [],int , double [],int [], double [],double []);
double average_tuition(ifstream&,string [],string [],string [],double [], int [], double [], double [] );
void signature();

int main(void)
{
	//Declare variables
	ifstream inFile;
	string university[MAX];
	string state[MAX];
	string city[MAX];
	string target;
	double tuition[MAX];
	int enrollment[MAX];
	double retention[MAX];
	double grad[MAX];
	int number; int loc;
	//Open file
	inFile.open("universities.txt");
	if (inFile.fail())
	{
		cerr << "No such file was found" << endl;
		//		system("pause");
		system("read -n 1 -s -p \"Press any key to continue...\"\n");
		exit(100);
	}
	//Input the entire contents of the university file
	number = getData(inFile, university, state, city, tuition, enrollment, retention, grad);
	system("read -n 1 -s -p \"Press any key to continue...\"\n");
	//Looking for a particular university by State
	cout << "\n\033[1;32mEnter the abbreviated State: \033[0m";
	cin >> target;
	loc = search(state, number, target);

	double avg_tuition=average_tuition(inFile, university, state, city, tuition, enrollment, retention, grad);
	//Condition test through IF-statement, search through index of array to find match target State
	if (loc == -1) // If not found do...
		cout << "No colleges in " << target << " state in the list" << endl;
	else  // otherwise, if found, 
	//	cout << "University:\t" << university[number] << endl;
	//	cout << "State:\t\t" << state[number] << endl;
	//	cout << "City:\t\t" << city[number] << endl;
	//	cout << setprecision(2) << fixed;
	//	cout << "Tuition:\t" << tuition[number] << "\tEnrollment:\t" << enrollment[loc];
	//	cout << "\tRetention:\t" << (retention[number]*100) << " %\t";
	//	cout << "\tGrad:\t\t" << (grad[number]*100) << " %" << endl;
	//	cout << "Average Tuition of all Universities:\t" << avg_tuition << endl;
	output(university, state, city, tuition, enrollment, retention, grad, number);
	
	//Sort by the average tuition
	sortSelect(university, state, city, number, tuition, enrollment, retention, grad);
	//Output each university's name, state, tuition, enrollment, retention, grad
//	output(university, state, city, tuition, enrollment, retention, grad, number);
	//system("pause");
	system("read -n 1 -s -p \"Press any key to continue...\"\n");
	// signature();
	return 0;
}
// FUNCTION GETDATA
int getData(ifstream& inFile, string university[], string state[], string city[],double tuition[], int enrollment[], double retention[], double grad[])
{
	/*	Pre: 		inFile - reference to input file
		university[] - array of university names
		state[] - array of abbreviated states
		tuition[] - array of tuitions
		enrollment[] - array of enrollment
		retention[] =  array of retention
Post:		number of items in stock
Purpose: 	read in information for all universities */
	int count = 0;
	double tuition_avg=0;
	double total_tuition=0;
	double accept[MAX];
	char ch='\n';
	char blank=' ';
	while (!inFile.eof() && count < MAX)
	{
		getline (inFile,university[count],ch);
		cout << "University:\t" << university[count] << endl;
		inFile >> setw(2) >> state[count];
		inFile.get(blank);
		cout << "State:\t\t" << state[count] << endl;
		getline (inFile,city[count]);
		inFile >> tuition[count] >> enrollment[count] >> accept[count] >> retention[count] >> grad[count];
		cout << "City:\t\t" << city[count] << endl;
		cout << setprecision(2) << fixed;
		cout << "Tuition:\t" << tuition[count] << "\tEnrollment:\t" << enrollment[count] << "\tRetention:\t" << (retention[count]*100) << "\tGrad:\t\t" << (grad[count]*100) << endl;
		inFile.get(ch);
		inFile.get(ch);
		//		total_tuition += tuition[count];
		count++;
	}
	//	tuition_avg=total_tuition/count;
	//	cout << "Average of Tuition:\t" << tuition_avg << endl;
	return count;
}
// FUNCTION TUITION_AVERAGE
double average_tuition(ifstream& inFile, string university[], string state[], string city[],double tuition[], int enrollment[], double retention[], double grad[])
{
	 int count = 0;
	 double tuition_avg=0;
	 double total_tuition=0;
	 double accept[MAX];
	 char ch='\n';
	 char blank=' ';
	while (!inFile.eof() && count < MAX)
	{
		getline (inFile,university[count],ch);
		cout << "University:\t" << university[count] << endl;
		inFile >> setw(2) >> state[count];
		inFile.get(blank);
		getline (inFile,city[count]);
		inFile >> tuition[count] >> enrollment[count] >> accept[count] >> retention[count] >> grad[count];
		total_tuition += tuition[count];
		count++;
	}
	tuition_avg=total_tuition/count;
	return tuition_avg;
}
// FUNCTION SEARCH
int search(string state[], int num, string target)
{
	/*	Pre:		arr[] - values being searched
		num - number of values to be searched through
		target - value being searched for
Post:		index of where it was found or -1 if not found
Purpose:	find location of value being searched for*/
	int loc = -1;
	for (int i = 0; i < num; i++)
	{
		if (state[i] == target)
			loc = i;
	}
	return loc;
}
// FUNCTION OUTPUT
void output(string university[], string state[], string city[], double tuition[], int enrollment[], double retention[], double grad[],int count)
{
	char fill=' ';
	for (int i = 0; i < count; i++){
		//cout << university[i] << "   " << state[i] << "   " << city[i] << "   " << tuition[i] << "   " << enrollment[i] << "   " << grad[i] << endl;
		cout << setprecision(2) << fixed;
//		cout << setw(40) << left << "\033[1;31mUniversity" << setw(30) << fill << setw(5) << "State" << setw(1) << fill << setw(8) << "Tuition" << setw(2) << fill << setw(10) << "Enrollment" << fill << setw(13) << "% Fresh Succeed" << setw(3) << fill << "% Graduate in six years" << "\033[0m\n";
		cout << "\033[1;32mUniversity\t" << "\033[1;33m" << university[i] << endl;
		cout << setw(5) << "\033[1;32mState\t\t" << "\033[1;33m" << state[i] << "\t\033[1;32mCity\t" << "\033[1;33m" << city[i] << endl;
//		cout << setw(5) << right << "\033[1;33m" << state[i] << "\t\t" << city[i] << endl;
		cout << setw(8) << "\033[1;32mTuition\t\t" << setw(2) << fill << setw(10) << "Enrollment\t" << fill;
		cout << setw(13) << "%Fresh Succeed\t" << setw(3) << fill << "%Graduate in six years" << "\033[1;33m\n";
		cout << setw(8) << tuition[i] << setw(4) << fill << setw(16) << enrollment[i] << fill << setw(16) << (retention[i]*100);
		cout << " %" << setw(19) << fill << right << (grad[i]*100) << " %" << endl;
//		cout << setw(40) << left << university[i] << setw(30) << fill << setw(5) << right << state[i] << fill << setw(8) << tuition[i] << fill << setw(10) << enrollment[i] << fill << setw(13) << retention[i] << fill << grad[i] << endl;
//		cout << "\n\033[1;33mUniversity:\t" << "\033[1;31m" << university[i] << "\t\033[1;33mState:\t" << "\033[1;31m" << state[i] << "\t\033[1;33mCity:\t" << "\033[1;31m" << city[i];
//		cout << "\t\033[1;33mTuition:\t" << "\033[1;31m" << tuition[i] << "\t\033[1;33mEnrollment:\t" << "\033[1;31m" << enrollment[i] << "\t\033[1;33mRetention:\t" << "\033[1;31m" << (retention[i]*100) << "\t\033[1;33mGrad:\t\t" << "\033[1;31m" << (grad[i]*100) << endl;
//		return;
	}
}
// FUNCTION SORTSELECT
void sortSelect(string university[], string state[], string city[], int num, double tuition[], int enrollment[], double retention[], double grad[])
{
	int current; int walker;
	int smallestIndex;
	//	int temp; 
	//	string temp_university;
	//	string temp_state;
	//	string temp_tuition;
	double tempDbl;
	for (current = 0; current < num - 1; current++)
	{
		smallestIndex = current;
		for (walker = current; walker < num; walker++)
		{
			if (enrollment[walker] < enrollment[smallestIndex])
				smallestIndex = walker;
		}
		//for walker

		//Swap to position smallest at what is the current position
		//		temp = enrollment[current];
		//		enrollment[current] = enrollment[smallestIndex];
		//		enrollment[smallestIndex] = temp;

		//		temp = university[current];
		//		university[current] = university[smallestIndex];
		//		university[smallestIndex] = temp;

		//		temp = state[current];
		//		state[current] = state[smallestIndex];
		//		state[smallestIndex] = temp;
		tempDbl = tuition[current];
		tuition[current] = tuition[smallestIndex];
		tuition[smallestIndex] = tempDbl;
	}
	//for current 
	return;
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
	cout << position3+ "Lab 7 - Choosing a University" << endl;
	ofstream myFileOut("lab7_output.txt",ios::app);
	myFileOut << "\n" << endl;
	myFileOut << position1+ "Alex Kim" << endl;
	myFileOut << position2+ "alexkim80@gmail.com" << endl;
	myFileOut << position3+ "Lab 7 - Choosing a University" << endl;
}
