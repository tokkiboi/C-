
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
double caffeine=130.0;
int cups;
//double consumed=caffeine * cups;
string empt=" ";
cout << "Enter Cups" << endl;
cin >> cups;
double consumed=caffeine * cups;
cout << "Consumed" << endl;
cout << consumed << endl;
}
