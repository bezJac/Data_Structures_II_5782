#include "Volunteer.h"



Volunteer::Volunteer(){}

Volunteer::~Volunteer(){}

Volunteer& Volunteer::operator=(const Volunteer& vol)
{
	name = vol.name;
	address = vol.address;
	phone = vol.phone;
	return *this;
}

bool Volunteer::operator==(const Volunteer& vol)const
{
	return name == vol.name;
}

ostream& operator<<(ostream& os, const Volunteer& vol)
{
	os << vol.name << ":volunteer ";
	os << "name=" << vol.name;
	os << " phone=" << vol.phone;
	os << " address=" << vol.address;
	return os;
}
istream& operator>>(istream& is, Volunteer& vol)
{
	cout << "Enter volunteer name phone address\n";
	is >> vol.name  >> vol.phone >> vol.address;
	return is;
}
