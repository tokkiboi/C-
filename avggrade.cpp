/*Write a program to input a pin numbers and score for each student from file called grades.txt until the end of file is reached. 
Compute and output the average score. Together then we will add output the pin number, score, and deviation from the average for
 each student.*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>

void getData(
using namespace std;

int main()
{
//Declare variables
//string names;
string names[10];
int pin[10];
int score=[10];
double avg=[0]; 
double sum=[0];
int count;
int i;
char ch='\n';

//Input each number and add it into the sum


//Calculate average
//avg = sum/static_cast<double>(count);

//Output the average
ifstream myFile;
myFile.open ("gradesWithNames.txt");
if (myFile.fail()){cerr << "File is not found\n";}
else {};
//int num=0;
for (i=0; i <count;i++){
//while (getline(myFile,names[10])){
while (!myFile.eof()){
getline (myFile,names[i]);
getData(pin[],i]);
myFile >> score[i];
myFile.get(ch);
//getline (myFile,tempstr);
sum+=score;
avg = sum/(i+1);
cout << "\033[0nName:\t" << names << endl;
cout << "\033[1;32mPIN:\t" << pin << "\tSCORE:\t" << score << endl;
cout << "\033[1;33mSUM:\t" << sum << endl;
cout << "\033[1;33mAVG:\t" << avg << "\033[0m" << endl;
count++;
}
myFile.close();
}
return 0;
}

void getData(pinnum[],num){
for (i=0; i < num; i++){
	myFile >> pinnum[i];
return;
}
}

