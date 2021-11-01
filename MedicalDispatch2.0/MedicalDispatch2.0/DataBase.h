#pragma once
#include "Client.h"
#include "Volunteer.h"
#include "HashClient.h"
#include "HashVolunteer.h"


// object represents database of volunteers and clients 
class DataBase
{
private:

	HashClient  clients = HashClient(100);					 // hash table of the  clients
	HashVolunteer volunteers = HashVolunteer(100);			 // hash table of volunteers

public:

	void addVolunteer(Volunteer);
	void delVolunteer(Volunteer);
	void addClient(Client);
	void delClient(Client);
	void addVolunteerToClient(Volunteer, Client);
	void listOfVolunteers(Client);
	void listOfClients(Volunteer);
	void printHashTables();
	
};