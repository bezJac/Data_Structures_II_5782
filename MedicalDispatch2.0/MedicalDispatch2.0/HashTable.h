#pragma once
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;



template <class T, class K>
class HashTable
{
private:
	Item<T, K>* table = new Item<T, K>[];
	bool isPrime(int n);
	int  nextPrime(int n);
	int length = 0;
public:
	HashTable(int size);
	~HashTable();
	virtual int Hashfunc1(K) = 0;
	virtual int Hashfunc2(K) = 0;
	virtual int Hash(K, int);
	virtual int Search(K);
	void Add(Item<T, K>);
	virtual void Delete(K k);
	void Print();




};






template<class T, class K>
HashTable< T, K>::HashTable(int size)
{
	length = nextPrime(size);
	table = new Item< T, K>[length];


}

template<class T, class K>
HashTable< T, K>::~HashTable()
{
	if (length > 0)
		delete table[];
}

template<class T, class K>
bool HashTable< T, K>::isPrime(int n)
{
	// Corner cases
	if (n <= 1) return false;
	if (n <= 3) return true;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
template<class T, class K>
int HashTable< T, K>::nextPrime(int n)
{
	// Base case
	if (n <= 1)
		return 2;

	int prime = n;
	bool found = false;

	// Loop continuously until isPrime returns
	// true for a number greater than n
	while (!found) {
		prime++;

		if (isPrime(prime))
			found = true;
	}

	return prime;
}
template<class T, class K>
int HashTable< T, K>::Hash(K k, int i)
{
	return(Hashfunc1(k) + i * Hashfunc2(k)) % length;
}

template<class T, class K>
int HashTable<T, K>::Search(K k)
{
	int i = 0;
	for (int j = hash(k, i); i == length || table[j].flag == empty; i++)
	{
		if (table[j].key == k)
			return j;
		i += 1;

	}
	return -1;
}
template<class T, class K>
void HashTable<T, K>::Add(Item<T, K> temp)
{

	int i = 0;
	bool flag = false;
	for (int j = hash(temp.key, i); i < length; i++)
	{
		if (table[j].status == empty || table[j].flag == deleted)
		{
			table[j].data = temp.data;
			table[j].key = temp.key;
			table[j].flag = full;
			flag = true;
			break;
		}
		i += 1;
	}
	if (!flag)
		cout << "hash table overflow\n";
}

template<class T, class K>
void HashTable < T, K>::Delete(K k)
{
	int i = Search(k);
	table[i].status = deleted;
}
template<class T, class K>
void  HashTable < T, K>::Print()
{
	for (int i = 0; i < length; i++)
	{
		if (table[i].status == full)
			cout << table[i].data;
	}
}

