// Alex Kim - William Suh
// alexkim80@gmail.com - williamsuh@gmail.com
// "Ugly Carpet"

#include <iostream>
#include <iomanip>
using namespace std;

#define TAX_RATE 0.085
#define LABOR_RATE 0.35

//Function Prototypes
void inputData(int&,int&,int&,double&);
void calc(int,int,int,double,int&,double&,double&,double&,double&,double&,double&,double&);
void output(int l, int w, int dis, double unitCost, int area, double carpetCost,
           double labour, double install, double discount, double taxes, double subtotal, double total);

double calcInstall(int,double,double&,double&,double&);
double calcSubtotal(double,double,double&,double&);
double calcTotal(double,double&,double&);

int main(){

//declare variables
int length, width, discountRate, area;
double priceSqFt, carpetCost, labour, install, discount;
double subtotal, taxes, total;

// input dimensions of room, discount and price per sq ft of carpet
inputData(length, width, discountRate, priceSqFt);

// compute cost
calc(length, width,discountRate, priceSqFt,area,carpetCost,
labour, install, discount, taxes, subtotal, total);

//output
output(length, width, discountRate, priceSqFt, area, carpetCost,
labour, install, discount, taxes, subtotal, total);

system( "read -n 1 -s -p \"Press any key to continue...\"" );
return 0;}


/*====================input==============================
Purpose: Inputs the room dimensions, percent of discount, and
the cost of the carpet per square foot. */

void inputData(int& l, int& w, int& dis, double& unitCost){
/*	Pre: 		Addresses for room dimensions, rate of discount, price per square foot of carpet
	Post: 		Nothing */
	
	cout << "please enter the length of room: ";
	cin >> l;
	cout << "please enter the width of room: ";
	cin >> w;
	cout << "please enter the discount rate: ";
	cin >> dis;
	cout << "please enter the cost per square feet of carpet: ";
	cin >> unitCost;
return;}

/* ===================== calculations====================================
Purpose: Computes the costs for labor and carpet. Computes discount, subtotal, taxes and total.

	Pre:		length, width, discount rate, and unit price along with references to cost of carpet,
			cost of labour, installation cost, amount of discount, tax, subtotal and total for order.
	Post:		The area of the room is returned.*/

void calc(int Length,int Width, int DisCount, double UnitCost,int& Area, double& CarpetCost,
double& Labour, double& Install, double& Discount, double& Taxes, double& Subtotal, double& Total){
Area=Length*Width;
//return Area;
Install=calcInstall(Area,UnitCost,CarpetCost,Labour,Install);
Subtotal=calcSubtotal(Install,DisCount,Discount,Subtotal);
Total=calcTotal(Subtotal,Taxes,Total);
}

/* =====================calcInstall=================================
	Purpose:	Computes costs of labor and carpet and their sum.
	Pre:		area and unit price along with the references to carpet cost, labor cost, and
			installed cost.
	Post:		Nothing */

//calcInstall
double calcInstall(int areA,double unitCost,double& carpetCost,double& laborCost, double& installCost){
carpetCost=unitCost*areA;
laborCost=LABOR_RATE*unitCost;
installCost=carpetCost+laborCost;
return installCost;}


/* =======================calcSubtotal===============================
	Purpose:	Computes the amount of discount and subtotal.
	Pre:		The installed cost and discount rate along with addresses for the
			amount of the discount and the subtotal.
	Post:		Nothing */
//calcSubtotal
double calcSubtotal(double install_cost,double DC_rate,double& DC,double& subTotal){
DC=(DC_rate/100);
subTotal=install_cost+(install_cost*DC);
return subTotal;}

/*========================calcTotal=================================
	Purpose:	Computes the tax and total.
	Pre:		Subtotal along with reference pointers to tax and total
	Post:		Nothing */

//calcTotal
double calcTotal(double s_total,double& Tax, double& g_total){
Tax=s_total*static_cast<double>(TAX_RATE);
g_total=s_total+Tax;
return g_total;}

void output(int leng, int wid, int disc, double unit_cost, int aRea, double carpet_cost,
double labor, double instaLL, double diScount, double taxeS, double suBtotal, double totaL)
{
cout << setprecision(2) << fixed;
cout<< "\t\t\tMEASUREMENT" << endl;
cout<<"Length " << setw(3) << leng <<" ft" << endl;
cout<<"Width " << setw(3) << wid <<" ft" << endl;
cout<<"Area " << setw(3) << aRea <<" ft" << endl;

cout<<"\n\n\t\t\tCHARGES" <<endl;
cout<<"\nDESCRIPTION COST/SQ.FT. CHARGE" <<endl;
cout<<"----------- ----------- ----------";
cout<<left << setw(20) << "\nCarpet " << right << setw(7) << unit_cost << " " << setw(7)<< carpet_cost;
cout<<left << setw(20) <<"\nLabor " << right << setw(7) << LABOR_RATE<< " " << setw(7) << labor;
cout<< setw(25) <<"\n ----------";
cout<<left << setw(20) <<"\nINSTALLED PRICE $ " << right << setw(7) << instaLL;
cout<<left << setw(20) <<"\nDiscount " << right << setw(7)<< disc << "%" <<setw(7) << diScount;
cout << setw(25) <<"\n ----------";
cout<<left << setw(20) <<"\nSUBTOTAL $ " << right << setw(7) << suBtotal;
cout<<left << setw(20) <<"\nTax " << right << setw(7) << taxeS;
cout<<left << setw(20) <<"\nTOTAL $ " << right << setw(7) << totaL << cout<< endl;

cout<< "Programmed by: 1) Alex Kim\n\t\t 2) William Suh\n\n";
}
