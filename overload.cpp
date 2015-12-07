#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;
char menu();
double calcArea(double);
double calcArea(double,double);
double calcArea(double,double,double);
double calcArea(int);


int main()
{
//Declare variables
char choice; int side;
double radius, len, width, ht, base1, base2;
while ((choice = menu()) != 'E' )
{
switch (choice)
{
case 'C':
cout << "Enter the radius of the circle: "<< endl;
cin >> radius;
cout << calcArea(radius)<<endl;
break;

case 'R':
cout << "Enter the length of the rectangle: "<< endl;
cin >> len;
cout << "Enter the width of the rectangle: "<< endl;
cin >>width;
cout << calcArea(len,width)<<endl;
break;

case 'S':
cout << "Enter the length of the side of the square: " << endl;
cin >> side;
cout << calcArea(side)<<endl;
break;
case 'Q':
cout << "Enter the height of the trapezoid: " << endl;
cin >> ht;
cout << "Enter length of first base of the trapezoid: " << endl;
cin >> base1;
cout << "Enter length of second base of the trapezoid: " << endl;
cin >> base2;
cout << calcArea(ht, base1, base2) <<endl;
break;

default:
cout << "Not a valid choice " << endl;
}
}//while
cout << "Have a marvelous day " << endl;
system ("pause");
return 0;
}
char menu()
{
char choice;
cout << "Enter " <<endl;
cout << "\t C to compute area of a circle: " <<endl;
cout << "\t R to compute area of a rectangle: " <<endl;
cout << "\t S to compute area of a square: " << endl;
cout << "\t Q to compute area of a trapezoid: " << endl;
cout << "\t E to exit the program " << endl;
cin >> choice;

return toupper(choice);
}
double calcArea(double circ)
{
circ_area=}

