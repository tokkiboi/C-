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

// FUNCTION PROTOTYPE DECLARATION
void input_data(double&,double&,int&);
void calc(double,double,int,double&,double&,double&,double,double&);
double loan_amount(double,double);
double downPayment(double,double);
double mortgage(double,double,int);
void output_data(double,double,int,double,double,double,double,double);
void signature();

using namespace std;

// FUNCTION INPUT
/* PRE:         s_price - Reference to selling price of the house
                int_rate - Reference to interest rate on the mortgage
                numYear - Reference to duration of the loan in years
   POST:        values received will be passed to function caller.
   PURPOSE:     Prompt user and store data for variables passed by reference and return to function caller */
     
void input_data(double& s_price,double& int_rate,int& numYear){
cout << "Enter the selling price: ";
    cin >> s_price;
cout << "Enter rate of interest: ";
    cin >> int_rate;
int_rate=int_rate/100;
cout << "Enter the number of years for the loan: ";
    cin >> numYear;
    return;}

// FUNCTION MAIN
int main(){
    // Variables declaration
    int num_of_years;
    double sell_price,interest_rate,loaner,mortgagePayment,d_payment,property_tax;
    
    // Non-global memory constant variable declaration for downpayment rate @ 20%
    const double downpayrate=0.2;
    
    // declare fstreaming
	fstream myfile ("lab5_output.txt");
    // check to see if file containing previous output exists, if true, rename file and create a new file to open for stream out 
    if (myfile){
    cerr << "Previous data exists... backing up.. and opening a new file\n";
        system("mv lab5_output.txt lab5_output2.txt");
        myfile.close();

    myfile.open("lab5_output.txt",fstream::out);}
    else myfile.open("lab5_output.txt", fstream::app);

    // function calls
    input_data(sell_price,interest_rate,num_of_years);   // variables passed by reference will return with values
    calc(sell_price,interest_rate,num_of_years,loaner,mortgagePayment,d_payment,downpayrate,property_tax);
    output_data(sell_price,interest_rate,num_of_years,loaner,mortgagePayment,d_payment,downpayrate,property_tax);
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
return 0;
}

// FUNCTION CALC
/*  PRE:        selling price, interest rate, duration of loan downpayment rate passed by value.
                loan - reference to mortgage loan amount, 
                mortgagePaument - reference to monthly mortgage payment
                dPayment - reference to amount of downpayment
                p_tax - reference to property TAX
    POST:       compute and define variables passed by reference to return
    PURPOSE:    invoke sub-functions loan_amount to calculate the amount of loan needed, sub-function downPayment for amount of downpayment to be made, sub-function\
                mortgagePayment to calculate monthly mortgage payment needed */
                
void calc(double s_price,double i_rate,int numOfYears, double& loan,double& mortgagePayment,double& dPayment,double dpay_rate,double& p_tax){
    // declare and initialize property tax amount
    p_tax=s_price*TAX_RATE;
    // invoke sub-functions to compute the amount of loan, downpayment, mortgage payment
    loan=loan_amount(s_price,dpay_rate);
    dPayment=downPayment(s_price,dpay_rate);
    mortgagePayment=mortgage(i_rate,loan,numOfYears);
    }

// FUNCTION downPayment
/*  PRE:        selling price of the house and downpayment rate passed by value
    POST:       return amount of downpayment
    PURPOSE:    compute for the amount of downpayment to be made */        
double downPayment(double sellPrice,double dpayRate){
    double down_payment=sellPrice*dpayRate;
   return down_payment;}

// FUNCTION loan_amount
/*  PRE:        selling price and downpayment rate passed by value
    POST:       return loan amount
    PURPOSE:    calculate the amount of loan needed */
double loan_amount(double sPrice,double dpayRate){
    double loanamt=sPrice-(sPrice*(dpayRate));
    return loanamt;}

// FUNCTION mortgage
/*  PRE:        interest rate, loan amount, duration of loan passed by value
    POST:       return amount of mortgage payment
    PURPOSE:    calculate the expected monthly mortgage payment */
double mortgage(double i_rate,double loan,int numOfYears){
    double comp_i_rate=i_rate/12;
    double comp_period=numOfYears*12;
    double mortgage_payment=(((loan*comp_i_rate)*(pow((1+comp_i_rate),comp_period)))/((pow((1+comp_i_rate),comp_period))-1));
    return mortgage_payment;}

// FUNCTION output_data
/*  PRE:        all previously declared variables are defined and passed by values
    POST:       voided
    PURPOSE:    stream all output data to a file */
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

// FUNCTION signature - my identity
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