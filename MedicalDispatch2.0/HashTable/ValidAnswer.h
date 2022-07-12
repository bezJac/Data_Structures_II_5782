#pragma once
#include "DecisionTreeNode.h"
#include <iostream>
#include <string>
using namespace std;

class DecisionTreeNode;
//Answer: for each answer, the string, and the pointer to the node where to continue
class ValidAnswer
{
public:
	string ans;
	DecisionTreeNode* son;
	ValidAnswer(string s, DecisionTreeNode* p) { ans = s; son = p; }
};
