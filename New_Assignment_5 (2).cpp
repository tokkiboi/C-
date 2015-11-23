// Alex Kim - 20224753
// Assignment #5
// Visual Studio 2013

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int harryTotalScore = 0, marryTotalScore = 0, larryTotalScore = 0,play = 1,maxroll = 0;
	int die1,die2,score;
	string player = "harry";
	srand(time(NULL));
	//loop to keep playing until someone scores 100+
	if (player == "harry")
	{
	    int die1 = (rand() % 6) + 1;
        int die2 = (rand() % 6) + 1;
        int score = die1 + die2;
        cout << "Harry, it is your turn" << endl;
		cout << "* You rolled " << die1 << " and " << die2 << ".  That's " << score << endl;
        harryTotalScore = harryTotalScore + score;
		if (harryTotalScore >= 100  && score != 7)
        cout << " Harry won the game with " << harryTotalScore << " points" << endl;
        else if (score == 7)
        {
        harryTotalScore = 0;
        player = "marry";
        }
        else
        {
        cout << "** Points for turn = " << score << endl;
		cout << "*** Total points = " << harryTotalScore << "\n" << endl;
		player = "marry";
        }
	}
	if (player == "marry")
    {
        cout << "Marry, it is your turn" << endl;
	    while(play){
            die1 = (rand()%6)+1;
            die2 = (rand()%6)+1;
            score = die1 + die2;
            maxroll++;
            marryTotalScore=marryTotalScore+score;
        if(score == 7){
        cout << "* You rolled " << die1 << " and " << die2 << ".  That's " << score << endl;
        cout << "** Points for turn = " << score << endl;
        play = 0;
        marryTotalScore = 0;
        }
        else if(maxroll == 3){
        cout << "* You rolled " << die1 << " and " << die2 << ".  That's " << score << endl;
        cout << "** Points for turn = " << score << endl;
        play = 0;
        }
        else if(marryTotalScore >= 100){
        cout << "* You rolled " << die1 << " and " << die2 << ".  That's " << score << endl;
        cout << "Marry won the game with " << larryTotalScore << " points\n" << endl;
        cout << "** Points for turn = " << score << endl;
        play = 0;
        }
        cout << "* You rolled " << die1 << " and " << die2 << ".  That's " << score << endl;
        cout << "** Points for turn = " << score << endl;
        cout << "*** Total points = " << marryTotalScore << "\n\n" << endl;
}
    }
		if (player == "larry")
    {
        cout << "Larry, it is your turn" << endl;
	    while(play){
            die1 = (rand()%6)+1;
            die2 = (rand()%6)+1;
            score = die1 + die2;
            larryTotalScore=larryTotalScore+score;
        if(score == 7){
        cout << "* You rolled " << die1 << " and " << die2 << ".  That's " << score << endl;
        cout << "** Points for turn = " << score << endl;
        play = 0;
        larryTotalScore = 0;
        }
        else if(larryTotalScore >= 100){
        cout << "* You rolled " << die1 << " and " << die2 << ".  That's " << score << endl;
        cout << "Larry won the game with " << larryTotalScore << " points\n" << endl;
        cout << "** Points for turn = " << score << endl;
        play = 0;
        }
        cout << "* You rolled " << die1 << " and " << die2 << ".  That's " << score << endl;
        cout << "** Points for turn = " << score << endl;
        cout << "*** Total points = " << larryTotalScore << "\n\n" << endl;
    }
    }
}
