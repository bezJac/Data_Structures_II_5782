#pragma once
#include <string>
#include <iostream>
#include <list>
#include "Volunteer.h"
using namespace std;


// object represents a client
class Client
{
public:
	string name;
	string address;
	string phone;
	// names of voleenters that helped the client
	list<string> helpedByVolunteers;
	
	Client();
	~Client();
	friend ostream& operator<<(ostream&, const Client&);
	friend istream& operator>>(istream&, Client&);
	Client& operator=(const Client&);
	bool operator==(const Client&);

	

};

