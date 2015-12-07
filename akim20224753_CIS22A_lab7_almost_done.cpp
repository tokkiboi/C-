// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 7 - Choosing a University

/*	Remove all escape characters beginning with '\033' and ending with 'm' (ex: "\033[1;32m" )
	if on any machine that does not support ANSI color output.. purpose is to output
	in distinct color while debugging */

#include <iostream> // Standard input/output streaming through system
#include <fstream>  // Allow file handling: Input/Output to and from file(s)
#include <string>   // Utilize string variable
#include <cstdlib>  // Required for Exit() function
#include <iomanip>  // Input/Output Formatting library
#define MAX 1000 // Pre-processor global macro to define MAX to have value of 1000

using namespace std;

// FUNCTION PROTOTYPE DECLARATION (FP Declaration)
int getData(ifstream&,string [],string [],string [],double [], int [], double [], double [] );	// FP to store value for number of elements present in array specified
int search(string [],int,string);  // function prototype to search for position of target item
void grab_index(string[], string[], string[], double[], int[], double[], double[],int,string);  // FP to extract and display all information of target item
void compare_tuition(string[],double[],int,double); // FP to seek affordable universities
void output(string [],string [],string [],double[], int[], double[], double[], int); // FP to output		
void sortSelect(string [],string [], string [],int , double [],int [], double [],double []); // FP to sort the arrays
double average_tuition(ifstream&,string [],string [],string [],double [], int [], double [], double [] ); // FP to compute the average tuition for all universities
void signature(); // FP Signature

// FUNCTION MAIN
int main(void)
{
	// declare variables
	ifstream inFile;
	string university[MAX];
	string state[MAX];
	string city[MAX];
	string target;
	double tuition[MAX];
	int enrollment[MAX];
	double retention[MAX];
	double grad[MAX];
	int number; int loc; double afford_tuition;
	// open file
	inFile.open("universities.txt");
	// condition to check if file successfully opens/fails and alert user, otherwise continue
	if (inFile.fail())
	{
		cerr << "No such file was found" << endl;
		//		system("pause");
		system("read -n 1 -s -p \"Press any key to continue...\"\n");
		exit(100);
	}

	// count and store in variable number:  total elemements present in the arrays through calling function getData
	number = getData(inFile, university, state, city, tuition, enrollment, retention, grad);
	double avg_tuition=average_tuition(inFile, university, state, city, tuition, enrollment, retention, grad);
	cout << "Average Tuition of all Universities:\t" << avg_tuition << endl;
	system("read -n 1 -s -p \"Press any key to continue...\"\n");

	// prompt user for particular university(ies) in State input
	cout << "\n\033[1;32mEnter the abbreviated State: \033[0m";
	cin >> target;
	// prompt for maximum affordable tuition to user
// debug: cout << "Looking for Target **" << target << "**" << endl;
	cout << "\n\033[1;32mEnter the affordable tuition: \033[0m";
	cin >> afford_tuition;
	// call search function to find indexed position
	loc = search(state, number, target);
// debug: cout << "\n\033[1;31mAmount of affordable tuition:\033[0m\t" << afford_tuition << endl;
	compare_tuition(university,tuition,number,afford_tuition);  // call function compare_tution to find affordable universities with maximum tuition affordable

	// Condition test through IF-statement, search through index of array to find match target State
	if (loc == -1) 		// If not found alert non-existence of colleges in asked state
		cout << "No colleges in " << target << " state in the list" << endl;
	else{			// otherwise, if found, display all the information for found target by calling function grab_index
	grab_index(university,state,city,tuition,enrollment,retention,grad,number,target);}
	
	//Sort by the average tuition
	sortSelect(university, state, city, number, tuition, enrollment, retention, grad);
	
	//Output each university's name, state, tuition, enrollment, retention, grad
	//	output(university, state, city, tuition, enrollment, retention, grad, number);
// for Windows machines: //system("pause");
	system("read -n 1 -s -p \"Press any key to continue...\"\n");
	signature();
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
	double accept[MAX];
	char ch='\n';
	char blank=' ';
	while (!inFile.eof() && count < MAX)
	{
		getline (inFile,university[count],ch);
		inFile >> setw(2) >> state[count];
		inFile.get(blank);
		getline (inFile,city[count]);
		inFile >> tuition[count] >> enrollment[count] >> accept[count] >> retention[count] >> grad[count];
		inFile.get(ch);
		inFile.get(ch);
		count++;
	}
	return count;
}
// FUNCTION TUITION_AVERAGE
double average_tuition(ifstream& inFile, string university[], string state[], string city[],double tuition[], int enrollment[], double retention[], double grad[])
{
	/*	Pre:		inFile - input file handling passed by reference
				university[] - array of name of universities
				state[] - array of states
				city[] - array of name of the cities
				tuition[] - array of amount of tuition
				enrollment[] - array of enrollment
				retention[] - array of retention percentage rate
				grad[] - array of percentage rate of graduates
		Post:		return the value for average tution
		Purpose:	compute the average tution for all the universities */
	int count = 0;
	double tuition_avg=0;
	double total_tuition=0;
	double accept[MAX];  // declaring to store and negate(ignore) extra data in the data file
	char ch='\n';
	char blank=' ';
	while (!inFile.eof() && count < MAX)
	{
		getline (inFile,university[count],ch);
// debug:	cout << "University:\t" << university[count] << endl;
		inFile >> setw(2) >> state[count];
		inFile.get(blank);
		getline (inFile,city[count]);
		inFile >> tuition[count] >> enrollment[count] >> accept[count] >> retention[count] >> grad[count];
//		inFile.get(ch);
		inFile.get(ch);
		total_tuition += tuition[count];
		count++;
	}
	tuition_avg=total_tuition/count;
	return tuition_avg;
}
// FUNCTION SEARCH
int search(string state[], int num, string target)
{
	/*	Pre:		state[] - array of states where target value is being searched within
				num - number of values to be searched through
				target - specific value being searched for
		Post:		index of where it was found or -1 if not found, if found, position of 'i' in array represents the location found at
		Purpose:	find location of value being searched for */
	int loc = -1;  // -1 in array subscript will return false
	for (int i = 0; i < num; i++) 
	{
		if (state[i] == target)  // check within elements in array of states and see if any match is found
			loc = i;  // return the position where match is found
	}
	return loc; // return index position
}

