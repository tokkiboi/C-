#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
//Declare variables
int computer, guess;

//Compute computer's number
srand(time(0));
computer = rand() % 100 + 1; 

//Input user's guess
cout << "Enter your guess: (between 1 & 100 inclusive): ";
cin >> guess;

//Does it match?
if (guess == computer)
cout << "Congrats " << endl;
else
cout << "Computer's number was" << computer << endl;

system("pause");
return 0;
}
