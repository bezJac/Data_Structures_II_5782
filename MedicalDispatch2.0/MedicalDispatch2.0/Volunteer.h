#pragma once
#include <string>
#include <iostream>
using namespace std;
class Volunteer
{
public:
	Volunteer();
	~Volunteer();
	Volunteer& operator=(const Volunteer&);
	bool operator==(const Volunteer&)const;
	friend ostream& operator<<(ostream&, const Volunteer&);
	friend istream& operator>>(istream&, Volunteer&);

private:
	string name;
	string address;
	string city;
	string phone;

};


