#include "Client.h"
#include <iostream>
using namespace std;

Client::Client() {}

Client::~Client() {}
istream& operator>>(istream& is, Client& other)
{
	cout << "enter name:";
	is >> other.name;
	cout << "enter phone number:\n";
	is >> other.phone;
	cout << "enter street address:\n";
	is >> other.address;
	cout << "enter city:\n";
	is >> other.city;
	return is;

}
ostream& operator<<(ostream& os, const Client& other)
{
	os << "name is: " << other.name;
	os << "phone is " << other.phone;
	os << "address is: " << other.address << " " << other.city;
	return os;
}
Client& Client::operator=(const Client& other)
{
	name = other.name;
	phone = other.phone;
	address = other.address;
	city = other.city;
	return *this;
}
bool Client::operator==(const Client& other)
{
	return name == other.name;
