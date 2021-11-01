#pragma once
#include "HashTable.h"
#include "Volunteer.h"


// implementation of template class HashTable<T,K> for Volunteer objects
// name of volunteer used as key for hashing functionality
class HashVolunteer :public HashTable <Volunteer, string>
{
public:

	HashVolunteer(int num) :HashTable(num) {}
	int Hashfunc1(string name )
	{
		int res = ConvertStringToNum(name);
		return  res % size;
	}
	int Hashfunc2(string name)
	{
		int res = ConvertStringToNum(name);
		return (res % (size - 1) + 1) % size;
	}

	// convert a string to a numeric value
	// returns int
	int ConvertStringToNum(string name)
	{
		int res = 0;
		for (int i = 0; i < name.size(); i++)
			res += (int)name[i];
		return res;
	}
};


