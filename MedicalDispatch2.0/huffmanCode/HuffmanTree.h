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
	void buildPriorityQueue(string str);

	
};