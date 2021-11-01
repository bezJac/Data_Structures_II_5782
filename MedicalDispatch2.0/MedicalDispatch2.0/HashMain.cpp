// Menachem Heller 305567943
// Bezalel Jacober 312033236

#include <iostream>
#include <string>
#include "Client.h"
#include "Volunteer.h"
#include "HashClient.h"
#include "HashVolunteer.h"
#include "DataBase.h"
using namespace std;

int main()
{
	char ch;
	Volunteer v;
	Client c;
	list<Volunteer*> lst;
	DataBase ht;

		cout << "Hash Tables\n";
	do
	{
		cout << "\nChoose one of the following" << endl;
		cout << "n: New volunteer" << endl;
		cout << "d: Del a volunteer " << endl;
		cout << "c: New client" << endl;
		cout << "l: Add a connection volunteer-client " << endl;
		cout << "*: Print volunteers that helped a client " << endl;
		cout << "i: Print clients that were helped by a voluneer " << endl;
		cout << "p: Print hash tables " << endl;
		cout << "e: Exit " <<  endl;
		cin >> ch;
		switch (ch)
		{
		case 'n':cin >> v; ht.addVolunteer(v);  break;
		case 'd': cout << "enter volunteer name "; cin >> v.name; ht.delVolunteer(v);  break;
		case 'c': cin >> c; ht.addClient(c); break;
		case 'l': cout << "enter volunteer name and client phone ";  cin >> v.name >> c.phone; ht.addVolunteerToClient(v, c); break;
		case '*': cout << "enter client phone ";  cin >> c.phone; ht.listOfVolunteers(c); break;
		case 'i': cout << "enter volunteer name ";  cin >> v.name; ht.listOfClients(v); break;
		case 'p': ht.printHashTables(); break;
		case 'e':cout << "bye "; break;
		default: cout << "Error ";  break;
		}
	} while (ch != 'e');
	return 0;
		
}

/*
* Hash Tables

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
n
Enter volunteer name phone address
avraham 123 haifa

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
n
Enter volunteer name phone address
issac 234 afula

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
n
Enter volunteer name phone address
yaacov 345 natania

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
c
please enter name and phone and address of client
reuven 1234 haifa

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
c
please enter name and phone and address of client
shimon 2345 jerusalem

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
c
please enter name and phone and address of client
levi 3456 afula

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
p
Volunteers:
issac:volunteer name=issac phone=234 address=afula avraham:volunteer name=avraham phone=123 address=haifa yaacov:volunteer name=yaacov phone=345 address=natania
Clients:
1234:client name: reuven phone: 1234 address: haifa 2345:client name: shimon phone: 2345 address: jerusalem 3456:client name: levi phone: 3456 address: afula
Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
l
enter volunteer name and client phone avraham 1234

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
l
enter volunteer name and client phone avraham 3456

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
l
enter volunteer name and client phone isaac 1234
ERROR

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
l
enter volunteer name and client phone isaac 2345
ERROR

Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
p
Volunteers:
issac:volunteer name=issac phone=234 address=afula avraham:volunteer name=avraham phone=123 address=haifa yaacov:volunteer name=yaacov phone=345 address=natania
Clients:
1234:client name: reuven phone: 1234 address: haifa 2345:client name: shimon phone: 2345 address: jerusalem 3456:client name: levi phone: 3456 address: afula
Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
*
enter client phone 123
The volunteers that helped to client 123:
Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
*
enter client phone 1234
The volunteers that helped to client 1234:  avraham isaac
Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
i
enter volunteer name avraham
The clients that were helped by volunteer avraham: reuven levi
Choose one of the following
n: New volunteer
d: Del a volunteer
c: New client
l: Add a connection volunteer-client
*: Print volunteers that helped a client
i: Print clients that were helped by a voluneer
p: Print hash tables
e: Exit
e
bye
C:\Users\mybj2\source\repos\DAST-2021\MedicalDispatch2.0\Debug\MedicalDispatch2.0.exe (process 7740) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/