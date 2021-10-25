#include "Volunteer.h"

Volunteer::Volunteer()
{

}

Volunteer::~Volunteer()
{
}

Volunteer& Volunteer::operator=(const Volunteer& vol)
{
	name = vol.name;
	address = vol.address;
	city = vol.city;
	phone = vol.phone;
	return *this;
}

bool Volunteer::operator==(const Volunteer& vol)const
{
	return name == vol.name;
}

ostream& operator<<(ostream& os, const Volunteer& vol)
{
	os << "name is : " << vol.name << "\n";
	os << "phone is: " << vol.phone << "\n";
	os << "address : " << vol.address << "\n";
	os << "city:" << vol.city << "\n";
	return os;
}
istream& operator>>(istream& is, Volunteer& vol)
{
	cout << "enter name\n";
	is >> vol.name;
	cout << "enter phone number\n";
	is >> vol.phone;
	cout << "enter address\n";
	is >> vol.address;
	cout << "enter city\n";
	is >> vol.city;

	return is;
}