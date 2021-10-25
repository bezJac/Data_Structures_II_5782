#pragma once
#include "HashTable.h"
#include "Client.h"
class HashClient : HashTable<Client, string>
{
public:
	HashClient(int num);
	~HashClient();
	int Hashfunc1(string);
	int Hashfunc2(string);
	int Hash(string, int);
	int Search(string);
	void Delete(string);
}; 