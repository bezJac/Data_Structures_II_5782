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

void HuffmanTree::printCodes(HuffmanNode* root, string str)
{
	if (root == NULL)
		return;
	if (root->str != "")
		cout << root->str << ':' << str<<endl;
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
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
