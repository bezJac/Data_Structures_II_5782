#pragma once
#include "HuffmanNode.h"
#include <queue>

class HuffmanTree
{
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	HuffmanNode* root;
	int charCount = 0;
	
public:
	HuffmanTree(){}
	int GetTreeCount() { return charCount; }
	void buildTree(string );
	void printCodes(HuffmanTree* t,string input)
	{ string codes; 
	for(int i=0;i<input.size();i++)
		printCodes(t->root, codes,input[i]); 
	}
	void PrintTreeStructure(HuffmanTree* t) { PrintTreeStructure(t->root); }
	void printOrderOfTree(HuffmanTree* t) { printOrderOfTree(t->root); }
private:
	void printCodes(HuffmanNode* root, string str,char ch);
	void PrintTreeStructure(HuffmanNode* root);
	void buildPriorityQueue(string str);
	void printOrderOfTree(HuffmanNode* root);
	
};