// Alex Kim - 20224753
// alexkim80@gmail.com
// Lab 6 - Comparative Cost of Living in US Cities
/*	Write a C++ program to compare cost of living in cities throughout the United States.	*/

#include <iostream>
#include <fstream>  // Allow file handling: Input/Output to and from file(s)
#include <string>   // Utilize string variable
#include <cstdlib>  // Required for Exit() function
#include <iomanip>  // Input/Output Formatting library

// FUNCTION PROTOTYPE DECLARATION
double comp_index(double,double,double,double,double,double);
void signature();

using namespace std;

// FUNCTION MAIN
int main()
{
	// Declaring variables
	int count=0;
	double c_index;
	double max;
	double min;
	string state_name,max_string,min_string;
	double groceries,housing,utilities,transportation,health,misc;
	char ch='\n';
	
	// Declare myFile as file handler
	ifstream myFileIn;
	myFileIn.open("costIndex.txt");
	ofstream myFileOut;
	myFileOut.open("costIndex.txt",ios::app);
		
		// If-Else statement to check success/fail on file open
		if (myFileIn.fail())	
		{
			cerr << "\033[1;31mFile could not be open\033[0m\n";
			system("read -n 1 -s -p \"Press any key to continue...\"\n" );
			exit(1);
		}
		else {cout << "\033[1;31mFile successfully open.. continuing...\033[0m\n";}

	// While loop to read in data from file until data input is valid
	while (getline(myFileIn,state_name))
	{
		myFileIn >> groceries >> housing >> utilities >> transportation >> health >> misc;
		myFileIn.ignore(100,ch);	// Clear buffer before transitioning to next getline from cin to rid empty line retrieved
		myFileOut << setprecision(1) << fixed << endl;	// Set output to display 1 digit after decimal point.
		myFileOut << "State Name:\t\t" << state_name << endl;
		myFileOut << "Groceries:\t\t" << setw(5) << right << groceries << endl;
		myFileOut << "Housing:\t\t" << setw(5) << right << housing << endl;
		myFileOut << "Utilities:\t\t" << setw(5) << right << utilities << endl;
		myFileOut << "Transportation:\t\t" << setw(5) << right << transportation << endl;
		myFileOut << "Health:\t\t\t" << setw(5) << right << health << endl;
		myFileOut << "Misc:\t\t\t" << setw(5) << right << misc << endl;
		c_index=comp_index(groceries,housing,utilities,transportation,health,misc);
		myFileOut << "Composite Index:\t" << setw(5) << right << c_index << endl;

                cout << setprecision(1) << fixed << endl;     // Set output to display 1 digit after decimal point.
		cout << "\033[1;33m" << "State Name:\t\t" << state_name << endl;
                cout << "\033[1;32m" << "Composite Index:\t" << setw(5) << right << c_index << endl;

		// If statement to declare max composite index/min composite index and corresponding city name
		if ((c_index >= min) && (c_index >= max))
		{
			max=c_index;
			min=c_index;
			max_string=state_name;
		}
		else if (c_index <= min)
		{
			min=c_index;
			min_string=state_name;
		}
		count++;
	}
myFileIn.close();
// myFileIn.close(); // close readin file
		cout << "\n";
		myFileOut << "\n";
		myFileOut << "The Min:\t\t" << setw(5) << right <<  min << "\t" << min_string << endl;
		myFileOut << "The Max:\t\t" << setw(5) << right <<  max << "\t" << max_string << endl;
		cout << "\033[1;31mThe Min:\t\t" << "\033[0m" << setw(5) << right << min << "\t" << "\033[1;31m" << min_string << "\033[0m" << endl;
		cout << "\033[1;31mThe Max:\t\t" << "\033[0m" << setw(5) << right << max << "\t" << "\033[1;31m" << max_string << "\033[0m" << endl;
myFileOut.close();	// close write out file
signature();
return 0;
}

