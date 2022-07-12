#pragma once
#include "HuffmanNode.h"
#include <queue>

class HuffmanTree
{
private:
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	HuffmanNode* root;
	// numer of leafs in tree
	int charCount;


	// public functions
	// +b overload methods that call matching private methods to avoid outside access to root of tree
public:
	HuffmanTree() { root = new HuffmanNode(0),charCount=0; }
	~HuffmanTree();
	int GetTreeCount() { return charCount; }
	void buildTree(string);
	void printCodes(string input)
	{
		string codes;
		for (int i = 0; i < input.size(); i++)
			printCodes(root, codes, input[i]);
	}
	void PrintTreeStructure() { PrintTreeStructure(root); }
	void printOrderOfTree() { printOrderOfTree(root); } 
	void createTreeFromStructure(string structure, string letters) 	{ createTreeFromStructure(structure, &letters, root);}
	string decodeToText(string code);
	bool checkIfLegalTree(string str, int num);	
	void clearQueue()
	{
		while (!pQueue.empty())
			pQueue.pop();
	}

private:
	int decodeToText(string code, HuffmanNode* t,string* str);
	string createTreeFromStructure(string structure, string* const& letters, HuffmanNode* t);
	void printCodes(HuffmanNode* root, string str, char ch);
	void PrintTreeStructure(HuffmanNode* root);
	void buildPriorityQueue(string str);
	void printOrderOfTree(HuffmanNode* root);
	int countFrequency(string, char);	
	void clearTree(HuffmanNode* );
};