#pragma once

#include <iostream>
#include <list>
#include <string>
#include "DecisionTreeNode.h"
using namespace std;


///Tree: the Decision Tree
class Tree
{
private:
	DecisionTreeNode* root;
	bool searchAndPrint(DecisionTreeNode* p, string val);
	DecisionTreeNode* search(DecisionTreeNode* p, string val, DecisionTreeNode*& parent);
	void print(DecisionTreeNode* p, int level = 0);
	void process(DecisionTreeNode* p);
public:
	Tree();
	~Tree();
	void addRoot(string newval);
	bool addSon(string fatherquestion, string newanswer, string newval);
	void searchAndPrint(string val);
	void searchAndPrintArea(string val);
	void printAllTree();
	void process();
	string printToString(DecisionTreeNode* p);
	string printToString();
	void deleteAllSubTree(DecisionTreeNode* t);
	void deleteSubTree(string val);
};


