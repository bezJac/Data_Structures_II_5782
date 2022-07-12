#pragma once
#pragma once
#include <iostream>
#include <vector>
using namespace std;


// enum representing states of an elemnt in hash Table
enum state { Empty, full, deleted };


// template class representing an element in a  Hash table
template <typename T, typename K>
class Item
{
public:
	T data;            // value
	K key;			  // key for hashing functionality
	state flag;		  // current state of location containning item in the hash table

	Item() { flag = Empty; }
	Item(T d, K k, state f) { data = d; key = k; flag = f; }
};



// object represents a hash table
template <typename T, typename K>
class HashTable
{
public:
	Item<T, K> *table;
	int size;

	HashTable(int size);
	~HashTable();
	bool isPrime(int);
	virtual int Hashfunc1(K) = 0;
	virtual int Hashfunc2(K) = 0;
	int Hash(K, int);
	int Search(K k);
	void Add(T, K);
	void Delete(K k);
	void Print();




};





// check if a number is a  prime number. 
// returns bool
template <typename T, typename K>
bool HashTable<T, K>::isPrime(int n)
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


// cunstroctor 
// instantiates table  size to nearest prime number to the left of size
template <typename T, typename K>
HashTable<T, K>::HashTable(int size)
{
	// increase size value to nearest greater prime number to parameter size
	while (!isPrime(size))
		size++;
	this->size = size;
	table = new Item<T, K>[size];
}



// destructor
template <typename T, typename K>
HashTable<T,K>::~HashTable()
{
	delete[] table;
}


// search for a vlaue in hash table by its key
template <typename T, typename K>
int HashTable<T,K>::Search(K k)
{
	int counter = 0;
	int index;
	do
	{
		// calculate expected location index in hash table
		index= Hash(k, counter); 

		if (table[index].key == k && table[index].flag == full)
			return index;		
		else
			counter++;

	} while(counter < size && table[index].flag != Empty);
	return -1;   //if the item wasn't found
}


// calculate location index of an item in hash table
// returns index
template <typename T, typename K>
int HashTable<T, K>::Hash(K k, int i )
{
	return (Hashfunc1(k) + i * Hashfunc2(k)) % size;
}

// insert an item into hash table
template <typename T, typename K>
void HashTable<T, K>::Add(T d,K k)
{
	int time = 0;
	Item<T, K> item(d, k, full);
	int index;
	do
	{
		index = Hash(k, time);  // calculate an index to check state for insert
		if (table[index].flag == Empty || table[index].flag == deleted)
		{
			table[index].data = item.data;
			table[index].key = item.key;
			table[index].flag = item.flag;
			return;
		}
		time++;					// current index is full
	} while (time < size);

	// table overflow, no available location to insert
	cout << "hash table overflow\n";
}

// delete an item from hash table - identified by its key
template <typename T, typename K>
void HashTable < T, K>::Delete(K k)
{
	// find value's index  in the table
	int index = Search(k);

	// item not found
	if (index == -1) 
	{
		cout << "ERROR";
		return;
	}

	// set location in table to deleted - insertion is now allowed at index
	table[index].flag = deleted;
}

// print content the of hash table
template <typename T, typename K>
void  HashTable < T, K>::Print()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].flag == full)			// print only current items in table
			cout << table[i].data << ' ';
	}
}

