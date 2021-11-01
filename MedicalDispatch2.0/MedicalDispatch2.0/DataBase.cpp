#include "DataBase.h"
#include <list>
#include <algorithm>

// implementation of DataBase class

void DataBase::addVolunteer(Volunteer vol)
{
	volunteers.Add(vol,vol.name);
}
void DataBase::delVolunteer(Volunteer vol)
{
	volunteers.Delete(vol.name);
}
void DataBase::addClient(Client cl)
{
	clients.Add(cl, cl.phone);
}
void DataBase::delClient(Client cl)
{
	clients.Delete(cl.phone);
}

// add a volunteer and a client connection
void DataBase::addVolunteerToClient(Volunteer vol, Client cl)
{
	list<string>::iterator it;
	int index = clients.Search(cl.phone);
	int volIndex = volunteers.Search(vol.name);
	if (index == -1 || volIndex == -1)				 // either one not in table
		cout << "ERROR\n";
	else
	{
		// check if  volunteer is  not already linked to client
		it = find_if(clients.table[index].data.helpedByVolunteers.begin(), clients.table[index].data.helpedByVolunteers.end(), [vol](string& name) {return name == vol.name; });

		if (it != clients.table[index].data.helpedByVolunteers.end()) // volunteer found in list
			cout << "ERROR\n";
		else
		{
			volunteers.table[volIndex].data.clientsHelped.push_back(clients.table[index].data.name);
			clients.table[index].data.helpedByVolunteers.push_back(vol.name);
		}
	}
}

// print a specific client's list of  volunteers with connection
void DataBase::listOfVolunteers(Client cl)
{
	cout << "The volunteers that helped to client " << cl.phone << ":  ";
	int index = clients.Search(cl.phone);			// get index of client in table
	if(index != -1)									// if client exists
		for_each(clients.table[index].data.helpedByVolunteers.begin(), clients.table[index].data.helpedByVolunteers.end(), [](string& vol) {cout << vol; cout  << ' '; });
}

// print a specific volunteer's list of  vclients with connection
void DataBase::listOfClients(Volunteer vol)
{
	cout << "The clients that were helped by volunteer " << vol.name << ": ";
	// iterate through entire client table
	for (int i = 0; i < clients.size; i++)
	{
		if (clients.table[i].flag == full) // check al existing client
		{
			list<string>::iterator it = clients.table[i].data.helpedByVolunteers.begin();
			while(it !=  clients.table[i].data.helpedByVolunteers.end())
			{
				if ((*it) == vol.name)			// volunteer's name in current clients list
				{
					cout << clients.table[i].data.name << ' ';
					break;
				}
				it++;
			}	
		}
	}
}

// print both clients and volunteers tables
void DataBase::printHashTables()
{
	cout << "Volunteers:\n";
	volunteers.Print();
	cout << "\nClients:\n";
	clients.Print();
}
