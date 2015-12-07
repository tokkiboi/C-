//	Alex Kim - 20224753
//	alexkim80@gmail.com
//	Arrays101
/*	Write a C++ program to read floating point numbers from a file until the end of file.Assume a maximum of 200. Output the entire array.
	Replace any number less than the average with zero and output this new array.*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int getData(double[]);
int main()
{
	//Declare Variables
	int count, counter;
	int i; double avg=0; double array[200];
	double newarray[200];
	char fill = ' ';
	
	count = getData(array);
	cout << endl << "Number of elements: " << count << endl;
	
	//Compute average
	for (i = 0; i < count; i++)
	{
		if (array[i] < avg)
		{
			newarray[i] = 0;
		}
		else
		{
			newarray[i] = array[i];
		}
		avg = (avg + array[i]) / (i + 1);
		cout << setprecision(2) << fixed << endl;
		//cout << setw(20) << left << "Average:" s<< setw(12) << fill << setw(5) << right << avg << endl;
		//cout << setw(20) << left << "Element in array:" << setw(2) << i << setw(10) << fill << setw(5) << right << array[i] << endl;
		//cout << setw(20) << left << "New Array Element:" << setw(2) << i << setw(10) << fill << setw(5) << right << newarray[i] << endl;
		cout << "Average:\t\t\t" << setw(7) << avg << endl;
		cout << "Element in Array:" << "[" << setw(2) << i << "]:\t\t" << setw(7) << array[i] << endl;
		cout << "\n" << setw(5) << fill << "*** " << "New Array: " << "[" << setw(2) << i << "]" << setw(5) << fill << newarray[i] << " ***" << endl;
	}
	cout << "\n***** NEW ARRAY *****" << endl;
	for (counter = 0; counter < count;counter++){
		cout << "Array [" << counter << "]\t" << newarray[counter] << endl;
	}
	//Replace with zero all values less than average
	system("pause");
	return 0;
}//main
 /////////////////////////////////////////////////////////////
int getData(double arr[])
{
	int n = 0;
	ifstream inFile;
	inFile.open("complete.txt");
	if (inFile.fail())
	{
		cout << "No such file" << endl; system("pause"); exit(100);
	}

	while (!inFile.eof())
	{
		inFile >> arr[n];
		n++;
	}
	inFile.close();
	return n;
}