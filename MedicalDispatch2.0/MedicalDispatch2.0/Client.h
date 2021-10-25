#pragma once
#include <string>
#include <iostream>
#include <list>
using namespace std;

class Client
{
public:
	Client();
	~Client();
	friend ostream& operator<<(ostream&, const Client&);
	friend istream& operator>>(istream&, Client&);
	Client& operator=(const Client&);
	bool operator==(const Client&);
private:
	string name;
	string address;
	string phone;
	string city;
	list<string> volunteers;

};
#pragma once
