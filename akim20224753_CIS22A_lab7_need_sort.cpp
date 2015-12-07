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
void grab_index(string[], string[], string[], double[], int[], double[], double[],int,string);  // FP to extract and display all information of target item
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
//	string min_university="";
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
	double low_tuition=lowest_tuition(university,tuition,number,avg_tuition);
// debug: cout << "\033[1;32mUniversity with the lowest tuition:\t" << min_university << endl;  // debug purpose (Testing) {for (int i=0; i < count;i++){     
	cout << setprecision(2) << fixed;
	cout << "\033[1;32mTuition:\033[0m\t\t" << "\033[1;33m" << "$ " << low_tuition << "\033[0m" << endl;
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
// debug: cout << "\n\033[1;31mAmount of affordable tuition:\033[0m\t" << afford_tuition << endl;

	compare_tuition(university,tuition,number,afford_tuition);  // call function compare_tution to find affordable universities with maximum tuition affordable

	// Condition test through IF-statement, search through index of array to find match target State
	if (loc == -1) 		// If not found alert non-existence of colleges in asked state
		cout << "No colleges in " << target << " state in the list" << endl;
	else{			// otherwise, if found, display all the information for found target by calling function grab_index
	grab_index(university,state,city,tuition,enrollment,retention,grad,number,target);}

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

//debug: uncomment following two lines and comment starting with ofstream to overwrite file
//	ofstream fileOut;  // declare output filehandling...
//	fileOut.open("lab7_output.txt");  // open file output streaming
	ofstream fileOut("lab7_output.txt",ios::app);
	// check success/fail of file opening for output stream, alert when fail and create new file..
	if (fileOut.fail())
		{
			cerr << "File could not be open";
			cout << "Creating a new file...";
			system("touch lab7_output.txt"); // remove and manually create file if on Windows system
		}
		else
			cout << "Successfully opened... continuing to write to file... " << endl;
	char fill=' ';
	fileOut << "\n\033[1;31mUniversities found in the state:\033[0m\t" << target << endl;
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
//debug:	double max_tuition=avg_tuition;
//debug:	cout << "AVERAGE TUITION:\t" << avg_tuition << endl;
//debug:	cout << "Min_Tuition:\t" << min_tuition << endl;
//debug:	cout << "Max_Tuition:\t" << max_tuition << endl;
	string min_university;
	for (int i=0; i < count;i++){
	if ((tuition[i] <= min_tuition) && (tuition[i] > 0)){
//debug		cout << "Tuition:\t" << tuition[i] << endl;
		min_tuition=tuition[i];
		min_university=university[i];
			}
			else
				min_tuition=min_tuition;
		}
		cout << "\033[1;32mUniversity with lowest tuition:\033[0m\t" << endl;
		cout << "\033[1;33m" << min_university << "\033[0m" << endl;
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
	                Post:           return the value for average tution
	                Purpose:        compute the average tution for all the universities */
	 ofstream fileOut("lab7_output.txt",ios::app);
         // check success/fail of file opening for output stream, alert when fail and create new file..
         if (fileOut.fail())
         {
         cerr << "File could not be open";
         cout << "Creating a new file...";
         system("touch lab7_output.txt"); // remove and manually create file if on Windows system
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
	ofstream fileOut("lab7_output.txt",ios::app);
	fileOut << "\n" << endl;
	fileOut << position1+ "Alex Kim" << endl;
	fileOut << position2+ "alexkim80@gmail.com" << endl;
	fileOut << position3+ "Lab 7 - Choosing a University" << endl;
}

/* OUTPUT DATA -- Testing 
tokkiboi@voyager~/programming/cpp $ ./a.out 
File successfully opened for read... continuing ...
Successfully opened... continuing to write to file... 

Average Tuition of all Universities:	$ 42755.07
University with lowest tuition:	
University of California-Los Angeles
Tuition:		$ 25064.00
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

Successfully opened... continuing to write to file... 
Press any key to continue...
Student Name:	Alex Kim
E-mail:		alexkim80@gmail.com
Assignment:	Lab 7 - Choosing a University */


