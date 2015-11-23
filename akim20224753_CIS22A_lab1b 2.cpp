// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 1B

/* Determine the amount of money in dollars in a change purse given the number of quarter, dimes, nickels, and pennies. Prompt the user for the number of each type of coin.
	Test data: 3 quarters, no dimes, 5 nickels, and 23 pennies.
*/

#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
    double qrtr = 0.25;
    double dime = 0.10;
    double nickel = 0.05;
    double penny = 0.01;
	double ttl_money= (3*qrtr) + (0*dime) + (5*nickel) + (23*penny);
	cout << "Total amount of money in dollars in a change purse:\n";
    cout << "$ " << ttl_money;
  return 0;
}

/* Output of the program
Total amount of money in dollars in a change purse:
$ 1.23 
*/