// FUNCTION GRAB_INDEX
void grab_index(string university[], string state[], string city[], double tuition[], int enrollment[], double retention[], double grad[],int count,string target)
{
        /*      Pre:            inFile - input file handling passed by reference
                                university[] - array of name of universities
                                state[] - array of states
                                city[] - array of name of the cities
                                tuition[] - array of amount of tuition
                                enrollment[] - array of enrollment
                                retention[] - array of retention percentage rate
                                grad[] - array of percentage rate of graduates
                Post:           N/A
                Purpose:        display all the information for each univerisities */

	ofstream fileOut;  // declare output filehandling...
	fileOut.open("lab7_output.txt");  // open file output streaming
	// check success/fail of file opening for output stream, alert when fail and create new file..
	if (fileOut.fail())
		{
			cerr << "File could not be open";
			cout << "Creating a new file...";
			system("touch lab7_output.txt"); // remove and manually create file if on Windows system
		}
	char fill=' ';
	fileOut << "\033[1;31mUniversities found in the state:\033[0m\t" << target << endl;
	for (int i=0; i < count; i++){
		if (state[i] == target){
		fileOut << setprecision(2) << fixed;
// debug:	cout << "\033[1;32mUniversity\t" << "\033[1;33m" << university[i] << endl;
// debug:	fileOut << "\033[1;31mState being searched:\033[0m\t" << state[i] << endl;
// debug"	fileOut << "\033[1;31mTarget being searched:\033[0m\t" << target << endl;
		fileOut << "\033[1;32mUniversity\t" << "\033[1;33m" << university[i] << endl;
		fileOut << setw(5) << "\033[1;32mState\t\t" << "\033[1;33m" << state[i] << "\t\033[1;32mCity\t" << "\033[1;33m" << city[i] << endl;
		fileOut << setw(8) << "\033[1;32mTuition\t\t" << setw(2) << fill << setw(10) << "Enrollment\t" << fill;
		fileOut << setw(13) << "%Fresh Succeed\t" << setw(3) << fill << "%Graduate in six years" << "\033[1;33m\n";
		fileOut << setw(8) << tuition[i] << setw(4) << fill << setw(16) << enrollment[i] << fill << setw(16) << (retention[i]*100);
		fileOut << " %" << setw(19) << fill << right << (grad[i]*100) << " %" << endl;
		}
// debug:	else exit (100);}
	}
}

