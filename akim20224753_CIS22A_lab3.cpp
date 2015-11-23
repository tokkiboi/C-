// Alex Kim
// alexkim80@gmail.com

/* LAB 3 - TV / VCR Problem
Write a program to create a customer's bill for a company that sells only five products: \
TV,DVD player, Remote Controller, CD Player, and Audio Visual Processor.\
Given the unit price per each product, ask for quantities of each item from the user\
and calculate the subtotal for each items for output including subtotal and tax of the subtotal and lastly the total bill.
*/

#include <iostream> // fundamental library needed for input output
#include <string>  // to handle string values
#include <iomanip> // to allow usage of setw() / setprecision() etc for formatting

// Defining the tax rate of 8.75% (Cupertino) in preprocessor directive
#define TAX_RATE 0.0875
using namespace std;

int main()
{
	// declare memory constant for each unit price
	const double tv_p = 500.00;
	const double dvd_p = 380.00;
	const double rmt_p = 35.20;
	const double cdp_p = 74.50;
	const double avp_p = 1500.00;
	string fill = "";
	// declare integer variables of quantities per product to be stored from user input
	int tv_q, dvd_q, rmt_q, cdp_q, avp_q;

	// prompt for user input for the quantities of each product and store accordingly
	cout << "How many TVs were sold? ";
	cin >> tv_q;
	cout << "How many DVD players were sold? ";
	cin >> dvd_q;
	cout << "How many Remote Controller units were sold? ";
	cin >> rmt_q;
	cout << "How many CD Players were sold? ";
	cin >> cdp_q;
	cout << "How many AV Processors were sold? ";
	cin >> avp_q;
	
	// declare and calculate subtotal of each product and the subtotal of the bill
	double sub_tv = tv_p * tv_q;
	double sub_dvd = dvd_p * dvd_q;
	double sub_rmt = rmt_p * rmt_q;
	double sub_cdp = cdp_p * cdp_q;
	double sub_avp = avp_p * avp_q;
	double sub_ttl = sub_tv + sub_dvd + sub_rmt + sub_cdp + sub_avp;
	double tax_sub_ttl = TAX_RATE * sub_ttl;
	double bill_ttl = sub_ttl + tax_sub_ttl;


	// setting the width of the output display as 55 and instructing to output of monetary values to have 2 decimal points only
	cout << setw(3) << left << "\nQTY" << setw(2) << fill << setw(20) << left << "Description" << setw(10) << fill << setw(19) << left << "Unit Price" << setw(5) << fill << setw(25) << left << "Total Price" << endl; 

	// format the output for better visual output as instructed
	// cout << setfill(' ') << setw(30) << left << "Total Collected:" << "$ " << setw(10) << fixed << setprecision(2) << right << total_amount_collected << endl;
	cout << fixed << setprecision(2);
	// cout << setw(2) << right << tv_q << setw(3) << left << fill << "TV" << setw(27) << right << tv_p << setw(13) << left << fill << setw(8) << right << sub_tv << endl;
	cout << setw(2) << right << tv_q << setw(3) << fill << setw(20) << left << "TV" << setw(10) << fill << setw(8) << right << tv_p << setw(15) << fill << setw(9) << right << sub_tv << endl;
	cout << setw(2) << right << dvd_q << setw(3) << fill << setw(20) << left << "DVD" << setw(10) << fill << setw(8) << right << dvd_p << setw(15) << fill << setw(9) << right << sub_dvd << endl;
	cout << setw(2) << right << rmt_q << setw(3) << fill << setw(20) << left << "REMOTE CONTROLLER" << setw(10) << fill << setw(8) << right << rmt_p << setw(15) << fill << setw(9) << right << sub_rmt << endl;
	cout << setw(2) << right << cdp_q << setw(3) << fill << setw(20) << left << "CD PLAYER" << setw(10) << fill << setw(8) << right << cdp_p << setw(15) << fill << setw(9) << right << sub_cdp << endl;
	cout << setw(2) << right << avp_q << setw(3) << fill << setw(20) << left << "AV PROCESSOR" << setw(10) << fill << setw(8) << right << avp_p << setw(15) << fill << setw(9) << right << sub_avp << endl;
	cout << endl;
	cout << setw(38) << right << "SUBTOTAL" << setw(10) << fill << setw(9) << right << sub_ttl << endl;
	cout << setw(38) << right << "TAX" << setw(10) << fill << setw(9) << right << tax_sub_ttl << endl;
	cout << setw(38) << right << "TOTAL" << setw(10) << fill << setw(9) << right << bill_ttl << endl;
	cout << "\nAlex Kim" << endl;
	system("pause");
	return 0;
}

/* Output of the program
How many TVs were sold? 13
How many DVD players were sold? 2
How many Remote Controller units were sold? 0
How many CD Players were sold? 1
How many AV Processors were sold? 21

QTY  Description                   Unit Price              Total Price
13   TV                              500.00                 6500.00
2   DVD                             380.00                  760.00
0   REMOTE CONTROLLER                35.20                    0.00
1   CD PLAYER                        74.50                   74.50
21   AV PROCESSOR                   1500.00                31500.00

SUBTOTAL           38834.50
TAX            3398.02
TOTAL           42232.52

Alex Kim
Press any key to continue . . .
*/
