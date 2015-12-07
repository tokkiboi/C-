#include <iostream>
#include <fstream>

using namespace std;

#define MAX 50

//ifstream inFile;

int getData(ifstream&,int [],double [],int [],int [] );
int search(int arr[],int,int);
void output();
void sortSelect(int arr[],int);

int main()
{
// Declare variables
// ifstream inFile;
int id[MAX];
double price[MAX];
int qty[MAX];
int rop[MAX];
int number;
int loc;
int target;

ifstream inFile;
//Open file
inFile.open("products.txt");
	if (inFile.fail())
	{
		cerr << "file could not be open";
		exit (100);
	}
	else{
	 cout << "file opened successfully";
	 }

//Input the entire contents of the product file
// number=getData(ifstream& inFile,id[],price[],qty[],rop[]);
//Looking for a particular product - next week
cout << "Enter product id: ";
cin >> target;

loc = search (id,number,target);
if (loc == -1){
	cout << "Product is not there\n";}
else{cout << "Cost: " << price[loc] << "Qty: " << qty[loc] << "Re-Order Point: " << rop[loc] << endl;}


number=getData(inFile,id,number,target);
//Sort by the product id - next week
sortSelect(id,number);

	//Output each product's id, quantity on hand, re-order point, and price

	system("pause");

	return 0;
}

int getData (ifstream& inFile, int id[],double price[],int qty[],int rop[])
{
/*	Pre: 		inFile - reference to input file
			id 0 an array of product numbers
			cost -an array of price each of
			qty - an array of quantities in stock in warehouse
			rop - an array of re-ordering point
	Post:		Return number of items in stock
	Purpose:	Read in the inventory */

int count=0;
while (!inFile.eof() && count < MAX){
	inFile >> id[count] >> price[count] >> qty[count] >> rop[count];
	cout << id[count] << price[count] << qty[count] << rop[count] << endl;
	count++;
}
return count;
}
int search (int arr[],int num, int target)
{
/*	Pre:		arr[] = values being searched
			num - number of values to be searched through
			target - value being searched for 
	Post:		Index of where it was found or -1 (if not found)
	Purpose:	find location of value being searched for */

	int loc = -1;
	for (int i=0; i < num; i++)
	{
	if (arr[i] == target)
		loc = i;
	}
return loc;

}
void sortSelect(int arr[], int num)
{
    int current; int walker;
    int smallestIndex;
    int temp;
   
    for (current = 0; current < num - 1; current++)
    {
        smallestIndex = current;
        for (walker = current; walker < num; walker ++)
          {
                if (arr[walker] < arr[smallestIndex])
                  smallestIndex = walker;
          }//for walker
       
        //Swap to position smallest at what is the current position
        temp = arr[current];
        arr[current] = arr[smallestIndex];
        arr[smallestIndex] = temp; 
    }//for current
  return;
}
