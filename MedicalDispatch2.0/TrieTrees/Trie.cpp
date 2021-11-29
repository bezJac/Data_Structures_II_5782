#include "Trie.h"
Trie::Trie() 
{
	root = new TrieNode();
}
Trie::~Trie()
{
	// call clear an on root to delete all tree
	clear(root);
}
void Trie::clear(TrieNode* node)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		// each exsisting child of node call function on its subtree
		if (node->children[i]!=NULL && hasChildren(node->children[i]))
			clear(node->children[i]);
		else
			delete node->children[i];
	}
	// delete current node
	delete node;
}
void Trie::addWord(string key)
{
	// check if word already exsists
	if (searchWord(key))
	{
		cout << "word exists, no need to insert\n";
		return;
	}
	TrieNode* node = root;
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 'a'] == NULL)
			node->children[key[i] - 'a'] = new TrieNode(node);
			node = node->children[key[i] - 97];
	}
	node->isEndOfWord = true;
}
bool Trie::deleteWord(string key)
{
	TrieNode* node = root;
	// find "claimed" end of word node
	for (int i = 0; i < key.length(); i++)
	{
		if (node->children[key[i] - 'a'] == NULL)
			return false;
		else
			node = node->children[key[i] - 97];
	}
	// node isn't end of word, word dosen't exsist
	if (node->isEndOfWord==false)
		return false;
	// node has childrren - remove end of word flag and return
	if (hasChildren(node))
	{
		node->isEndOfWord = false;
		return true;
	}
	// node does not have children - return through parent path to root
	// delete all nodes in path, until a parent node in path either has children or is
	// a end of a word - then stop deleteing
	TrieNode* temp = node->parent;
	for (int i = key.length()-1; i >= 0; i--)
	{
		if (i != key.length() - 1)
		{
			node = temp;
			temp = temp->parent;
		}
		delete node;
		temp->children[key[i] - 'a'] = NULL;
		if (temp->isEndOfWord|| hasChildren(temp))
			return true;
	}
	
}
bool Trie::searchWord(string key,TrieNode* node)
{
	// tree is empty - return false
	if (node == NULL)
		return false;
	// serach path of word in tree
	for (int i = 0; i < key.length(); i++)
	{
		// node in expected path is null - return false
		if (node->children[key[i] - 'a'] == NULL)
			return false;
		else
			node = node->children[key[i] - 'a'];
	}
	// "claimed" end of word node is actually the end of the word, return true
	if (node->isEndOfWord)
		return true;
	// word dosen't exsist return false
	return false;
}
int Trie::printAutoSuggestions(string key)
{
	TrieNode* node = root;
	char wordsArray[ALPHABET_SIZE * 100];
	// find path of prefix in tree , add each letter in prefix to array
	for (int i = 0; i < key.length(); i++)
	{
		// node in path is null - prefix dosen't exsist in tree
		if (node->children[key[i] - 'a'] == NULL)
			return false;
		else
		{
			wordsArray[i] = key[i];
			node = node->children[key[i] - 'a'];
		}
	}
	// print all subtree's rooted in end of prefix
	return printAllWordFromPrefix( node, wordsArray,key.length());
}
int  Trie::printAllWordFromPrefix(TrieNode* node, char* wordsArray, int position, int count)
{
	// end of word reached - print word, advance word count by one
	if (node->isEndOfWord)
	{
		count++;
		for (int i = 0; i < position; i++)
		{
			cout << wordsArray[i];
		}
		cout << endl;
		
	}
	// iterate through all prefix's children, print all the subtrees
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != NULL)
		{
			// add current node value to array for print
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