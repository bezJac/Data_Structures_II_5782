#pragma once
#include "HashTable.h"
#include "Volunteer.h"

class HashVolunteer :public HashTable <Volunteer, string>
{
public:

	HashVolunteer(int num) :HashTable(num) {};
	~HashVolunteer() {};
	int Hashfunc1(string);
	int Hashfunc2(string);



private:

};


