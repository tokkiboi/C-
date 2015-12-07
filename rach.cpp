//Rachit Shukla
//CIS 022A
//rachitshukla45@gmail.com
//lab 6     
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;
double calcCI(double, double, double, double, double, double, double&, string);

int main()
{
	//Declare variables
	string name;
	double composite_index;
	double G, H, U, T, He, M;
	char ch='\n';

	ifstream fileIn;
	fileIn.open("costIndex.txt");
	if (fileIn.fail())
	{
		cout << "No such file";
		system("pause");
		exit(100);
	}
//	calcCI(G, H, U, T, He, M, composite_index, name);
	while (!fileIn.eof())
{
getline(fileIn,name);
cout << name << endl;
fileIn >> G >> H >> U >> T >> He >>  M;
cout << G << U << T << He << M << endl;
fileIn.get(ch);
	composite_index=calcCI(G,H,U,T,He,M,composite_index,name);
	cout << left << setw(10) << G << right << setw(9) << H << setw(10) <<
		U << right << setw(9) << T << setw(10) << He << right << setw(9) << setw(10)
		<< M << right << setw(9) << endl;
	cout << composite_index << endl;
}

	cout << "Rachit Shukla" << endl;
	system("pause");
	return 0;

}
//Composite Index
///////////////////////////////////////////////
double calcCI(double G, double H, double U, double T, double He, double M, double& composite_index, string name)
{
//	ifstream fileIn;
//	char ch='\n';
//	while (!fileIn.eof())
//	{
//		getline(fileIn, name);
//		cout << name << endl;
//		fileIn >> G >> H >> U >> T >> He >> M;
//		cout << G << U << T << He << M << endl;
//		fileIn.get(ch);
		composite_index = 0.13 * G + .29 * H + .10 * U + .12 * T + .12 * He + .24 * M;
//		cout << setprecision(1) << fixed;
//		cout << "Composite Index: " << composite_index << endl;
//
//	}
	return composite_index;
}

