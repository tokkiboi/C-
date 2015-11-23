#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
Step 1: Write a program to ask the user for the number of numbers.
Step 2: Then input the numbers.
Step 3: Add summing the values.
Step 4: Add computing the average.
Step 5: Add output to a file
*/

int main()
{
int num; int response; int sum = 0; double avg;

//Number of values to be summed
cout << "Enter the number of numbers: "; 
cin >> num;

//Input the numbers
for (int i = 0; i < num; i++)
{
cin >> response;
sum = sum + response;
}

avg = static_cast<double>(sum) / num;

ofstream fileout;
if (fileout.fail()){cerr << "File could not be open";}
else {
fileout.open("sumavg_output.txt");
fileout << "Sum of values: " << sum << endl;
fileout << "Average: " << avg << endl;
fileout.close();}
// system("pause");
return 0;
}
