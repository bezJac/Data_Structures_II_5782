#include "Trie.h"
void Trie::addWord(string key)
{
	if(searchWord(key))
		cout << " word exists, no need to insert\n";
			return;
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
int Trie::printAllWordFromPrefix(string key)
{
	
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