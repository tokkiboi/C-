// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab #5 - Monthly House Costs
/* Write a C++ program to calculate the monthly cost of a house given the selling price */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <string>

#define TAX_RATE 0.0125
#define INSURANCE_COST 550.00
#define UTILITIES 300.00

void input_data(double&,double&,int&);
void calc(double,double,int,double&,double&,double&,double,double&);
double loan_amount(double&,double&);
double downPayment(double&,double&);
double mortgage(double,double,int);
void output_data(double,double,int,double,double,double,double,double);
void signature();

using namespace std;

void input_data(double& s_price,double& int_rate,int& numYear){
cout << "Enter the selling price: ";
    cin >> s_price;
cout << "Enter rate of interest: ";
    cin >> int_rate;
int_rate=int_rate/100;
cout << "Enter the number of years for the loan: ";
    cin >> numYear;
    return;}

int main(){
    int num_of_years;
    double sell_price,interest_rate,loaner,mortgagePayment,d_payment,property_tax;
    const double downpayrate=0.2;

	fstream myfile;
myfile.open("lab5_output.txt");

    input_data(sell_price,interest_rate,num_of_years);
    calc(sell_price,interest_rate,num_of_years,loaner,mortgagePayment,d_payment,downpayrate,property_tax);
    output_data(sell_price,interest_rate,num_of_years,loaner,mortgagePayment,d_payment,downpayrate,property_tax);
return 0;
}

void calc(double s_price,double i_rate,int numOfYears, double& loan,double& mortgagePayment,double& dPayment,double dpay_rate,double& p_tax){
    p_tax=s_price*TAX_RATE;
    loan=loan_amount(s_price,dpay_rate);
    dPayment=downPayment(s_price,dpay_rate);
    mortgagePayment=mortgage(i_rate,loan,numOfYears);
    }

double downPayment(double& sellPrice,double& dpayRate){
    double down_payment=sellPrice*dpayRate;
   return down_payment;}

double loan_amount(double& sPrice,double& dpayRate){
    double loanamt=sPrice-(sPrice*(dpayRate));
    return loanamt;}

double mortgage(double i_rate,double loan,int numOfYears){
    double comp_i_rate=i_rate/12;
    double comp_period=numOfYears*12;
    double mortgage_payment=(((loan*comp_i_rate)*(pow((1+comp_i_rate),comp_period)))/((pow((1+comp_i_rate),comp_period))-1));
    return mortgage_payment;}


void output_data(double sellPrice,double intRate,int numberOfYears,double loanamt,double mortgagePayment,double dPayment,double dp_rate,double prop_tax){

string fill=" ";
string fill2="_________";
fstream myfile;
myfile.open ("lab5_output.txt",fstream::out);
myfile << "MONTHLY COST OF HOUSE" << endl << endl;
myfile << setw(30) << left << "SELLING PRICE" << setw(15) << fill << "$" << setw(9) << setprecision(2) << fixed << right << sellPrice << endl;
myfile << setw(30) << left << "DOWN PAYMENT" << setw(15) << fill << setw(10) << right << dPayment << endl;
myfile << setw(30) << left << "AMOUNT OF LOAN" << setw(15) << fill << setw(10) << right << loanamt << endl;
myfile << setw(30) << left << "INTEREST RATE" << setw(15) << fill << setw(9) << setprecision(1) << right << intRate*100.0 << "%" << endl;
myfile << setw(30) << left << "TAX RATE" << setw(15) << fill << setw(9) << setprecision(1) << right << TAX_RATE * 100.0 << "%"<< endl;
myfile << setw(30) << left << "DURATION OF LOAN (YEARS)" << setw(15) << fill << setw(10) << right << numberOfYears << endl << endl;
myfile << "MONTHLY PAYMENT\n";
myfile << setw(5) << fill << setw(25) << left << "MORTGAGE" << setw(17) << fill << setw(8) << setprecision(2) << fixed << right << mortgagePayment << endl;
myfile << setw(5) << fill << setw(25) << left << "UTILITIES" << setw(17) << fill << setw(8) << setprecision(2) << fixed << right << UTILITIES << endl;
myfile << setw(5) << fill << setw(25) << left << "PROPERTY TAXES" << setw(17) << fill << setw(8) << setprecision(2) << fixed << right << prop_tax << endl;
myfile << setw(5) << fill << setw(25) << left << "INSURANCE" << setw(17) << fill << setw(8) << setprecision(2) << fixed << right << INSURANCE_COST << endl;
myfile << setw(46) << fill << setw(9) << fill2 << endl;
myfile << setw(45) << fill << "$ " << setw(8) << setprecision(2) << fixed << right << (mortgagePayment+UTILITIES+prop_tax+INSURANCE_COST) << endl;
signature();
myfile.close();}

void signature(){
fstream myfile;
myfile.open("lab5_output.txt",fstream::app);
string position1="Student Name:\t";
string position2="E-mail:\t\t";
string position3="Program:\t";
myfile << position1+"Alex Kim" << endl;
myfile << position2+"alexkim80@gmail.com" << endl;
myfile << position3+"Lab #5 - Monthly House Costs" << endl;
myfile.close();
}

