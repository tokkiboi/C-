// Page 145 #12
// Alex Kim
// alexkim80@gmail.com

/* LAB 2 - Small Business Taxes:
Write a program that asks for the month, the year, and the total amount collected at the cash register
assuming state sales tax is 5.5% (to be declared in preprocessor directive) and rate of county sales tax at 2.3% as value of a variable declared in local main function
Output is to contain your name printed using cout object
Output is to be copied and pasted as a comment below the source code.
Decimal points must be lined up beautifully as shown in Week 3 notes.
*/

#include <iostream>
#include <string>
#include <iomanip>
// preprocessor declaration of state's sales tax if 5.6%
#define STATE_SALES_TAX 0.056
using namespace std;

int main()
{
	// declare variables for month and year
	string month, fill = "*";
	int year;

	// County Sales Tax is 2.3%
	const double county_sales_tax = 0.023;
	// declare variables to store calculation of sales of the product, amount taxed as state,county, and total amount taxed combined
	double total_amount_collected, sales, stax, ctax, ttax;

	// print to request input from user for month / year / total amount collected
	cout << "Please enter the month: ";
	cin >> month;
	cout << "Please enter the year: ";
	cin >> year;
	cout << "Please enter the total amount collected at the cash register: ";
	cin >> total_amount_collected;

	// calculate and output total amount collected, amount of state tax, amount of county tax, and price of the product
	sales = total_amount_collected / ((STATE_SALES_TAX + county_sales_tax) + 1);
	stax = sales*STATE_SALES_TAX;
	ctax = sales*county_sales_tax;
	ttax = stax + ctax;
	cout << setw(30) << left << "\nMonth:" << setw(13) << right << month << endl;
	cout << setw(30) << left << "Year:" << setw(12) << setprecision(0) << right << year << endl;

	// filling in a line with asterisk for better looking formatting
	cout << setfill('*') << setw(42) << fill << endl;

	// output of the calculated data
	cout << setfill(' ') << setw(30) << left << "Total Collected:" << "$ " << setw(10) << fixed << setprecision(2) << right << total_amount_collected << endl;
	cout << setw(30) << left << "Sales:" << "$ " << setw(10) << setprecision(2) << right << sales << endl;
	cout << setw(30) << left << "County Sales Tax:" << "$ " << setw(10) << setprecision(2) << right << ctax << endl;
	cout << setw(30) << left << "State Sales Tax:" << "$ " << setw(10) << setprecision(2) << right << stax << endl;
	cout << setw(30) << left << "Total Sales Tax:" << "$ " << setw(10) << setprecision(2) << right << ttax << endl;
	cout << setw(30) << left << "\nAlex Kim" << endl;
	system("pause");
	return 0;
}

/* Output of the program
Please enter the month: September
Please enter the year: 2015
Please enter the total amount collected at the cash register: 71678.47

Month:                           September
Year:                                 2015
******************************************
Total Collected:              $   71678.47
Sales:                        $   66430.46
County Sales Tax:             $    1527.90
State Sales Tax:              $    3720.11
Total Sales Tax:              $    5248.01

Alex Kim
Press any key to continue . . .
*/