// FUNCTION COMPARE_TUITION
void compare_tuition(string university[],double tuition[],int count, double target_tuition)
{
	        /*      Pre:            inFile - input file handling passed by reference
	                                university[] - array of name of universities
	                                state[] - array of states
	                                city[] - array of name of the cities
	                                tuition[] - array of amount of tuition
	                                enrollment[] - array of enrollment
	                                retention[] - array of retention percentage rate
	                                grad[] - array of percentage rate of graduates
	                Post:           return the value for average tution
	                Purpose:        compute the average tution for all the universities */

	cout << "\033[1;32mMaximum affordable tuition:\t" << target_tuition << endl;  // debug purpose (Testing)
	for (int i=0; i < count;i++){
		if (tuition[i] <= target_tuition){
			cout << "\033[1;32mAffordable Universities:\n";
			cout << "\033[1;33m" << university[i] << "\033[0m" << endl;}
	}
}
// FUNCTION OUTPUT
void output(string university[], string state[], string city[], double tuition[], int enrollment[], double retention[], double grad[],int count)
{
	        /*      Pre:            university[] - array of name of universities
	                                state[] - array of states
	                                city[] - array of name of the cities
	                                tuition[] - array of amount of tuition
	                                enrollment[] - array of enrollment
	                                retention[] - array of retention percentage rate
	                                grad[] - array of percentage rate of graduates
					count - counter of total elements in array
	                Post:           return the value for average tution
	                Purpose:        compute the average tution for all the universities */
	char fill=' ';
	for (int i = 0; i < count; i++){
		cout << setprecision(2) << fixed;
		cout << "\033[1;32mUniversity\t" << "\033[1;33m" << university[i] << endl;
		cout << setw(5) << "\033[1;32mState\t\t" << "\033[1;33m" << state[i] << "\t\033[1;32mCity\t" << "\033[1;33m" << city[i] << endl;
		cout << setw(8) << "\033[1;32mTuition\t\t" << setw(2) << fill << setw(10) << "Enrollment\t" << fill;
		cout << setw(13) << "%Fresh Succeed\t" << setw(3) << fill << "%Graduate in six years" << "\033[1;33m\n";
		cout << setw(8) << tuition[i] << setw(4) << fill << setw(16) << enrollment[i] << fill << setw(16) << (retention[i]*100);
		cout << " %" << setw(19) << fill << right << (grad[i]*100) << " %" << endl;
		return;
	}
}
// FUNCTION SORTSELECT
void sortSelect(string university[], string state[], string city[], int num, double tuition[], int enrollment[], double retention[], double grad[])
{
	        /*      Pre:            university[] - array of name of universities
	                                state[] - array of states
	                                city[] - array of name of the cities
					num - counter of total elements in array
	                                tuition[] - array of amount of tuition
	                                enrollment[] - array of enrollment
	                                retention[] - array of retention percentage rate
	                                grad[] - array of percentage rate of graduates
	                Post:           N/A
	                Purpose:        sort array by enrollment in ascending order */

	int current; int walker;
	int smallestIndex;
	int temp; 
	for (current = 0; current < num - 1; current++)
	{
		smallestIndex = current;
		for (walker = current; walker < num; walker++)
		{
			if (enrollment[walker] < enrollment[smallestIndex])
				smallestIndex = walker;
		}
		//Swap to position smallest at what is the current position
				temp = enrollment[current];
				enrollment[current] = enrollment[smallestIndex];
				enrollment[smallestIndex] = temp;
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

/* OUTPUT DATA -- Testing 
tokkiboi@voyager~/programming/cpp $ ./a.out 
Average Tuition of all Universities:	nan
Press any key to continue...
Enter the abbreviated State: CA

Enter the affordable tuition: 30000
Maximum affordable tuition:	30000
Affordable Universities:
University of California-Berkeley
Affordable Universities:
University of California-Los Angeles
Affordable Universities:

Press any key to continue...
Student Name:	Alex Kim
E-mail:		alexkim80@gmail.com
Assignment:	Lab 7 - Choosing a University
tokkiboi@voyager~/programming/cpp $ */

/* DATA output to file
tokkiboi@voyager~/programming/cpp $ cat lab7_output.txt 
Universities found in the state:	CA
University	Stanford University
State		CA	City	Stanford
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
44757.00               18136            98.00 %                   96.00 %
University	California Institute of Technology
State		CA	City	Pasadena
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
43362.00                2181            97.00 %                   93.00 %
University	University of California-Berkeley
State		CA	City	Berkeley
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
25064.00               36204            97.00 %                   91.00 %
University	University of California-Los Angeles
State		CA	City	Los Angeles
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
25064.00               42190            97.00 %                   90.00 %
University	University of Southern California
State		CA	City	Los Angeles
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
48280.00               41368            97.00 %                   91.00 %


Student Name:	Alex Kim
E-mail:		alexkim80@gmail.com
Assignment:	Lab 7 - Choosing a University
tokkiboi@voyager~/programming/cpp $  */
