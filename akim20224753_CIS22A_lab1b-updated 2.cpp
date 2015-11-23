// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 1B

/* Determine the amount of money in dollars in a change purse given the number of quarter, dimes, nickels, and pennies. Prompt the user for the number of each type of coin.
	Test data: 3 quarters, no dimes, 5 nickels, and 23 pennies.
*/

#include <iostream>
#include <cstdlib>

// define values for each variables for Quarters, Dimes, Nickels, Pennies
#define qrtr 0.25
#define dime 0.10
#define nickel 0.05
#define penny 0.01
using namespace std;


int main()
{
// declare variables as integers for total quantities of each coins
	int ttl_qrtr,ttl_dime,ttl_nickel,ttl_penny;
// print text to request total quantities per each coins to be input
	cout << "Please enter the quantities of Quarters:\t";
	cin >> ttl_qrtr;
	cout << "Please enter the quantities of Dimes:\t\t";
	cin >> ttl_dime;
	cout << "Please enter the quantities of Nickels:\t\t";
	cin >> ttl_nickel;
	cout << "Please enter the quantities of Pennies:\t\t";
	cin >> ttl_penny;
// declare variable ttl_money as double to hold the sum of calculation per each coins and their quantities and retain values after the decimal point

	double ttl_money= (ttl_qrtr*qrtr) + (ttl_dime*dime) + (ttl_nickel*nickel) + (ttl_penny*penny);
	cout << "\nTotal amount of money in dollars in a change purse:\n";
    cout << "$ " << ttl_money;
	cout << "\n\nAlex Kim" << endl;
	system("pause");
  return 0;
}

/* Output of the program
Please enter the quantities of Quarters:	3
Please enter the quantities of Dimes:		0
Please enter the quantities of Nickels:		5
Please enter the quantities of Pennies:		23

Total amount of money in dollars in a change purse:
$ 1.23

Alex Kim 
Exit code: 0 (normal program termination)
*/
