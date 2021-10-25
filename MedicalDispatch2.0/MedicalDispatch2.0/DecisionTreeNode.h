#pragma once
#include "Tree.h"
#include "ValidAnswer.h"
#include <string>
using namespace std;

///Node: each node in the decision tree
class DecisionTreeNode
{
public:
	list<ValidAnswer*> answersList;
	string value;
	bool isLeaf;
	DecisionTreeNode(string v) { isLeaf = true;  value = v; }

	friend class Tree;
};

