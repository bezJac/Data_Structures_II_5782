#include "HuffmanTree.h"
#include"HuffmanNode.h"
#include <string>

void HuffmanTree::buildTree(string str)
{
	buildPriorityQueue(str);
	for (int i = 0; i < charCount-1; i++)
	{
		HuffmanNode* temp1 = pQueue.top();
		pQueue.pop();
		HuffmanNode* newNode = new HuffmanNode(temp1, pQueue.top());
		pQueue.pop();
		pQueue.push(newNode);
	}
	root= pQueue.top();

}

void HuffmanTree::buildPriorityQueue(string str)
{
	for ( string temp = "a"; temp[0] <= 'z'; temp[0]++)
	{
		int frequency = count(str.begin(), str.end(), temp[0]);
		if (frequency > 0)
		{
			charCount++;
			pQueue.push(new HuffmanNode(frequency,temp));
		}
	}
}

void HuffmanTree::printOrderOfTree(HuffmanNode* root)
{
	

		if (root == NULL)
			return;
		printOrderOfTree(root->left);
		if (root->str != "")
			cout << root->str;
		printOrderOfTree(root->right);
	
}

void HuffmanTree::printCodes(HuffmanNode* root, string code, char ch)
{
	if (root == NULL)
		return;
	if (root->str[0] == ch)
		cout << code;
	printCodes(root->left, code + "0",ch);
	printCodes(root->right, code + "1",ch);
}

void HuffmanTree::PrintTreeStructure(HuffmanNode* root)
{
	
		if (root->left == NULL && root->right == NULL)
		{
			cout << 1;
			return;
		}
		if (root->left != NULL)
		{
			cout << 0;
			PrintTreeStructure(root->left);
		}
		if (root->right != NULL)
			PrintTreeStructure(root->right);

	
}

