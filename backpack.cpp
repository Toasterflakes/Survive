/************************
*Eric Dost
*CPSC 1020-001, F16
*Assignment 4 Extra Credit
*edost
************************/

#include "backpack.h"

using namespace std;
backpack::backpack() // default constructor
{
	for(int i = 0; i < 10; i++)
	{
		iName[i] = " ";
		hpEffect[i] = 0;
		statEffect[i] = " ";
	}

}

void backpack::init(string str[], int num[], string stat[]) // init method to fill arrays
{
	for(int i = 0; i < 10; i++)
	{
		iName[i] = str[i];
		hpEffect[i] = num[i];
		statEffect[i] = stat[i];
	}
}

backpack::~backpack() // destructor
{}

void backpack::content() // print out a list of the items in the backpack
{
	cout << endl << "\t\tBackpack\n" ;

	for(int i = 0; i < 10; i++)
	{
		cout << i+1 << ". ";
		if(iName[i] != " ")
		{
			cout << iName[i] << " -- " << "HP: +" << hpEffect[i] <<
			" -- Status effect: " << statEffect[i];
		}
		cout << endl;
	}
}

void backpack::addWater(int cnt) // add water to the backpack
{
	iName[cnt] = "water";
	hpEffect[cnt] = 30;
	statEffect[cnt] = "none";
}

void backpack::addFood(int cnt) // place food in the backpack
{
	iName[cnt] = "food";
	hpEffect[cnt] = 50;
	statEffect[cnt] = "none";
}

void backpack::addMedicine(int cnt) // place medicine in the backpack
{
	iName[cnt] = "medicine";
	hpEffect[cnt] = 75;
	statEffect[cnt] = "cures";
}

string backpack::whatisit(int num) // what's in the specified slot? return the name of item
{
	return iName[num];
}

void backpack::useWater(int n, vector<person>& po) 
{
	iName[n] = " ";// reset the value of specified slot
	hpEffect[n] = 0;
	statEffect[n] = " ";
	
	int temp = 0;

	po[0].printInfo();
	po[1].printInfo();
	po[2].printInfo();

	// ask the user which person they would like to use the water on
	cout << endl << "who do you want to use the water on?\n" <<
	"1) John\n2) Sarah\n3) Samantha\n\n";
	cin >> temp;

	if(po[temp -1].getHealth() > 0) po[temp -1].water();
}	

void backpack::useFood(int n, vector<person>& po)
{
	iName[n] = " "; // reset the values of the slot
	hpEffect[n] = 0;
	statEffect[n] = " ";
	
	int temp = 0;

	po[0].printInfo();
	po[1].printInfo();
	po[2].printInfo();

	// ask the user which person they would like to use the food on
	cout << endl << "who do you want to use the food on?\n" <<
	"1) John\n2) Sarah\n3) Samantha\n\n";
	cin >> temp;

	if(po[temp -1].getHealth() > 0) po[temp -1].food();
}	

void backpack::useMedicine(int n, vector<person>& po)
{
	iName[n] = " "; // reset the values of the slot
	hpEffect[n] = 0;
	statEffect[n] = " ";
	
	int temp = 0;

	po[0].printInfo();
	po[1].printInfo();
	po[2].printInfo();

	// ask the user which person they would like to use the medicine on
	cout << endl << "who do you want to use the medicine on?\n" <<
	"1) John\n2) Sarah\n3) Samantha\n\n";
	cin >> temp;

	if(po[temp -1].getHealth() > 0) po[temp -1].medicine();
}	
