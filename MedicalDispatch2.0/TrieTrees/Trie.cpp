#include "Trie.h"
Trie::Trie() 
{
	root = new TrieNode();
}
void Trie::addWord(string key)
{
	// check if word already exsists in tree
	if (searchWord(key))
	{
		cout << "word exists, no need to insert\n";
		return;
	}
	TrieNode* node = root;
	// create path of word in tree, if node in path is NULL, initialize th node
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 97] == NULL)
			node->children[key[i] - 97] = new TrieNode(node);
			node = node->children[key[i] - 97];
	}
	// set  of end of word node flag to true
	node->isEndOfWord = true;
}
bool Trie::deleteWord(string key)
{
	TrieNode* node = root;
	// find path of word in tree - node points to  "claimed" end of the  word node
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 97] == NULL)
			return false;
		else
			node = node->children[key[i] - 97];
	}
	// node is not an end of a word - word dosen't exsist in tree - return false
	if (node->isEndOfWord==false)
		return false;
	// node is a valid end of word- check if node has children, if positive,
	// set end of word flag of node to false and return true
	if (hasChildren(node))
	{
		node->isEndOfWord = false;
		return true;
	}
	// node does not have children - node is deleted
	// for each father in path back to root check if father has children or is a
	// end of a word -if positive stop deletion - return true.
	TrieNode* temp = node->parent;   // temp points to cuurent loop  node's father
	for (int i = key.length()-1; i >= 0; i--)
	{
		if (i != key.length() - 1)
		{
			node = temp;
			temp = temp->parent;
		}
		delete node;
		temp->children[key[i] - 97] = NULL;
		if (temp->isEndOfWord|| hasChildren(temp))
			return true;
	}
	
}
bool Trie::searchWord(string key,TrieNode* node)
{
	if (node == NULL)
		return false;
	// iterate through node's path, if any node in path is NULL
	// word does not exsist- return false
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 97] == NULL)
			return false;
		else
			node = node->children[key[i] - 97];
	}
	// end of word reached, check if current node is actually end of a word
	if (node->isEndOfWord)
		return true;
	// word does not exsist in tree
	return false;
}
int Trie::printAutoSuggestions(string key)
{
	TrieNode* node = root;
	char wordsArray[ALPHABET_SIZE * 100];
	// find node that contains last charachter of string
	// add each charachter in loop to array sent to recursive printing function, to enable prefix
	// printing for each suggestion
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 97] == NULL)
			return false;
		else
		{
			wordsArray[i] = key[i];
			node = node->children[key[i] - 97];
		}
	}
	// send found node and  array containing prefix to print.
	return printAllWordFromPrefix( node, wordsArray,key.length());
}
int  Trie::printAllWordFromPrefix(TrieNode* node, char* wordsArray, int position, int count)
{
	//  end of word reached end recursion call - print the word
	if (node->isEndOfWord)
	{
		count++;
		for (int i = 0; i < position; i++)
		{
			cout << wordsArray[i];
		}
		cout << endl;
		
	}
	// iterative recursive call to run through a given node to check all 
	// exsisting children for print
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		// node has child - recursive call to iterate through subtree rooted in current child
		if (node->children[i] != NULL)
		{
			wordsArray[position] = i + 'a';
			count += printAllWordFromPrefix(node->children[i], wordsArray, position + 1);
		}
	}
	return count;
}
bool Trie::hasChildren(TrieNode* node)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != NULL)
			return true;
	}
	return false;
}