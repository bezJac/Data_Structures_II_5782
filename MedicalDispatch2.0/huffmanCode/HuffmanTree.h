#pragma once
#include "HuffmanNode.h"
#include <queue>

class HuffmanTree
{
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareNode> pQueue;
	HuffmanNode* root;
	int charCount=0;
public:
	HuffmanTree(){}
	void buildTree(string );
	void printCodes(HuffmanTree* t) { string codes; printCodes(t->root, codes); }
	void PrintTreeStructure(HuffmanTree* t) { PrintTreeStructure(t->root); }

private:
	void printCodes(HuffmanNode* root, string str);
	void PrintTreeStructure(HuffmanNode* root);
	void buildPriorityQueue(string str);
	
};