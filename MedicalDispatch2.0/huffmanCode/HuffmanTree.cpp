#include "HuffmanTree.h"
#include"HuffmanNode.h"
#include <string>

  HuffmanTree::~HuffmanTree()
{
	clearTree(root);
}

void HuffmanTree::buildTree(string str)
{
	buildPriorityQueue(str);
	for (int i = 0; i < charCount-1; i++)
	{
		HuffmanNode* temp1 = pQueue.top();
		pQueue.pop();
		HuffmanNode* newNode = new HuffmanNode(temp1, pQueue.top());
		pQueue.pop();
		pQueue.push(newNode);
	}
	root= pQueue.top();

}

void HuffmanTree::buildPriorityQueue(string str)
{
	charCount = 0;
	for ( string temp = "a"; temp[0] <= 'z'; temp[0]++)
	{
		int frequency = countFrequency(str,temp[0]);
		if (frequency > 0)
		{
			charCount++;
			pQueue.push(new HuffmanNode(frequency,temp));
		}
	}
	int space = countFrequency(str, ' ');
	if (space > 0)
	{
		string spaceStr = " ";
		charCount++;
		pQueue.push(new HuffmanNode(space, spaceStr));
	}
}

void HuffmanTree::printOrderOfTree(HuffmanNode* root)
{
	

		if (root == NULL)
			return;
		printOrderOfTree(root->left);
		if (root->str != "")
			cout << root->str;
		printOrderOfTree(root->right);
	
}

int HuffmanTree::countFrequency(string str, char ch)
{
	int count = 0;
	for (int i= 0; i < str.length(); i++)
	{
		if (str[i] == ch)
			++count;
	}
	return count;
}



void HuffmanTree::clearTree(HuffmanNode* root)
{
	if (root->left == NULL && root->right == NULL)
	{
		delete root;
		return;
	}
	clearTree(root->left);
	clearTree(root->right);
	delete root;
}

void HuffmanTree::printCodes(HuffmanNode* root, string code, char ch)
{
	if (root == NULL)
		return;
	if (root->str[0] == ch)
		cout << code;
	printCodes(root->left, code + "0",ch);
	printCodes(root->right, code + "1",ch);
}

void HuffmanTree::PrintTreeStructure(HuffmanNode* root)
{
	
		if (root->left == NULL && root->right == NULL)
		{
			cout << 1;
			return;
		}
		if (root->left != NULL)
		{
			cout << 0;
			PrintTreeStructure(root->left);
		}
		if (root->right != NULL)
			PrintTreeStructure(root->right);

	
}

int HuffmanTree::decodeToText(string code, HuffmanNode* t, string* result)
{
	int size = 0;
	for (int i = 0; i <= code.length(); i++)
	{
		if (t->left == NULL && t->right == NULL)
		{
			*(result) += t->str;
			return size;
		}
		if (code[i] == '0')
		{
			t = t->left;
			size++;
		}
		if (code[i] == '1')
		{
			t = t->right;
			size++;
		}
	}
}

string HuffmanTree::createTreeFromStructure(string structure, string* const& letters, HuffmanNode* root)
{
	if (structure[0] == '0')
	{
		root->left = new HuffmanNode(0);
		root->right = new HuffmanNode(0);
		structure=createTreeFromStructure(structure.substr(1), letters, root->left);
		structure=createTreeFromStructure(structure.substr(1), letters, root->right);
	}

	else if (structure[0] == '1')
	{
		root->str = letters->at(0);
		*letters = letters->substr(1);
	}
	return structure;
}



