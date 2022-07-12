#pragma once
#include "HashTable.h"
#include "Client.h"


// implementation of template class HashTable<T,K> for Client objects
// phone number of client used as key for hash functionality
class HashClient :public HashTable<Client, string>
{
public:
	HashClient(int num) :HashTable(num) {}

	int Hashfunc1(string phone)
	{
		// convert string representstion of phone number to its numeric value
		// first 0 excluded
		long res = stoi(phone);
		return  res % size;
	}
	int Hashfunc2(string phone)
	{
		// convert string representstion of phone number to its numeric value
		// first 0 excluded
		long res = stoi(phone);
		return (res % (size - 1) + 1) % size;
	}
	
}; 