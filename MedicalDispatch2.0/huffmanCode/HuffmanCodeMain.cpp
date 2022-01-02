// Menachem Heller 305567943
// Bezalel Jacober 312033236

#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanTree.h"
using namespace std;


int main()
{
	char choice;
	string word;
	string build;
	string letters;
	int num;
	HuffmanTree* t = new HuffmanTree();
	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 'E':
		{
			cout << "enter the original text" << endl;
			cin.ignore();
			getline(cin, word);
			cout << "The encoded string is " << endl;
			t->buildTree(word);
			cout << t->GetTreeCount();
			cout << endl;
			t->printOrderOfTree();
			cout << endl;
			t->PrintTreeStructure();
			cout << endl;
			t->printCodes(word);
			cout << endl;

			break;
		}
		case 'D':
		{
			cout << "enter n\n";
			cin >> num;
			cout << "enter the letters\n";
			cin.ignore();
			getline(cin, letters);
			cout << "enter the encoded structure\n";
			cin >> build;
			cout << "enter the encoded text\n";
			cin >> word;
			if (!t->checkIfLegalTree(build, num))
			{
				cout << "ERROR\n";
			}
			else
			{
				t->createTreeFromStructure(build, letters);
				cout << "The decoded string is\n";
				cout << t->decodeToText(word);
				cout << endl;
			}
			break;
		}
		default:
			break;
		}
		t->clearQueue();
	} while (choice != 'X');

	t->~HuffmanTree();
	cout << "bye";
	return 0;
}