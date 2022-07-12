#include "HuffmanTree.h"
#include"HuffmanNode.h"
#include <string>

HuffmanTree::~HuffmanTree()
{
	clearTree(root);
}

void HuffmanTree::buildTree(string str)
{
	// create prority queue from string
	buildPriorityQueue(str);
	// create tree from queue
	for (int i = 0; i < charCount - 1; i++)
	{
		HuffmanNode* temp1 = pQueue.top();
		pQueue.pop();
		HuffmanNode* newNode = new HuffmanNode(temp1, pQueue.top());
		pQueue.pop();
		pQueue.push(newNode);
	}
	root = pQueue.top();

}
// check if a tree structure matches a given tree
// gets structure and proposed number of characters as parameters
// returns true if number of 1 bits in code matches parameter
bool  HuffmanTree::checkIfLegalTree(string str, int num)
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

// bouild a priority queue based on frequency of characters in a string
void HuffmanTree::buildPriorityQueue(string str)
{
	charCount = 0;
	// check all 256 ASCII characters
	for (int temp = 1; temp <= 255; temp++)
	{
		char ch = (char)temp;
		// count frequency of character in string
		int frequency = countFrequency(str, temp);
		// character exsist in string - create new node in queue
		if (frequency > 0)
		{
			charCount++;
			string val(1, ch);
			pQueue.push(new HuffmanNode(frequency, val));
		}
	}
}

// prinnt order of characters in frequncy in tree
// recursive inorder scan of tree used
void HuffmanTree::printOrderOfTree(HuffmanNode* root)
{
	if (root == NULL)
		return;
	printOrderOfTree(root->left);
	if (root->str != "")
		cout << root->str;
	printOrderOfTree(root->right);

}

// count frequency of a given character in a string
int HuffmanTree::countFrequency(string str, char ch)
{
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ch)
			++count;
	}
	return count;
}


// clear a tree- called by destructor- to avoid access to root
void HuffmanTree::clearTree(HuffmanNode* root)
{
	// node is a leaf  - delet the leaf - end recursive call
	if (root->left == NULL && root->right == NULL)
	{
		delete root;
		return;
	}
	// clear left subtree
	clearTree(root->left);
	// clear right subtree
	clearTree(root->right);
	delete root;
}

// print the huffmsn code for a given character
void HuffmanTree::printCodes(HuffmanNode* root, string code, char ch)
{
	// tree is empty
	if (root == NULL)
		return;
	// tree only has a root
	if (charCount == 1)
	{
		cout << "1";
		return;
	}
	// leaf matching char is reached - print path taken to node
	if (root->str[0] == ch)
		cout << code;
	// add 0 to string on left turn in path
	printCodes(root->left, code + "0", ch);
	// add 1 to string on right turn in path
	printCodes(root->right, code + "1", ch);
}

// print structure of tree
void HuffmanTree::PrintTreeStructure(HuffmanNode* root)
{
	// node is leaf - print 1
	if (root->left == NULL && root->right == NULL)
	{
		cout << 1;
		return;
	}
	// node is not a leaf print 0 to resembel both left and right son and 
	// call function recursivlley on each son
	if (root->left != NULL)
	{
		cout << 0;
		PrintTreeStructure(root->left);
	}
	if (root->right != NULL)
		PrintTreeStructure(root->right);


}

// decode a huffman code back to its original charachter
//  returns number of bits used in code to encode given character
int HuffmanTree::decodeToText(string code, HuffmanNode* t, string* result)
{
	int size = 0;
	for (int i = 0; i <= code.length(); i++)
	{
		// leaf is reached - add leaf value to string and return 
		// count of bits
		if (t->left == NULL && t->right == NULL)
		{
			*(result) += t->str;
			if (charCount == 1)
				return 1;
			return size;
		}
		// turn left on 0
		if (code[i] == '0')
		{
			t = t->left;
			size++;
		}
		// turn right on 1
		if (code[i] == '1')
		{
			t = t->right;
			size++;
		}
	}
}

string HuffmanTree::decodeToText(string code)
{
	int count = 0;
	string str = code;
	string result;
	// private method returns number of bits in the code we advanced on previous iterration
	// we subtract from the code the number of bits advanced and send back to print next character
	// count initialized to 0 befor loop , so on first iteration the full code is sent.
	for (int i = 0; i < code.size(); i += count)
	{
		str = str.substr(count);
		count = decodeToText(str, root, &result);
	}
	return result;
}

// create a huffman tree from a given tree structue and order of letters in tree
string HuffmanTree::createTreeFromStructure(string structure, string* const& letters, HuffmanNode* root)
{
	// structure code current value not a leaf
	// create node with two sons, call recursive call for each son- subtracting code used to create 
	// the actuall son, code sent by reference so right son gets code after left son subtracted
	// all bits used to create his subtree
	if (structure[0] == '0')
	{
		root->left = new HuffmanNode(0);
		root->right = new HuffmanNode(0);
		structure = createTreeFromStructure(structure.substr(1), letters, root->left);
		structure = createTreeFromStructure(structure.substr(1), letters, root->right);
	}
	// leaf reached - add to leaf value of first character from letters string - then remove value 
	// from string
	else if (structure[0] == '1')
	{
		root->str = letters->at(0);
		*letters = letters->substr(1);
	}
	// return structure of tree
	return structure;
}



