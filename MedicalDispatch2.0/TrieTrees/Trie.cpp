#include "Trie.h"
Trie::Trie() 
{
	root = new TrieNode();
	/*for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		root->children[i] = new TrieNode(root);
	}*/
}
void Trie::addWord(string key)
{
	if (searchWord(key))
	{
		cout << " word exists, no need to insert\n";
		return;
	}
	TrieNode* node = root;
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 97] == NULL)
			node->children[key[i] - 97] = new TrieNode(node);
			node = node->children[key[i] - 97];
	}
	node->isEndOfWord = true;
}
bool Trie::deleteWord(string key)
{
	TrieNode* node = root;
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 97] == NULL)
			return false;
		else
			node = node->children[key[i] - 97];
	}
	if (node->isEndOfWord==false)
		return false;
	if (hasChildren(node))
	{
		node->isEndOfWord = false;
		return true;
	}
	for (int i = key.length(); i > 0; i--)
	{
		node = node->parent;
		node->children[key[i] - 97] = NULL;
		if (hasChildren(node))
			return true;
	}
	
}
bool Trie::searchWord(string key,TrieNode* node)
{
	if (node == NULL)
		return false;
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 97] == NULL)
			return false;
		else
			node = node->children[key[i] - 97];
	}
	if (node->isEndOfWord)
		return true;
	return false;
}
int Trie::printAutoSuggestions(string key)
{
	TrieNode* node = root;
	string pointer;
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 97] == NULL)
			return false;
		else
		{
			pointer += key[i];
			node = node->children[key[i] - 97];
		}
	}
	char wordsArray[ALPHABET_SIZE*100];
	for (int i = 0; i < pointer.length(); i++)
	{
		wordsArray[i] = pointer[i];
	}
	return printAllWordFromPrefix( node, wordsArray,pointer.length());
}
int  Trie::printAllWordFromPrefix(TrieNode* node, char* wordsArray, int position, int count)
{
	if (node->isEndOfWord)
	{
		count++;
		for (int i = 0; i < position; i++)
		{
			cout << wordsArray[i];
		}
		cout << endl;
		
	}
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
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