#pragma once
#include "HuffmanNode.h"
#include <queue>

class HuffmanTree
{
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	HuffmanNode* root;
	int charCount;

public:
	HuffmanTree() { root = new HuffmanNode(0),charCount=0; }
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
	void createTreeFromStructure(string structure, string letters) { createTreeFromStructure(structure, &letters, root); }
	void decodeToText(string code)
	{
		int count = 0;
		string str = code;
		for (int i = 0; i <= code.size(); i += count)
		{
			str = str.substr(count);
			count = decodeToText(str, root);
		}
	}
private:
	int decodeToText(string code, HuffmanNode* t);
	string createTreeFromStructure(string structure, string* const& letters, HuffmanNode* t);
	void printCodes(HuffmanNode* root, string str, char ch);
	void PrintTreeStructure(HuffmanNode* root);
	void buildPriorityQueue(string str);
	void printOrderOfTree(HuffmanNode* root);
	int countFrequency(string, char);

};