/* DATA output to file
tokkiboi@voyager~/programming/cpp $ cat lab7_output.txt 
University	Princeton University
State		NJ	City	Princeton
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
41820.00                8014            98.00 %                   97.00 %
University	Harvard University
State		MA	City	Cambridge
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
43838.00               19882            97.00 %                   97.00 %
University	Yale University
State		CT	City	New Haven
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
45800.00               12109            99.00 %                   98.00 %
University	Columbia University
State		NY	City	New York			
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
51008.00               23606            99.00 %                   96.00 %
University	Stanford University
State		CA	City	Stanford
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
44757.00               18136            98.00 %                   96.00 %
University	University of Chicago
State		IL	City	Chicago
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
48253.00               12539            99.00 %                   93.00 %
University	Massachusetts Institute of Technology
State		MA	City	Cambridge
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
45016.00               11301            98.00 %                   93.00 %
University	Duke University
State		NC	City	Durham
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
47488.00               15465            97.00 %                   94.00 %
University	University of Pennsylvania
State		PA	City	Philadelphia
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
47668.00               21358            98.00 %                   96.00 %
University	California Institute of Technology
State		CA	City	Pasadena
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
43362.00                2181            97.00 %                   93.00 %
University	Dartmouth College
State		NH	City	Hanover
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
48108.00                6342            98.00 %                   95.00 %
University	Johns Hopkins University
State		MD	City	Baltimore
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
47060.00               21052            97.00 %                   93.00 %
University	Northwestern University
State		IL	City	Evanston
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
47251.00               20997            97.00 %                   94.00 %
University	Washington University in St. Louis
State		MO	City	St. Louis
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
46467.00               14032            97.00 %                   94.00 %
University	Cornell University
State		NY	City	Ithaca
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
47286.00               21593            97.00 %                   93.00 %
University	Brown University
State		RI	City	Providence			
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
47434.00                8943            98.00 %                   94.00 %
University	University of Notre Dame
State		IN	City	Notre Dame			
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
46237.00               12124            98.00 %                   95.00 %
University	Vanderbilt University
State		TN	City	Nashville
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
43838.00               12757            97.00 %                   93.00 %
University	Rice University
State		TX	City	Houston
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
40566.00                6628            97.00 %                   91.00 %
University	University of California-Berkeley
State		CA	City	Berkeley
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
25064.00               36204            97.00 %                   91.00 %
University	Emory University
State		GA	City	Atlanta
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
45008.00               14513            95.00 %                   91.00 %
University	Georgetown University
State		DC	City	Washington
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
46744.00               17849            96.00 %                   92.00 %
University	University of California-Los Angeles
State		CA	City	Los Angeles
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
25064.00               42190            97.00 %                   90.00 %
University	University of Virginia
State		VA	City	Charlottesville
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
42184.00               23464            97.00 %                   93.00 %
University	Carnegie Mellon University
State		PA	City	Pittsburgh
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
48786.00               12991            95.00 %                   88.00 %
University	University of Southern California
State		CA	City	Los Angeles
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
48280.00               41368            97.00 %                   91.00 %
University	
State			City	
Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
    0.00                   0             0.00 %                   0.00 %
    *** END OF ORIGINAL ARRAY LIST ***


    Universities found in the state:	PA
    University	University of Pennsylvania
    State		PA	City	Philadelphia
    Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
    47668.00               21358            98.00 %                   96.00 %
    University	Carnegie Mellon University
    State		PA	City	Pittsburgh
    Tuition		  Enrollment	 %Fresh Succeed	   %Graduate in six years
    48786.00               12991            95.00 %                   88.00 %


    Student Name:	Alex Kim
    E-mail:		alexkim80@gmail.com
    Assignment:	Lab 7 - Choosing a University */
