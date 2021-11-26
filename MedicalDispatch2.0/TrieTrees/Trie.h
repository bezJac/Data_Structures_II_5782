#pragma once
#include <iostream>
#include <vector>
using namespace std;
const int ALPHABET_SIZE = 26;
class Trie
{
public:
    class TrieNode
    {
    public:
       
        TrieNode* children [ALPHABET_SIZE] ;
        TrieNode* parent;
        // isEndOfWord is true if the node
        // represents end of a word
        bool isEndOfWord;
    public:
        TrieNode() { parent = NULL; isEndOfWord = false; };
        TrieNode(TrieNode* p) { parent = p; isEndOfWord = false;}
    };
    TrieNode* root;
public:
    Trie();
    /// <summary>
/// add a new word to Trie tree
/// </summary>
/// <param name="key"> : the word to add</param>
    void addWord(string);
    /// <summary>
/// delete a word from Trie tree
/// </summary>
/// <param name="key"> : the word to delete </param>
/// <returns> true if delition was successful, othewise false</returns>
    bool deleteWord(string);
    /// <summary>
    /// check if word is in tree,
    /// public method ,
    ///  calls private method with tree root 
    /// </summary>
    /// <param name="key"> word to serch for </param>
    /// <returns> true if word was found, otherwise false</returns>
    bool searchWord(string key) { return searchWord(key, root); }
    /// <summary>
/// print Auto suggestions for word endings to charachters enterd by user,
/// from the words in the tree
/// </summary>
/// <param name="key"> string of input charachters from user </param>
/// <returns></returns>
    int printAutoSuggestions(string key);
private:
    /// <summary>
/// search for a word in a Trie tree
/// </summary>
/// <param name="key"> : word to search</param>
/// <param name="node"> : tree's root </param>
/// <returns> true if found, otherwise false</returns>
    bool searchWord(string, TrieNode*);
    /// <summary>
/// check if a given node in Trie tree has children
/// </summary>
/// <param name="node"> - node in check</param>
/// <returns> true if node has children, otherwise false</returns>
    bool hasChildren(TrieNode*);
    /// <summary>
/// print all words in Trie tree rooted in a given node
/// </summary>
/// <param name="node">  - node  serving as root to print from </param>
/// <param name="wordsArray"> -  array to copy words to </param>
/// <param name="position">  - current position in array</param>
/// <param name="count"> -  number of words printed</param>
/// <returns> number of words successfuly printed </returns>
    int printAllWordFromPrefix(TrieNode*, char* wordsArray,int position, int count =0 );

};