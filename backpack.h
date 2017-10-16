/*********************
*Eric Dost
*CPSC 1020-001, F16
*Assignment 4 Extra Credit
*edost
*********************/

#ifndef BACKPACK_H
#define BACKPACK_H

#include "person.h"

using namespace std;
class backpack
{
	private:
		string iName[10];
		int hpEffect[10];
		string statEffect[10];
	public:
		backpack();
		void init(string [10], int [10], string [10]);
		~backpack();
		void content();
		void addWater(int);
		void addFood(int);
		void addMedicine(int);
		void useWater(int, vector<person>&);
		void useFood(int, vector<person>&);
		void useMedicine(int, vector<person>&);
		string whatisit(int);
};

#endif
