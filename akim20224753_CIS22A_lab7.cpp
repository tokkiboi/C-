// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 7 - Choosing a University

/*	Remove all escape characters beginning with '\033' and ending with 'm' (ex: "\033[1;32m" )
	if on any machine that does not support ANSI color output.. purpose is to output
	in distinct color while debugging */
// debug == uncomment to test values and debug

#include <iostream> // Standard input/output streaming through system
#include <fstream>  // Allow file handling: Input/Output to and from file(s)
#include <string>   // Utilize string variable
#include <cstdlib>  // Required for Exit() function
#include <iomanip>  // Input/Output Formatting library
#include <cctype> // Using to change lowercase input to uppercase
#define MAX 1000 // Pre-processor global macro to define MAX to have value of 1000

using namespace std;

// FUNCTION PROTOTYPE DECLARATION (FP Declaration)
int getData(ifstream&,string [],string [],string [],double [], int [], double [], double [] );	// FP to store value for number of elements present in array specified
int search(string [],int,string);  // function prototype to search for position of target item
int search2(double[],int,double);  // FP to search for subscript of minimum_tuition
void grab_index(string[], string[], string[], double[], int[], double[], double[],int,string);  // FP to extract and display all information of target item
void grab_index2(string[],double[],int,double); // FP to extract and display university name and tuition for university w/ lowest tuition
void compare_tuition(string[],double[],int,double); // FP to seek affordable universities
double lowest_tuition(string[],double[],int,double&);
void output(string [],string [],string [],double[], int[], double[], double[], int); // FP to output		
void sortSelect(string [],string [], string [],int , double [],int [], double [],double []); // FP to sort the arrays
double average_tuition(ifstream&,string [],string [],string [],double [], int [], double [], double [],int); // FP to compute the average tuition for all universities
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
	int low_val;
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
	else
		cout << "File successfully opened for read... continuing ..." << endl;
	// count and store in variable number:  total elemements present in the arrays through calling function getData
	number = getData(inFile, university, state, city, tuition, enrollment, retention, grad);
	// output to file all original array and data information
	output(university, state, city, tuition, enrollment, retention, grad, number);
	// declare avg_tuition to store computed average tuition from calling function average_tuition
	double avg_tuition=average_tuition(inFile,university,state,city,tuition,enrollment,retention,grad,number);
	cout << setprecision(2) << fixed;
	cout << "\n\033[1;31mAverage Tuition of all Universities:\033[0m\t" << "$ " << avg_tuition << endl;
	double low_tuition=lowest_tuition(university,tuition,number,avg_tuition); // grab lowest tuition through calling function lowest_tuition
	//debug:	cout << "LOW_TUITION VALUE:\t" << low_tuition << endl;
	//	cout << "\033[1;32mUniversity with the lowest tuition:\t" << university[low_tuition] << endl;  // debug purpose (Testing) {for (int i=0; i < count;i++){     
	cout << setprecision(2) << fixed;
	//	cout << "\033[1;32mTuition:\033[0m\t\t" << "\033[1;33m" << "$ " << tuition[low_tuition] << "\033[0m" << endl;
	system("read -n 1 -s -p \"Press any key to continue...\"\n");

	// prompt user for particular university(ies) in State input
	cout << "\n\033[1;32mEnter the abbreviated State: \033[0m";
	cin >> target;
	for (int j=0; j < target.length(); ++j) { target[j]=toupper(target[j]); } // change lowercase to uppercase
	// debug: cout << "Looking for Target **" << target << "**" << endl;

	// prompt for maximum affordable tuition to user
	cout << "\n\033[1;32mEnter the affordable tuition: \033[0m";
	cin >> afford_tuition;

	// call search function to find indexed position
	loc = search(state, number, target);
	low_val=search2(tuition,number,low_tuition);
	compare_tuition(university,tuition,number,afford_tuition);  // call function compare_tution to find affordable universities with maximum tuition affordable

	// Condition test through IF-statement, search through index of array to find match target State
	if (loc == -1) 		// If not found alert non-existence of colleges in asked state
		cout << "No colleges in " << target << " state in the list" << endl;
	else{			// otherwise, if found, display all the information for found target by calling function grab_index
		cout << "Found match for state, " << target << " ... continuing to write to file" << endl;
		grab_index(university,state,city,tuition,enrollment,retention,grad,number,target);}
		if (low_val == -1)
			cout << "An error has occurred, no such information found" << endl;
		else{
			cout << "Found match for lowest tutition:\n" << endl;;
			grab_index2(university,tuition,number,low_tuition);}
			// call function sortSelect to sort universities by enrollment
			sortSelect(university, state, city, number, tuition, enrollment, retention, grad);

			//Output each university's name, state, tuition, enrollment, retention, grad
			//output(university, state, city, tuition, enrollment, retention, grad, number);
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
double average_tuition(ifstream& inFile, string university[], string state[], string city[],double tuition[], int enrollment[], double retention[], double grad[],int num)
{
	/*	Pre:		inFile - input file handling passed by reference
		university[] - array of name of universities
		state[] - array of states
		city[] - array of name of the cities
		tuition[] - array of amount of tuition
		enrollment[] - array of enrollment
		retention[] - array of retention percentage rate
		grad[] - array of percentage rate of graduates
		num - number of total elements present passed by value from main - via function getData
Post:		return the value for average tution
Purpose:	compute the average tution for all the universities */
	double total_tuition=0;
	double tuition_avg=0;
	for (int i=0;i<num;i++)
		total_tuition += tuition[i];
	tuition_avg=total_tuition/num;
	// debug:        cout << "Tuition Average for all Universities:\t" << tuition_avg << endl;
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
// FUNCTION SEARCH2
int search2(double tuition[], int num, double min_val)
{
	/*      Pre:            tuition[] - array of tuitions where target value is being searched within
		num - number of values to be searched through
		min_val - target (minimum_tuition value) passed by value 
Post:           index of where it was found or -1 if not found, if found, position of 'y' in array represents the location found at
return the subscript where found
Purpose:        find location of value being searched for */
	int loc = -1;  // -1 in array subscript will return false
	//debug:	cout << "MIN_VAL:\t";
	//debug:	cout << min_val << endl;
	for (int y = 0; y < num; y++) 
	{   
		if (tuition[y] == min_val)  // check within elements in array of tuition and see if any match is found
			loc = y;  // return the position where match is found
	}   
	return loc; // return index position
}

// FUNCTION GRAB_INDEX
void grab_index(string university[], string state[], string city[], double tuition[], int enrollment[], double retention[], double grad[],int count,string target)
{
	/*      Pre:            university[] - array of name of universities
		state[] - array of states
		city[] - array of name of the cities
		tuition[] - array of amount of tuition
		enrollment[] - array of enrollment
		retention[] - array of retention percentage rate
		grad[] - array of percentage rate of graduates
		target - value being searched (abbreciated state)
Post:           N/A
Purpose:        output all the information for matching state */

	ofstream fileOut("lab7_output_indexed.txt",ios::app);
	// check success/fail of file opening for output stream, alert when fail and create new file..
	if (fileOut.fail())
	{
		cerr << "File could not be open";
		cout << "Creating a new file...";
		system("touch lab7_output_indexed.txt"); // remove and manually create file if on Windows system
	}
	else
		cout << "Successfully opened... continuing to write to file... " << endl;
	char fill=' ';
	fileOut << "\n\033[1;31mUniversities found in the state:\033[0m\t" << target << endl;
	for (int i=0; i < count; i++){
		if (state[i] == target){
			fileOut << setprecision(2) << fixed;
			fileOut << "\033[1;32mUniversity\t" << "\033[1;33m" << university[i] << endl;
			fileOut << setw(5) << "\033[1;32mState\t\t" << "\033[1;33m" << state[i] << "\t\033[1;32mCity\t" << "\033[1;33m" << city[i] << endl;
			fileOut << setw(8) << "\033[1;32mTuition\t\t" << setw(2) << fill << setw(10) << "Enrollment\t" << fill;
			fileOut << setw(13) << "%Fresh Succeed\t" << setw(3) << fill << "%Graduate in six years" << "\033[1;33m\n";
			fileOut << setw(8) << tuition[i] << setw(4) << fill << setw(16) << enrollment[i] << fill << setw(16) << (retention[i]*100);
			fileOut << " %" << setw(19) << fill << right << (grad[i]*100) << " %" << endl;}
	}
}
// FUNCTION GRAB_INDEX2
void grab_index2(string university[], double tuition[],int count, double min_val)
{
	/*      Pre:            university[] - array of name of universities
		tuition[] - array of amount of tuition
		count - number of elements in array
Post:           N/A
Purpose:        display university name and tuition for lowest tuition matched */
	for (int z=0;z < count;z++)
	{
		if (tuition[z] == min_val)
		{
			cout << "\nUniversity with the lowest tuition:\t";
			cout << university[z] << "\n" << "Tuition:\t" << tuition[z] << endl;
		}
	}
}

// FUNCTION COMPARE_TUITION
void compare_tuition(string university[],double tuition[],int count, double target_tuition)
{
	/*      Pre:            university[] - array of name of universities
		state[] - array of states
		city[] - array of name of the cities
		tuition[] - array of amount of tuition
		enrollment[] - array of enrollment
		retention[] - array of retention percentage rate
		grad[] - array of percentage rate of graduates
		target_tuition - specific amount of tuition passed as value to be searched in the array of university tuition
Post:           return the list of affordable school names with their tuition
Purpose:        search through list of tuitions list and find tuitions lower than target (affordable tuition) and extract related university name */

	cout << "\n\033[1;32mMaximum affordable tuition:\033[0m\t" << "$ " << target_tuition << endl;  // debug purpose (Testing)
	cout << "\033[1;31mAffordable Universities:\n";
	for (int i=0; i < count;i++){
		if (tuition[i] <= target_tuition){
			//debug:			cout << "\033[1;32mAffordable Universities:\n";
			cout << "\033[1;33m" << university[i] << "\033[0m" << endl;}
	}
}
// FUNCTION LOWEST_TUITION
double lowest_tuition(string university[],double tuition[],int count,double& avg_tuition)
{
	/*      Pre:            university[] - array of name of universities
		tuition[] - array of amount of tuition
		count - total elements in array passed by value
		avg_tuition - value passed by reference reoresenting average of all tuitions
Post:           return the lowest tuition amount
Purpose:        find the lowest tuition amount and university name */
	double min_tuition=avg_tuition;
	string min_university;
	for (int i=0; i < count;i++){
		if ((tuition[i] <= min_tuition) && (tuition[i] > 0)){
			min_tuition=tuition[i];
			min_university=university[i];
		}
		else
			min_tuition=min_tuition;
	}
	//debug:		cout << "\033[1;32mUniversity with lowest tuition:\033[0m\t" << endl;
	//debug:		cout << "\033[1;33m" << min_university << "\033[0m" << endl;
	//debug		cout << "Min_Tuition=\t" << min_tuition << endl;
	return min_tuition;
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
Post:           N/A
Purpose:        output to file all data for each of the universities */
	ofstream fileOut("lab7_output_original.txt",ios::app);
	// check success/fail of file opening for output stream, alert when fail and create new file..
	if (fileOut.fail())
	{
		cerr << "File could not be open";
		cout << "Creating a new file...";
		system("touch lab7_output_original.txt"); // remove and manually create file if on Windows system
	}
	else{
		cout << "Successfully opened... continuing to write to file... " << endl;}
	char fill=' ';
	for (int i = 0; i < count; i++)
	{
		fileOut << setprecision(2) << fixed;
		fileOut << "\033[1;32mUniversity\t" << "\033[1;33m" << university[i] << endl;
		fileOut << setw(5) << "\033[1;32mState\t\t" << "\033[1;33m" << state[i] << "\t\033[1;32mCity\t" << "\033[1;33m" << city[i] << endl;
		fileOut << setw(8) << "\033[1;32mTuition\t\t" << setw(2) << fill << setw(10) << "Enrollment\t" << fill;
		fileOut << setw(13) << "%Fresh Succeed\t" << setw(3) << fill << "%Graduate in six years" << "\033[1;33m\n";
		fileOut << setw(8) << tuition[i] << setw(4) << fill << setw(16) << enrollment[i] << fill << setw(16) << (retention[i]*100);
		fileOut << " %" << setw(19) << fill << right << (grad[i]*100) << " %" << endl;
	}
	fileOut << "\033[1;31m*** END OF ORIGINAL ARRAY LIST ***\n\033[0m" << endl;
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
	int tempI1;
	double tempD1,tempD2,tempD3;
	string tempS1,tempS2,tempS3;
	char fill=' ';
	for (current = 0; current < num - 1; current++)
	{
		smallestIndex = current;
		for (walker = current; walker < num; walker++)
		{
			if (enrollment[walker] < enrollment[smallestIndex])
				smallestIndex = walker;
		}
		//Swap to position smallest at what is the current position
		tempI1 = enrollment[current];
		enrollment[current] = enrollment[smallestIndex];
		enrollment[smallestIndex] = tempI1;
		tempD1 = tuition[current];
		tuition[current] = tuition[smallestIndex];
		tuition[smallestIndex] = tempD1;
		tempD2 = retention[current];
		retention[current] = retention[smallestIndex];
		retention[smallestIndex] = tempD2;
		tempD3 = grad[current];
		grad[current] = grad[smallestIndex];
		grad[smallestIndex] = tempD3;
		tempS1 = university[current];
		university[current] = university[smallestIndex];
		university[smallestIndex] = tempS1;
		tempS2 = state[current];
		state[current] = state[smallestIndex];
		state[smallestIndex] = tempS2;
		tempS3 = city[current];
		city[current] = city[smallestIndex];
		city[smallestIndex] = tempS3;
	}
	ofstream fileOut("lab7_output_sorted.txt",ios::app);
	for (int x=0;x<num;x++)
	{
		fileOut << setprecision(2) << fixed;
		fileOut << "\033[1;32mUniversity\t" << "\033[1;33m" << university[x] << endl;
		fileOut << setw(5) << "\033[1;32mState\t\t" << "\033[1;33m" << state[x] << "\t\033[1;32mCity\t" << "\033[1;33m" << city[x] << endl;
		fileOut << setw(8) << "\033[1;32mTuition\t\t" << setw(2) << fill << setw(10) << "Enrollment\t" << fill;
		fileOut << setw(13) << "%Fresh Succeed\t" << setw(3) << fill << "%Graduate in six years" << "\033[1;33m\n";
		fileOut << setw(8) << tuition[x] << setw(4) << fill << setw(16) << enrollment[x] << fill << setw(16) << (retention[x]*100);
		fileOut << " %" << setw(19) << fill << right << (grad[x]*100) << " %" << endl;
	}
	fileOut << "\033[1;33m*** END OF SORTED ARRAY LIST ***\n\033[0m" << endl;
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
}

/* OUTPUT DATA
tokkiboi@voyager~/programming/cpp $ ./a.out 
File successfully opened for read... continuing ...
Successfully opened... continuing to write to file... 

Average Tuition of all Universities:	$ 42755.07
Press any key to continue...
Enter the abbreviated State: pa

Enter the affordable tuition: 50000

Maximum affordable tuition:	$ 50000.00
Affordable Universities:
Princeton University
Harvard University
Yale University
Stanford University
University of Chicago
Massachusetts Institute of Technology
Duke University
University of Pennsylvania
California Institute of Technology
Dartmouth College
Johns Hopkins University
Northwestern University
Washington University in St. Louis
Cornell University
Brown University
University of Notre Dame
Vanderbilt University
Rice University
University of California-Berkeley
Emory University
Georgetown University
University of California-Los Angeles
University of Virginia
Carnegie Mellon University
University of Southern California

Found match for state, PA ... continuing to write to file
Successfully opened... continuing to write to file... 
Found match for lowest tutition:


University with the lowest tuition:	University of California-Berkeley
Tuition:	25064.00

University with the lowest tuition:	University of California-Los Angeles
Tuition:	25064.00
Press any key to continue...
Student Name:	Alex Kim
E-mail:		alexkim80@gmail.com
Assignment:	Lab 7 - Choosing a University */
