#include "Client.h"


// implementation for client class 


Client::Client() {}
Client::~Client() {}

istream& operator>>(istream& is, Client& other)
{
	cout << "please enter name and phone and address of client\n";
	is >> other.name >> other.phone	 >> other.address;
	return is;

}
ostream& operator<<(ostream& os, const Client& other)
{
	os << other.phone << ":client ";
	os << "name: " << other.name;
	os << " phone: " << other.phone;
	os << " address: " << other.address;
	return os;
}
Client& Client::operator=(const Client& other)
{
	name = other.name;
	phone = other.phone;
	address = other.address;
	return *this;
}
bool Client::operator==(const Client& other)
{
	return phone == other.phone;
}
