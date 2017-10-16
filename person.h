/***********************
*Eric Dost
*CPSC 1020-001, F16
*Assignment 4 Extra Credit
*edost
***********************/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class person
{
	private:
		string name;
		int    health;
		string status;
	public:
		person();
		person(string, int, string);
		~person();		
		void printInfo();
		void water();
		void food();
		void medicine();
		void dailyLoss();

		int getHealth();

		void setStat();
};


#endif
