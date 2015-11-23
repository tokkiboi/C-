// Alex Kim
// Assignment #3
// GNU Compiler - Linux

#include <iostream>
#include <iomanip>  // included to use set width
#include <string>
using namespace std;

int main()
{
    double pprice,sprice,cash,vshares,gain;
    int shares;
    const int invest=10000;
    const string pdate = "01/02/15";
    const string ticker = "XYZ";
    string sdate;

    cout << "\nEnter the purchase price => \t $";
    cin >> pprice;
    cin.ignore();
    cout << "\nEnter the sell date (mm/dd/yy) =>\t ";
    getline(cin,sdate);
    cout << "\nEnter the sell price =>\t $";
    cin >> sprice;
    shares = invest/pprice;
    cash = invest%shares;
    vshares = shares * sprice;
    gain = ((vshares + cash) - invest)/invest;
    cout << "\n\nStock Ticker: " << ticker << endl;
    cout << "\nPurchase Date: " << pdate << endl;
    cout << "Purchase Price: " << "$" << setprecision(2) << fixed << pprice << endl;
    cout << "Number of shares Purchased: " << shares << endl;
    cout << "\nSell Date: " << sdate << endl;
    cout << "Sell Price: " << "$" << setprecision(2) << fixed << sprice << endl;
    cout << "Value of Shares Sold: " << "$" << setprecision(2) << fixed << vshares << endl;
    cout << "Percentile of gain: " << gain << "%" << endl;
    return 0;
}
