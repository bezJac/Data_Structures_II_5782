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
	void createTreeFromStructure(string structure, string letters) 
	{ createTreeFromStructure(structure, &letters, root); }
	string decodeToText(string code)
	{
		int count = 0;
		string str = code;
		string result;
		for (int i = 0; i <= code.size(); i += count)
		{
			str = str.substr(count);
			count = decodeToText(str, root,&result);
		}
		return result;
	}
	bool checkIfLegalTree(string str,int num)
	{
		int count = 0;
		for (int i = 0; i <= str.size(); i++)
		{
			if (str[i] == '1')
				++count;
		}
		if (count == num)
			return  true;
		else
			return false;
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