#include <iostream>
#include <fstream>
using namespace std;

#define MAX 50
//declare functions
int getData(ifstream&,int [], double [], int [], int [] );
int search(int arr[], int howMany, int target);//index where found
void output(int[], double[], int[], int[], int);
void sortSelect(int arr[], int num, double [], int qty[],int rop[]);
int mostExpensive(double[],int[]);
int main(void)
{
	//Declare variables
	ifstream inFile;
	int id[MAX];
	double price[MAX];
	int qty[MAX];
	int rop[MAX];
	int number; int target; int loc,int highest;

	//Open file
	inFile.open("products.txt");
	if (inFile.fail())
	{
		cout << "No Such File" << endl;
		system("pause");
		exit(100);
	}
	

	//Input the entire contents of the product file
	number = getData(inFile, id, price, qty, rop);
	
	//Looking for a particular product 
	cout << "Enter product id: ";
	cin >> target;

	loc = search(id, number, target);
	if (loc == -1)
		cout << "No such product" << endl;
	else
		cout << "Cost: " << price[loc] << endl;

	//Sort by the product id 
	sortSelect(id, number, price, qty, rop);
	//Output each product's id, quantity on hand, re-order point, and price
	output(id, price, qty, rop, number);
	
	// Most expensive item
	highest = mostExpensive(price,number);
	cout << "Most expensive item: " << id[highest] << endl;
	system("pause");
	return 0;
}//main
//>>>>>>>>>>>>>>>>>>>>>>
int getData(ifstream& inFile, int id[], double cost[], int qty[], int rop[])
{
	/*Pre: inFile - reference to input file
	       id[] - array of product id numbers
		   cost[] - price each
		   qty[] - number on hand
		   rop[] - reorder point
      Post: Number of items in stock
	  Purpose: read in inventory*/

	int count = 0;
	while (!inFile.eof() && count < MAX)
	{
		inFile >> id[count] >> cost[count] >> qty[count] >> rop[count];
		
		count++;
	}

	return count;
}//getData
int search(int arr[], int num, int target)
{
	/* Pre: arr[] - values being searched
	        num - number of values to be searched through
			target - value being searched for
		Post: index of where it was found or -1 if not found
		Purpose: find location of value being searched for*/

	int loc = -1;

	for (int i = 0; i < num; i++)
	{
		if (arr[i] == target)
			loc = i;
	}
	return loc;
}//
void output(int id[], double price[],int qty[], int rop[], int count)
{
	for (int i = 0; i < count; i++)
		cout << id[i] << "   " << price[i] << "   " << qty[i]
		<< "   " << rop[i] << endl;
	return;
}
void sortSelect(int arr[], int num, double price[], int qty[], int rop[])
{
	int current; int walker;
	int smallestIndex;
	int temp; double tempDbl;

	for (current = 0; current < num - 1; current++)
	{
		smallestIndex = current;
		for (walker = current; walker < num; walker++)
		{
			if (arr[walker] < arr[smallestIndex])
				smallestIndex = walker;
		}//for walker

		//Swap to position smallest at what is the current position
		temp = arr[current];
		arr[current] = arr[smallestIndex];
		arr[smallestIndex] = temp;

		temp = qty[current];
		qty[current] = qty[smallestIndex];
		qty[smallestIndex] = temp;

		temp = rop[current];
		rop[current] = rop[smallestIndex];
		rop[smallestIndex] = temp;

		tempDbl = price[current];
		price[current] = price[smallestIndex];
		price[smallestIndex] = tempDbl;
	}//for current 
	return;
}

int mostExpensive(double cost, int num)
{
int highest=0;
 for (int i=0;i<num;i++){
	if (cost[i] > cost[highIndex])
	highIndex=i;
}
return highest;
}


