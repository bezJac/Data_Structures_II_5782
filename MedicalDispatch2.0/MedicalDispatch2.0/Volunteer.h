#pragma once
#include <string>
#include <list>
#include <iostream>
using namespace std;

// object represents a volunteer
class Volunteer
{
public:
	string name;
	string phone;
	string address;
	// list of names of clients helped by volunteer
	list<string> clientsHelped;

	Volunteer();
	~Volunteer();
	Volunteer& operator=(const Volunteer&);
	bool operator==(const Volunteer&)const;
	friend ostream& operator<<(ostream&, const Volunteer&);
	friend istream& operator>>(istream&, Volunteer&);

};


