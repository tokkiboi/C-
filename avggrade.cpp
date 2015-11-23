/*Write a program to input a pin numbers and score for each student from file called grades.txt until the end of file is reached. 
Compute and output the average score. Together then we will add output the pin number, score, and deviation from the average for
 each student.*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
//Declare variables
string name;
int pin;
double score=0;
double avg=0; 
double sum=0;
int count;
string tempstr;

//Input each number and add it into the sum


//Calculate average
avg = sum/static_cast<double>(count);

//Output the average
ifstream myFile;
myFile.open ("gradesWithNames.txt");
if (myFile.fail()){cerr << "File is not found\n";}
else {};
int num=0;
while (!myFile.eof()){
getline (myFile,name);
myFile >> pin >> score;
getline (myFile,tempstr);
sum=sum+score;
num++;
}

cout << pin << endl;
cout << sum << endl;
cout << avg << endl;
return 0;
}
