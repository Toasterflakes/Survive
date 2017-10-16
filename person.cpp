/************************
*Eric Dost
*CPSC 1020-001, F16
*Assignment 4 Extra Credit
*edost
************************/

#include "person.h"
#include "backpack.h"
#include "days.h"

using namespace std;
person::person() //default constructor. set values to 0
: name(" "), health(0), status("Healthy")
{}

person::person(string str, int num, string stat)
: name(str), health(num), status(stat) // reg constructor
{}

person::~person()//destructor
{}

void person::printInfo() // print out stats of the person
{
	if(health > 0 ) status = "\x1B[32mHealthy\x1B[0m";
	cout << endl << name << endl << "Health: \x1B[31m" << health << "%\x1B[0m" ;
	cout << endl << "Status: " << status << endl;
}

void person::water() // add 30 hp. if hp goes over 100, set hp to 100
{
	health+= 30;
	if(health > 100) health = 100;
}

void person::food() // add 50 hp
{
	health+= 50;
	if(health > 100) health = 100;
}

void person::medicine() // add 75 hp
{
	health+= 75;
	if(health > 100) health = 100;	
	status = "Healthy";
}

void person::dailyLoss() // call randomizer to reduce the person's hp 
{
	int num;

	if(status == "sick") num = cfind();
	else num = hfind();	

	health-=num;
}

int person::getHealth() // getter method for the person's current hp
{
	return health;
}

void person::setStat() // if hp is less than 1, the person is dead
{
	status = "\x1B[31mDead\x1B[0m";
	health = 0;
}
