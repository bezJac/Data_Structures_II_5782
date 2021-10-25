#include "Tree.h"


// constructor
Tree::Tree() { root = NULL; }


// destructor 
Tree::~Tree()
{
	if (root)
		deleteAllSubTree(root);
	root = NULL;
}


// add root to tree
void Tree::addRoot(string newval) { root = new DecisionTreeNode(newval); }


// add a son to existing node in tree - returns true if son was added
bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	DecisionTreeNode* dummy = NULL;
	// find node to add son to
	DecisionTreeNode* temp = search(root, fatherquestion, dummy);

	// node to add to is not in tree
	if (!temp)
		return false;

	// add son to node pointed in temp 
	// links parent (Temp), and son node with the new answer 
	// return true 
	else
	{
		DecisionTreeNode* newson = new DecisionTreeNode(newval);
		ValidAnswer* a = new ValidAnswer(newanswer, newson);
		temp->answersList.push_back(a);
		temp->isLeaf = false;
		return true;
	}
}


// private method
// find a value in the tree - returns a DecisionTreeNode containing the value
// parent node of found node also found - accsesed by reference  
DecisionTreeNode* Tree::search(DecisionTreeNode* p, string val, DecisionTreeNode*& parent)
{
	if (!p)
		parent = NULL;

	// return node if value is found
	if (p->value == val)
	{
		// value found in root - set parent to NULL
		if (p->value == root->value)
			parent = NULL;
		return p;
	}

	// loop through all of the  node's sons 
	// usees recursive call to search for node in all subtrees rooted in the sons
	DecisionTreeNode* temp = NULL;
	for (list<ValidAnswer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++)
	{
		parent = p;
		temp = search((*it)->son, val, parent);
		// node was found - end loop
		if (temp != NULL)
			break;
	}
	return temp;
}


// private method
// return true if a val sent as parameter equals a value of any node in tree
bool Tree::searchAndPrint(DecisionTreeNode* p, string val)
{
	// return true if value is found
	if (p->value == val)
		return true;
	bool exist = false;
	// if p has sons check all subtrees 
	if (!p->isLeaf)
		for (list<ValidAnswer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++)
		{
			exist = searchAndPrint((*it)->son, val);
			// end loop if value is found
			if (exist)
				break;
		}
	return exist;
}


// public method 
// print a route from a node  back to root
void Tree::searchAndPrint(string val)
{
	// check if value exist in tree - call private boolean method 
	if (!searchAndPrint(root, val))
		cout << "Value not found" << endl;
	//  call  private method to print the route
	else
		searchAndPrintArea(val);
}


// private method
// print a route from a node  back to root
void Tree::searchAndPrintArea(string val)
{
	DecisionTreeNode* parent;
	// find the node with the value and its parent
	DecisionTreeNode* area = search(root, val, parent);

	// print the value
	cout << area->value;

	// print path to root using recursive call
	// on value of parent
	if (parent)
	{
		cout << "=>";
		searchAndPrintArea(parent->value);
	}
}


// print entire tree  - public method
// calls print() and sends the root as the node to print its subtree
void Tree::printAllTree() { print(root); }


// private method
// print subtree rooted in node p sent as parameter - (with indentations)
// ( level parameter determines number of indentation to execute)
void Tree::print(DecisionTreeNode* p, int level)
{
	if (root != NULL)
	{
		// prints  node value
		cout << p->value << endl;

		//  use loop to print each answer in list
		// uses recursive call to print any subtree pointed by an answer
		if (!p->isLeaf)
			for (list<ValidAnswer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++)
			{
				for (int j = 0; j < level; j++)
					cout << ' ';
				cout << ": " << (*it)->ans << endl;
				for (int j = 0; j < level + 1; j++)
					cout << ' ';
				print((*it)->son, level + 1);
			}
	}

}

// public method 
// calls private method and sends root as node to start process from
void Tree::process() { process(root); }

// private method
// run a process on tree from a specific node down
// gets answers from user to determine path in tree
void Tree::process(DecisionTreeNode* p)
{
	// p is a leaf - print value and end function
	if (p->isLeaf)
		cout << p->value;

	// get ans from user and use recursive call to continue process on
	// son pointed by answer thats equal to user input
	else
	{
		string input;
		cout << p->value << endl;
		cin >> input;

		// find  son pointed to by the  answer 
		list<ValidAnswer*>::iterator it = p->answersList.begin();
		for (; it != p->answersList.end(); it++)
		{
			if ((*it)->ans == input)
				break;
		}
		// recursive call
		process((*it)->son);
	}
}


// returns a string with entire subtree rooted in node p in (node(ans,son)) format
string Tree::printToString(DecisionTreeNode* p)
{
	string temp;
	// add first '(' of tree to string
	if (p == root)
		temp.push_back('(');

	// add the  value to string
	temp += p->value;

	// node is leaf -  add closing parenthesis to string
	// end function
	if (p->isLeaf)
	{
		temp.push_back(')');
		return temp;
	}
	// node has son - run loop on answers
	else
		for (list<ValidAnswer*>::iterator it = p->answersList.begin(); it != p->answersList.end(); it++)
		{
			// each answer add opening parenthesis to string
			temp.push_back('(');
			// add answer to string
			temp += (*it)->ans;
			temp.push_back(',');
			// recursive call to print subtree rooted in each son
			temp += (printToString((*it)->son));
		}
	// add closing parenthesis to string
	temp.push_back(')');

	return temp;
}

// print entire tree in (node(ans,son)) format
// calls overloaded function with root as parameter
string Tree::printToString() { return printToString(root); }


// delete subtree rooted in node p which p->value is equal to val parameter
// calls deleteAllSubTree() on node found by search() 
void Tree::deleteSubTree(string val)
{
	DecisionTreeNode* parent;
	// find the  node and its parent
	DecisionTreeNode* temp = search(root, val, parent);
	// delete answer pointing to node
	if (parent)
	{
		for (list<ValidAnswer*>::iterator it = parent->answersList.begin(); it != parent->answersList.end(); it++)
		{
			// when answer found - delete the value
			// and remove the pointer from list
			if ((*it)->son == temp)
			{
				delete (*it);
				parent->answersList.erase(it);
				break;
			}
		}
	}
	// delete the tree rooted in found node
	deleteAllSubTree(temp);
	// update parent-node isLeaf status
	if (parent && parent->answersList.empty())
		parent->isLeaf = true;
}


// delete subtree rooted in node t sent as parameter
void Tree::deleteAllSubTree(DecisionTreeNode* t)
{
	// delete t if no subtree is rooted at node t
	if (t->isLeaf)
		delete t;

	// loop through node t answers first,  to delete answers and subtrees pointed by answers
	// then delete node t
	else
	{
		for (list<ValidAnswer*>::iterator it = t->answersList.begin(); it != t->answersList.end(); it++)
		{
			// delete subtree using recursive call
			deleteAllSubTree((*it)->son);
			// delete answer
			delete(*it);
		}
		// delete t itself
		delete t;
	}
}