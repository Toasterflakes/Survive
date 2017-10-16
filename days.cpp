/*************************
*Eric Dost
*CPSC 1020-001, F16
*Assignment 4 Extra Credit
*edost
*************************/

#include "days.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;
// begin day 1
int start(backpack& bo, vector<person>& po)
{
	int adv = -1;
	int sent = 0;

	static int dayCount = 1;
	// loop until day 30 ends or everyone dies
	while(dayCount < 31 && (po[0].getHealth() > 0 || 
			po[1].getHealth() > 0 || po[2].getHealth() > 0))
	{
		sent = -1;
		while(sent == -1)
		{	// print the day; ask who the players wants to send scavanging
			cout << "\n\nDay " << dayCount << endl;
			cout << endl << "Who will go out to look for supplies?" <<
			"\n1) John\n2) Sarah\n3) Samantha\n4) Nobody\n" ;
			cin >> adv;

			if(adv == 1) // check if person is dead, re-loop if dead
			{ if(po[0].getHealth() <= 0) {cout << "\nJohn is dead\n";sent = -1;}
				else 
				{	// call randomizer
					int number = rfind();
					founder(number, bo, po);// determine the result
					sent = 0;
				}
			}
			else if(adv == 2) // check if person is dead, re-loop if dead
			{ if(po[1].getHealth() <= 0) {cout << "\nSarah is dead\n";sent = -1;}
				else
				{	//call randomizer
					int number = rfind();
					founder(number, bo, po); // determine result
					sent = 0;
				}
			}
			else if(adv == 3) // check if person is dead, re-loop if dead
			{ if(po[2].getHealth() <= 0) {cout << "\nSamantha is dead\n";sent = -1;}
				else
				{	// call randomizer
					int number = rfind();
					founder(number, bo, po); // determine result
					sent = 0;
				}
			}

			else // invalid choice, end loop
			{
				sent = 0;
			}
		}
		po[0].dailyLoss(); // randomize the loss of hp
		cout << "...\n";
		sleep(1); // pause for re-seed
		po[1].dailyLoss();// randomize loss of hp
		cout << "...\n";
		sleep(1); // pause for re-seed
		po[2].dailyLoss();// randomize loss of hp

		for(int i = 0; i < 3; i++)
		{
			if(po[i].getHealth() <= 0)
			{
				po[i].setStat(); // if hp goes below 0, set to 0
			}
		}
		// print out the stats of each person
		po[0].printInfo();
		po[1].printInfo();
		po[2].printInfo();

		dayCount++;// increment day counter
	}
	return dayCount; // return day of death, or ultimate success
}

int rfind()
{
	srand(time(NULL)); // seed
	return rand() % 22 + 1; // range: 1-22
}

int cfind()
{
	srand(time(NULL));// seed
	return 	rand() % 17 + 10; // range: 10-27
}

int hfind()
{
	srand(time(NULL)); // seed
	return rand() % 25 + 5; // range: 5-30
}

void founder(int num, backpack& bo, vector<person>& po)
{
	int cnt = 0;
	if(num >= 5 && num < 10) // determine what the player found, based on random num
	{
		cout << endl << "You found some water!\n";
		sleep(1); // pase for dramatic effect
		bo.content(); // list the backpack contents
		cout << endl << "0. throw the water away\n";
		cout << endl << "which slot would you like to place the water in? "<<
		"(placing it in a filled slot will replace the item in that slot) ";
		cin >> cnt;
		// ask if use would like to keep the water
		if(cnt >= 1 && cnt <= 10)bo.addWater(cnt -1);
	}
	else if(num >= 10 && num <= 14)
	{
		cout << endl << "You found some food!\n";
		sleep(1);
		bo.content();
		cout << endl << "0. throw the food away\n";
		cout << endl << "which slot would you like to place the food in? "<<
		"(placing it in a filled slot will replace the item in that slot) ";
		cin >> cnt;

		if(cnt >= 1 && cnt <= 10)bo.addFood(cnt -1);
	}
	else if(num > 14 && num < 16)
	{
		cout << endl << "You found some medicine!\n";
		sleep(1);
		bo.content();
		cout << endl << "0. throw the medicine away\n";
		cout << endl << "which slot would you life to place the medicine in? " <<
		"(placing it in a filled slot will replace the item in that slot) ";
		cin >> cnt;

		if(cnt >= 1 && cnt <= 10)bo.addMedicine(cnt -1);
	}
	else cout << endl << "You didn't find anything today\n";
	sleep(1);
	cout << endl << "do you want to use any of your items tonight? (y/n)";
	char temp;
	int tempnum;
	cin >> temp;
	int i = 1;
	if(temp == 'y')
	{while(i != 0){
		bo.content(); // list items
		cout << endl << "which slot? ";
		cin >> tempnum; // ask user which item they want to use
		if(bo.whatisit(tempnum -1) == "water")
		{i = 0; bo.useWater(tempnum -1, po);}
		else if(bo.whatisit(tempnum -1) == "food")
		{i = 0; bo.useFood(tempnum -1, po);}
		else if(bo.whatisit(tempnum -1) == "medicine")
		{i = 0; bo.useMedicine(tempnum -1, po);}
		else {cout << endl << "There was nothing in that slot\n"; i = 1;}}	
	}	
}


