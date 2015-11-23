// Alex Kim - 20224753
// Assignment #5
// Visual Studio 2013

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int dieRoll();
int harryTurn(int);
int marryTurn(int);
int larryTurn(int);

int main()
{
	int harryTotalScore = 0, marryTotalScore = 0, larryTotalScore = 0;
	srand(time(NULL));
	do
	{
		harryTotalScore = harryTotalScore + harryTurn(harryTotalScore); //add the score from a new turn to the running total
		cout << "Your total score so far is " << harryTotalScore << "." << endl;
		if(harryTotalScore >= 100)
		{
			cout << " Harry won the game with " << harryTotalScore << " points" << endl;
			return 0;
		}
		marryTotalScore = marryTotalScore + marryTurn(marryTotalScore); //add the score from a new turn to the running total
		cout << "Marry total score so far is " << marryTotalScore << "." << endl;
		if(marryTotalScore >= 100)
		{
			cout << " Marry won the game with " << harryTotalScore << " points" << endl;
			return 0;
		}
		larryTotalScore = larryTotalScore + larryTurn(larryTotalScore); //add the score from a new turn to the running total
		cout << "Larry total score so far is " << larryTotalScore << "." << endl;
		if(larryTotalScore >= 100)
		{
			cout << " Larry won the game with " << harryTotalScore << " points" << endl;
			return 0;
        }
    }while(harryTotalScore < 100 && marryTotalScore < 100 && larryTotalScore < 100);
}
int dieRoll()
{
	return (rand() % 6) + 1; //call to rand() returns 0-5, + 1 to give range 1-6, best way to avoid impossible die roll of 0
}

int harryTurn(int harryTotalScore)
{
	int thisTurnScore = 0, score = 0;
	do
	{
		score = dieRoll(); //roll the die
		if(score == 1)
		{
			cout << "You rolled a 1.  End of turn." << endl;
			return 0;
		}
    }yes
		while(thisTurnScore < 20);
		thisTurnScore = thisTurnScore + score; //running total for this turn only

		cout << "You rolled a " << score << ".  Score so far this turn is " << thisTurnScore << "." << endl;
    return thisTurnScore; //finsh turn and return total score if player chooses to Hold
}
int marryTurn(int marryTotalScore)
{
	int thisTurnScore = 0, score = 0;
	do
	{
		score = dieRoll(); //roll the dice
		if(score == 7)
		{
			cout << "marry rolled " << score << endl;
			return 0;
		}
		thisTurnScore = thisTurnScore + score; //running total for this turn only
		return thisTurnScore;
	}
}
int larryTurn(int larryTotalScore)
{
	int thisTurnScore = 0, score = 0;

	//loop to keep going as long the CPU score for this turn is less than 20
	do
	{
		score = dieRoll(); //roll the dice

		if(score == 1)
		{
		cout << "larry rolled " << score << endl;
			return 0;
		}
		thisTurnScore = thisTurnScore + score; //running total for this turn only
	}
	while(thisTurnScore < 20);

}