// FUNCTION COMP_INDEX
/*	PRE:		Following variables passed by value:
			groc - income spent on Groceries
			house - income spent on Housing
			util - income spent on Utilities
			trans - income spenbt on Transportation
			hlth - income spent on Health
			misc - income spent on Miscellaneous
	POST:		Return the composite index
	PURPOSE:	Compute the composite index */
double comp_index(double groc,double house,double util,double trans,double hlth,double misc)
{
	// Declare variable index to store the composite index
	double index=((0.13*groc)+(0.29*house)+(0.1*util)+(0.12*trans)+(0.12*hlth)+(0.24*misc));
	// return calculated composite index
	return index;
}

// FUNCTION SIGNATURE
void signature()
{
ofstream myFileOut;
	myFileOut.open("costIndex.txt",ios::app);
	string position1="Student Name:\t";
	string position2="E-mail:\t\t";
	string position3="Assignment:\t";
	myFileOut << "\n" << endl;
	myFileOut << position1+ "Alex Kim" << endl;
	myFileOut << position2+ "alexkim80@gmail.com" << endl;
	myFileOut << position3+ "Lab 6 - Comparative Cost of Living in US Cities" << endl;
myFileOut.close();
}

/* OUTPUT
tokkiboi@voyager~/programming/cpp $ ./a.out 
File successfully open.. continuing...

State Name:		Anniston-Calhoun, County, ALt
Composite Index:	 90.5

State Name:		Akron OH
Composite Index:	 99.7

State Name:		Albany, GA
Composite Index:	 89.6

State Name:		Albany, NY
Composite Index:	108.2

State Name:		Alexandria, LA
Composite Index:	 94.7

State Name:		Amarillo, TX
Composite Index:	 89.9

State Name:		Americus, GA
Composite Index:	 89.5

State Name:		Ames, IA
Composite Index:	 97.3

State Name:		Anchorage, AK
Composite Index:	129.2

State Name:		Anderson, SC
Composite Index:	 92.0

State Name:		Appleton, WI
Composite Index:	 94.2

State Name:		Ardmore, OK
Composite Index:	 87.9

State Name:		Arlington, TX
Composite Index:	 99.2

State Name:		Asheville, NC
Composite Index:	101.3

State Name:		Ashland, OH
Composite Index:	 88.3

State Name:		Atlanta, GA
Composite Index:	 95.8

State Name:		Auburn-Opelika, AL
Composite Index:	 97.2

State Name:		Augusta-Aiken, GA-SC
Composite Index:	 93.3

State Name:		Austin, TX
Composite Index:	 95.5

State Name:		Bakersfield, CA
Composite Index:	103.9

State Name:		Baltimore, MD
Composite Index:	119.1

State Name:		Baton, Rouge, LA
Composite Index:	 96.1

State Name:		Beaufort, SC
Composite Index:	104.2

State Name:		Beaumont, TX
Composite Index:	 95.8

State Name:		Bellingham, WA
Composite Index:	114.3

State Name:		Bergen-Passaic, NJ
Composite Index:	130.3

State Name:		Bethesda-Gaithersburg-Frederick, MD
Composite Index:	130.3

State Name:		Binghamton, NY
Composite Index:	 99.8

State Name:		Birmingham, AL
Composite Index:	 89.8

State Name:		Bismarck-Mandan, ND
Composite Index:	 95.5

State Name:		Blacksburg, VA
Composite Index:	 95.1

State Name:		Boise, ID
Composite Index:	 97.7

State Name:		Boston, MA
Composite Index:	131.5

State Name:		Bowling, Green, KY
Composite Index:	 90.9

State Name:		Bozeman, MT
Composite Index:	101.8

State Name:		Bradenton, FL
Composite Index:	 96.1

State Name:		Brazoria, County, TX
Composite Index:	 89.4

State Name:		Brownsville, TX
Composite Index:	 86.3

State Name:		Buffalo, NY
Composite Index:	 96.4

State Name:		Burlington, IA
Composite Index:	 96.4

State Name:		Burlington, NC
Composite Index:	 94.6

State Name:		Burlington-Chittenden, Co, VT
Composite Index:	119.4

State Name:		Camden, SC
Composite Index:	 96.2

State Name:		Cape, Coral-Fort, Myers, FL
Composite Index:	 95.7

State Name:		Carlsbad, NM
Composite Index:	 95.1

State Name:		Cedar, City, UT
Composite Index:	 88.0

State Name:		Cedar, Rapids, IA
Composite Index:	 91.8

State Name:		Champaign-Urbana, IL
Composite Index:	 96.9

State Name:		Chapel, Hill, NC
Composite Index:	112.9

State Name:		Charleston, WV
Composite Index:	 93.0

State Name:		Charleston-N, Charleston, SC
Composite Index:	 98.4

State Name:		Charlotte, NC
Composite Index:	 93.9

State Name:		Charlottesville, VA
Composite Index:	106.0

State Name:		Chattanooga, TN
Composite Index:	 91.0

State Name:		Cheyenne, WY
Composite Index:	100.5

State Name:		Chicago, IL
Composite Index:	117.3

State Name:		Cincinnati, OH
Composite Index:	 93.6

State Name:		Clarksburg, WV
Composite Index:	 94.7

State Name:		Clarksville, TN
Composite Index:	 92.7

State Name:		Cleveland, OH
Composite Index:	101.2

State Name:		Cleveland, TN
Composite Index:	 93.3

State Name:		Colorado, Springs, CO
Composite Index:	 93.7

State Name:		Columbia, MO
Composite Index:	 91.6

State Name:		Columbia, SC
Composite Index:	100.0

State Name:		Columbus, OH
Composite Index:	 93.5

State Name:		Conroe, TX
Composite Index:	 91.0

State Name:		Conway, AR
Composite Index:	 87.3

State Name:		Cookeville, TN
Composite Index:	 84.8

State Name:		Corpus, Christi, TX
Composite Index:	 90.5

State Name:		Covington, KY
Composite Index:	 88.0

State Name:		Dallas, TX
Composite Index:	 92.2

State Name:		Danville, IL
Composite Index:	 91.8

State Name:		Dare, County, NC
Composite Index:	108.4

State Name:		Davenport-Moline-Rock, Is, IA-IL
Composite Index:	 97.1

State Name:		Dayton, OH
Composite Index:	 91.1

State Name:		Decatur, IL
Composite Index:	 91.4

State Name:		Decatur-Hartselle, AL
Composite Index:	 88.4

State Name:		Denver, CO
Composite Index:	103.3

State Name:		Des, Moines, IA
Composite Index:	 91.0

State Name:		Detroit, MI
Composite Index:	 99.3

State Name:		Dodge, City, KS
Composite Index:	 88.7

State Name:		Dothan, AL
Composite Index:	 88.6

State Name:		Douglas, GA
Composite Index:	 88.0

State Name:		Dover, DE
Composite Index:	 99.8

State Name:		Dubuque, IA
Composite Index:	 95.8

State Name:		Durham, NC
Composite Index:	 97.4

State Name:		Dutchess, County, NY
Composite Index:	120.2

State Name:		Dyersburg, TN
Composite Index:	 87.8

State Name:		Eau, Claire, WI
Composite Index:	 94.9

State Name:		Edmond, OK
Composite Index:	 91.3

State Name:		El, Paso, TX
Composite Index:	 91.1

State Name:		Elkhart-Goshen, IN
Composite Index:	 93.7

State Name:		Enid, OK
Composite Index:	 93.6

State Name:		Erie, PA
Composite Index:	 92.5

State Name:		Eugene, OR
Composite Index:	111.2

State Name:		Evansville, IN
Composite Index:	 96.2

State Name:		Everett, WA
Composite Index:	113.5

State Name:		Fairbanks, AK
Composite Index:	139.1

State Name:		Fargo-Moorhead, ND-MN
Composite Index:	 93.2

State Name:		Farmington, NM
Composite Index:	 97.1

State Name:		Fayetteville, AR
Composite Index:	 91.5

State Name:		Fayetteville, NC
Composite Index:	 96.6

State Name:		Findlay, OH
Composite Index:	 93.3

State Name:		Fitchburg-Leominster, MA
Composite Index:	104.3

State Name:		Flagstaff, AZ
Composite Index:	114.9

State Name:		Florence, AL
Composite Index:	 89.3

State Name:		Fort, Lauderdale, FL
Composite Index:	115.6

State Name:		Fort, Smith, AR
Composite Index:	 85.7

State Name:		Fort, Wayne-Allen, County, IN
Composite Index:	 94.3

State Name:		Fort, Worth, TX
Composite Index:	 90.9

State Name:		Framingham-Natick, MA
Composite Index:	133.8

State Name:		Fresno, CA
Composite Index:	117.4

State Name:		Gainesville, FL
Composite Index:	 99.7

State Name:		Galesburg, IL
Composite Index:	 93.0

State Name:		Garden, City, KS
Composite Index:	 89.1

State Name:		Glens, Falls, NY
Composite Index:	110.4

State Name:		Glenwood, Springs, CO
Composite Index:	124.2

State Name:		Grand, Junction, CO
Composite Index:	 99.1

State Name:		Grand, Rapids, MI
Composite Index:	 91.3

State Name:		Green, Bay, WI
Composite Index:	 95.8

State Name:		Greenville, NC
Composite Index:	 99.2

State Name:		Greenville, SC
Composite Index:	 90.4

State Name:		Gunnison, CO
Composite Index:	109.7

State Name:		Hammond, LA
Composite Index:	 95.7

State Name:		Hampton, Roads-SE, Virginia, VA
Composite Index:	111.7

State Name:		Harlingen, TX
Composite Index:	 84.2

State Name:		Harrisburg, PA
Composite Index:	 98.8

State Name:		Harrisonburg, VA
Composite Index:	 97.0

State Name:		Hartford, CT
Composite Index:	121.6

State Name:		Hastings, NE
Composite Index:	 92.5

State Name:		Hattiesburg, MS
Composite Index:	 91.9

State Name:		Hays, KS
Composite Index:	 89.2

State Name:		Hickory, NC
Composite Index:	 92.8

State Name:		Hilton, Head, Island, SC
Composite Index:	113.2

State Name:		Honolulu, HI
Composite Index:	165.5

State Name:		Hot, Springs, AR
Composite Index:	 92.1

State Name:		Houston, TX
Composite Index:	 91.8

State Name:		Huntsville, AL
Composite Index:	 90.7

State Name:		Hutchinson, KS
Composite Index:	 93.6

State Name:		Idaho, Falls, ID
Composite Index:	 90.6

State Name:		Indiana, County, PA
Composite Index:	 92.9

State Name:		Indianapolis, IN
Composite Index:	 87.5

State Name:		Iowa, City, IA
Composite Index:	 96.1

State Name:		Ithaca, NY
Composite Index:	103.6

State Name:		Jackson, MS
Composite Index:	 96.7

State Name:		Jackson-Madison, County, TN
Composite Index:	 89.8

State Name:		Jacksonville, FL
Composite Index:	 92.9

State Name:		Jacksonville, NC
Composite Index:	 96.6

State Name:		Janesville, WI
Composite Index:	 96.6

State Name:		Jefferson, City, MO
Composite Index:	 92.1

State Name:		Johnson, City, TN
Composite Index:	 86.7

State Name:		Johnstown, PA
Composite Index:	 92.4

State Name:		Joliet-Will, County, IL
Composite Index:	103.4

State Name:		Jonesboro, AR
Composite Index:	 87.9

State Name:		Joplin, MO
Composite Index:	 88.6

State Name:		Juneau, AK
Composite Index:	138.6

State Name:		Kalamazoo, MI
Composite Index:	 91.4

State Name:		Kalispell, MT
Composite Index:	 99.5

State Name:		Kansas, City, MO-KS
Composite Index:	 97.2

State Name:		Kennewick-Richland-Pasco, WA
Composite Index:	 94.0

State Name:		Kinston, NC
Composite Index:	 94.1

State Name:		Knoxville, TN
Composite Index:	 88.7

State Name:		Kodiak, AK
Composite Index:	130.3

State Name:		Lafayette, IN
Composite Index:	 99.3

State Name:		Lafayette, LA
Composite Index:	 98.7

State Name:		Lake, Charles, LA
Composite Index:	 96.6

State Name:		Lake, Havasu, City, AZ
Composite Index:	111.3

State Name:		Lancaster, PA
Composite Index:	106.2

State Name:		Laramie, WY
Composite Index:	 97.3

State Name:		Las, Cruces, NM
Composite Index:	100.4

State Name:		Las, Vegas, NV
Composite Index:	102.1

State Name:		Lawrence, KS
Composite Index:	 94.8

State Name:		Lawton, OK
Composite Index:	 94.1

State Name:		Lexington, KY
Composite Index:	 92.7

State Name:		Lexington-Buena, Vista-Rockbridge, VA
Composite Index:	 93.6

State Name:		Lima, OH
Composite Index:	 93.5

State Name:		Little, Rock-North, Little, Rock, AR
Composite Index:	 95.8

State Name:		Logan, UT
Composite Index:	 94.6

State Name:		Los, Alamos, NM
Composite Index:	109.6

State Name:		Los, Angeles-Long, Beach, CA
Composite Index:	136.4

State Name:		Louisville, KY
Composite Index:	 87.5

State Name:		Loveland, CO
Composite Index:	 91.3

State Name:		Lubbock, TX
Composite Index:	 89.3

State Name:		Lufkin, TX
Composite Index:	 93.0

State Name:		Lynchburg, VA
Composite Index:	 95.3

State Name:		Manchester, NH
Composite Index:	115.6

State Name:		Manhattan, KS
Composite Index:	 94.9

State Name:		Mankato, MN
Composite Index:	 93.8

State Name:		Marietta, GA
Composite Index:	 95.2

State Name:		Marion-McDowell, County, NC
Composite Index:	 92.4

State Name:		Marshfield, WI
Composite Index:	 95.2

State Name:		Martinsburg-Berkeley, County, WV
Composite Index:	 90.7

State Name:		Martinsville-Henry, County, VA
Composite Index:	 86.5

State Name:		Mason, City, IA
Composite Index:	 89.3

State Name:		McAllen, TX
Composite Index:	 86.3

State Name:		Memphis, TN
Composite Index:	 88.5

State Name:		Miami-Dade, County, FL
Composite Index:	106.1

State Name:		Middlesex-Monmouth, NJ
Composite Index:	124.2

State Name:		Midland, TX
Composite Index:	 93.4

State Name:		Milwaukee-Waukesha, WI
Composite Index:	102.9

State Name:		Minneapolis, MN
Composite Index:	110.4

State Name:		Minot, ND
Composite Index:	 98.0

State Name:		Missoula, MT
Composite Index:	100.0

State Name:		Mobile, AL
Composite Index:	 91.9

State Name:		Monroe, LA
Composite Index:	 92.5

State Name:		Montgomery, AL
Composite Index:	 98.4

State Name:		Morgantown, WV
Composite Index:	100.6

State Name:		Morristown, TN
Composite Index:	 90.0

State Name:		Muncie, IN
Composite Index:	 90.2

State Name:		Murfreesboro-Smyrna, TN
Composite Index:	 88.2

State Name:		Muskogee, OK
Composite Index:	 86.0

State Name:		Myrtle, Beach, SC
Composite Index:	 94.9

State Name:		Nacogdoches, TX
Composite Index:	 92.8

State Name:		Nashville-Franklin, TN
Composite Index:	 87.5

State Name:		Nassau, County, NY
Composite Index:	145.6

State Name:		New, Haven, CT
Composite Index:	121.4

State Name:		New, York, (Brooklyn), NY
Composite Index:	180.1

State Name:		New, York, (Manhattan), NY
Composite Index:	214.2

State Name:		New, York, (Queens), NY
Composite Index:	157.8

State Name:		Newark-Elizabeth, NJ
Composite Index:	128.5

State Name:		Norman, OK
Composite Index:	 94.6

State Name:		Oakland, CA
Composite Index:	138.9

State Name:		Odessa, TX
Composite Index:	 91.3

State Name:		Oklahoma, City, OK
Composite Index:	 92.0

State Name:		Olympia, WA
Composite Index:	105.5

State Name:		Omaha, NE
Composite Index:	 89.1

State Name:		Orange, County, CA
Composite Index:	146.7

State Name:		Orlando, FL
Composite Index:	 97.1

State Name:		Paducah, KY
Composite Index:	 87.1

State Name:		Palm, Springs, CA
Composite Index:	121.3

State Name:		Panama, City, FL
Composite Index:	 99.4

State Name:		Paris, TX
Composite Index:	 89.0

State Name:		Pascagoula, MS
Composite Index:	 92.1

State Name:		Peoria, IL
Composite Index:	 96.3

State Name:		Philadelphia, PA
Composite Index:	125.2

State Name:		Phoenix, AZ
Composite Index:	101.2

State Name:		Pittsburgh, PA
Composite Index:	 91.3

State Name:		Pittsfield, MA
Composite Index:	109.9

State Name:		Plano, TX
Composite Index:	 97.5

State Name:		Plattsburgh, NY
Composite Index:	101.6

State Name:		Ponca, City, OK
Composite Index:	 89.8

State Name:		Portland, ME
Composite Index:	116.9

State Name:		Portland, OR
Composite Index:	111.9

State Name:		Prescott-Prescott, Valley, AZ
Composite Index:	103.5

State Name:		Providence, RI
Composite Index:	121.7

State Name:		Pryor, Creek, OK
Composite Index:	 84.0

State Name:		Pueblo, CO
Composite Index:	 86.0

State Name:		Quincy, IL
Composite Index:	 95.8

State Name:		Raleigh, NC
Composite Index:	 98.0

State Name:		Reno-Sparks, NV
Composite Index:	101.3

State Name:		Richmond, IN
Composite Index:	 91.2

State Name:		Richmond, VA
Composite Index:	105.2

State Name:		Rio, Rancho, NM
Composite Index:	 94.9

State Name:		Riverside, City, CA
Composite Index:	113.1

State Name:		Roanoke, VA
Composite Index:	 94.2

State Name:		Rochester, MN
Composite Index:	 99.6

State Name:		Rochester, NY
Composite Index:	100.1

State Name:		Rockford, IL
Composite Index:	 93.1

State Name:		Roswell, NM
Composite Index:	 96.0

State Name:		Round, Rock, TX
Composite Index:	 89.5

State Name:		Sacramento, CA
Composite Index:	116.9

State Name:		Salina, KS
Composite Index:	 87.1

State Name:		Salt, Lake, City, UT
Composite Index:	100.4

State Name:		San, Angelo, TX
Composite Index:	 92.7

State Name:		San, Antonio, TX
Composite Index:	 95.6

State Name:		San, Diego, CA
Composite Index:	132.6

State Name:		San, Francisco, CA
Composite Index:	162.9

State Name:		San, Jose, CA
Composite Index:	157.0

State Name:		San, Marcos, TX
Composite Index:	 94.4

State Name:		Sarasota, FL
Composite Index:	102.0

State Name:		Savannah, GA
Composite Index:	 93.5

State Name:		Seattle, WA
Composite Index:	121.4

State Name:		Seguin, TX
Composite Index:	 90.9

State Name:		Sheboygan, WI
Composite Index:	101.8

State Name:		Shreveport-Bossier, City, LA
Composite Index:	 94.7

State Name:		Sierra, Vista, AZ
Composite Index:	 98.1

State Name:		Sioux, Falls, SD
Composite Index:	 94.0

State Name:		Slidell-St., Tammany, Parish, LA
Composite Index:	 96.5

State Name:		South, Bend, IN
Composite Index:	 91.9

State Name:		Spokane, WA
Composite Index:	 95.3

State Name:		Springfield, IL
Composite Index:	 87.3

State Name:		Springfield, MO
Composite Index:	 88.3

State Name:		St., Cloud, MN
Composite Index:	 98.0

State Name:		St., George, UT
Composite Index:	 95.1

State Name:		St., Joseph, MO
Composite Index:	 92.1

State Name:		St., Louis, MO-IL
Composite Index:	 90.9

State Name:		St., Paul, MN
Composite Index:	109.5

State Name:		Stamford, CT
Composite Index:	145.7

State Name:		Staunton-Augusta, County, VA
Composite Index:	 96.2

State Name:		Stillwater, OK
Composite Index:	 90.2

State Name:		Sumter, SC
Composite Index:	 96.0

State Name:		Syracuse, NY
Composite Index:	101.0

State Name:		Tacoma, WA
Composite Index:	109.9

State Name:		Tampa, FL
Composite Index:	 93.1

State Name:		Temple, TX
Composite Index:	 87.4

State Name:		Thomasville-Lexington, NC
Composite Index:	 90.4

State Name:		Topeka, KS
Composite Index:	 91.4

State Name:		Troy-Miami, County, OH
Composite Index:	 94.9

State Name:		Truckee-Nevada, County, CA
Composite Index:	146.0

State Name:		Tucson, AZ
Composite Index:	 96.5

State Name:		Tulsa, OK
Composite Index:	 88.1

State Name:		Tupelo, MS
Composite Index:	 87.7

State Name:		Tuscaloosa, AL
Composite Index:	 94.1

State Name:		Twin, Falls, ID
Composite Index:	 91.5

State Name:		Tyler, TX
Composite Index:	 95.8

State Name:		Valdosta, GA
Composite Index:	 94.7

State Name:		Vancouver, WA
Composite Index:	 96.1

State Name:		Vero, Beach-Indian, River, FL
Composite Index:	 96.9

State Name:		Waco, TX
Composite Index:	 89.2

State Name:		Washington-Arlington-Alexandria, DC-VA
Composite Index:	139.8

State Name:		Waterloo-Cedar, Falls, IA
Composite Index:	 92.1

State Name:		Wausau, WI
Composite Index:	 96.6

State Name:		Weatherford, TX
Composite Index:	 91.4

State Name:		Wichita, Falls, TX
Composite Index:	 87.0

State Name:		Wichita, KS
Composite Index:	 92.0

State Name:		Williamsport-Lycoming, Co, PA
Composite Index:	100.0

State Name:		Wilmington, DE
Composite Index:	105.3

State Name:		Wilmington, NC
Composite Index:	 98.7

State Name:		Winchester, VA-WV
Composite Index:	101.7

State Name:		Winston-Salem, NC
Composite Index:	 92.0

State Name:		Wooster, OH
Composite Index:	 92.7

State Name:		Yakima, WA
Composite Index:	 97.4

State Name:		York, County, PA
Composite Index:	101.6

State Name:		Youngstown-Warren, OH
Composite Index:	 89.8

State Name:		Yuma, AZ
Composite Index:	102.1

State Name:		
Composite Index:	102.1

The Min:		 84.0	Pryor, Creek, OK
The Max:		214.2	New, York, (Manhattan), NY */
