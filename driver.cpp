/**************************
*Eric Dost
*CPSC 1020-001, F16
*Assignment 4 Extra Credit
*edost
**************************/

#include "days.h"
#include "person.h"
#include "backpack.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>

void fillPeople(ifstream&, vector<person>&);
void fillBackpack(ifstream&, backpack&);

int dayCount; // global int to count which day it is

using namespace std;
int main(int argc, char** argv)
{
	ifstream in(argv[1]); // open the file
	vector<person> arr; // vector of person objects
	backpack back; // backpack object

	// print the intro to the game
	cout << endl << "You're the last 3 people alive in your town after a" <<
	" devistating nuclear fallout.\nAll you have left is a backpack" <<
	" filled with a few" <<
	" important items.\nIt could be up to a month" <<
	" before anyone finds you.\n" << "...\n...\n...\n";

	fillPeople(in, arr); // initialize and read in data for person objects

	fillBackpack(in, back); // read in data for the backpack

	in.close(); //close the file

	for(int i = 0; i < 3; i++)
	{
		arr[i].printInfo(); // print out the stats of each person
	}

	back.content();	// print out the contents of the backpack

	char choice; 

	// askt he user if they are ready to play
	cout << endl << "Are you ready to survive? (y/n) ";
	cin >> choice;

	int lep = 0;

	if(choice == 'y')
	{
		lep = start(back, arr); // start the game; day 1
	}

	if(lep < 30 && lep > 0)
	{				// tell the player what day they died on
		cout << endl << "\x1B[31mYou died on day " << lep -1 << "\x1B[0m";
	}else if(lep > 29){
	 cout << endl << "They found you!" << endl; // yay! congratulate the play for winning
	sleep(1); // pause for 1 second for dramatic effect
	cout << "You're saved...\n"; //
	}
		// bye bye!
	cout << endl << "\n\tThanks for playing" << endl << endl;

	return 0; // end main()
}

void fillPeople(ifstream& in, vector<person>& arr)
{
	string name;
	int hp;
	string stat;

	for(int i = 0; i < 3; i++)
	{	
		in >> name; // read in to temp variables
		in >> hp;
		in >> stat;
	
		person po(name, hp, stat); // call constructor

		arr.push_back(po); // put the object in the array
	}
} //end

void fillBackpack(ifstream& in, backpack& back)
{
	string name[10];
	int hp[10];
	string stat[10];

	for(int i = 0; i < 4; i++)
	{
		in >> name[i]; // read in to temp variables arrays
		in >> hp[i];
		in >> stat[i];
	}

	for(int i = 4; i < 10; i++)
	{
		name[i] = " "; // fill the rest of the elements - default values
		hp[i] = 0;
		stat[i] = " ";
	}
	
	back.init(name, hp, stat); // pass arrays to the backpack
}
