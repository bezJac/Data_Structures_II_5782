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
			cin >> word;
			
			t->buildTree(word);
			cout << t->GetTreeCount();
			cout << endl;
			t->printOrderOfTree(t);
			cout << endl;
			t->PrintTreeStructure(t);
			cout << endl;
			t->printCodes(t,word);
			
			
			break;
		}
		//Build Huffman tree given the data inside "word".
		//Then find the code of each letter.
		//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.
		

		case 'D':
		{
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 
			break;

		}
		default:
			break;
		}

	} while (choice != 'X');
	return 0;
}