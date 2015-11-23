// Alex Kim - 20224753
// Assignment #5
// Visual Studio 2013

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;




int main()
{
int play = 1;
int die1,die2,sum,score;
int maryScore = 0;
int harryScore = 0;
int larryScore = 0;
int harryTurn;

while(play){
        harryScore = harryScore + harryTurn;
        cout << "Harry's running total " << harryScore;
if ((harryScore >= 100) || (maryScore >= 100) || (larryScore >= 100))
    {
    play = 0;
    cout << harryScore;
    }
int harryTurn()
{
    int die1 = (rand() % 6 + 1);
    int die2 = (rand() % 6 + 1);
    int sum = die1 + die2;
    int score = 0;

    if (sum == 7)
        {
            cout << "* You rolled " << die1 << " and " << die2 << " .  That's " << sum << "\n\n" << endl;
            play = 0;
            score = 0;
        }
        if (die1 == die2)
        {
            sum = 13;
        }
        cout << "** Points for turn = " << score << endl;
        return score;
}


